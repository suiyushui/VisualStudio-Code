#include <iostream>
#include <thread>
#include <vector>

int count = 0;

void add(int id) {
    for(int i = 0; i < 10000; i++){
        count++;
    }
    std::cout << "Thread " << id << " finished.\n";
}

int main() {
    std::vector<std::thread> threads;
    for(int i = 0; i < 10; i++){
        threads.emplace_back(std::thread(add, i));
    }
    for(auto& t : threads){
        t.join(); // 等待线程结束
    }
    std::cout << "Final count: " << count << "\n";
    return 0;
}
