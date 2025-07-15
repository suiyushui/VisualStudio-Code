
#include<unordered_map>
#include<list>
#include<utility>
#include<iostream>
#include<mutex>

using namespace std;

class LRUCache {
private:
    int capacity;
    // 双向链表，用于存储缓存
    list<pair<int, int>> cacheList;
    // 哈希表，用于快速查找元素
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap;
    // 互斥锁，用于保护共享资源
    mutable mutex mtx;

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        lock_guard<mutex> lock(mtx); // 锁定互斥锁，自动解锁
        auto it = cacheMap.find(key);
        if (it == cacheMap.end()) {
            return -1;
        }
        // 将找到的元素移动到链表的开头
        cacheList.splice(cacheList.begin(), cacheList, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        lock_guard<mutex> lock(mtx); // 锁定互斥锁，自动解锁
        auto it = cacheMap.find(key);
        if (it != cacheMap.end()) {
            // key存在，更新value
            it->second->second = value;
            cacheList.splice(cacheList.begin(), cacheList, it->second);
            return;
        }
        if (cacheList.size() == capacity) {
            // 缓存满了，删除最后一个
            int lastKey = cacheList.back().first;
            cacheMap.erase(lastKey);
            cacheList.pop_back();
        }
        cacheList.emplace_front(key, value);
        cacheMap[key] = cacheList.begin();
    }

    void print() const {
        lock_guard<mutex> lock(mtx); // 锁定互斥锁，自动解锁
        for (auto [k, v] : cacheList) {
            cout << k << " " << v << endl;
        }
    }
};

int main() {
    LRUCache cache(3);

    cache.put(1, 1);
    cache.put(2, 2);
    cache.put(3, 3);
    cout << cache.get(2) << endl; // 输出 2
    cache.put(4, 4);
    cout << cache.get(3) << endl; // 输出 -1，因为3被移除了

    cache.print();

    return 0;
}
