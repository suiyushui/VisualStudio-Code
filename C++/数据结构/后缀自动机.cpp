// 后缀自动机，用于字符串匹配等操作
// 时间复杂度O(n)，空间复杂度O(n)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 定义状态结构体
struct State {
    int len;            // 当前状态对应的最长子串长度
    int link;           // 后缀链接，指向另一个状态
    vector<int> next;   // 转移表，存储当前状态通过某个字符转移到的状态

    // 构造函数，初始化状态长度为len，默认为0；后缀链接为link，默认为-1；转移表大小为128，默认所有值为-1
    State(int len = 0, int link = -1) : len(len), link(link), next(128, -1) {} 
};

// 后缀自动机类
class SuffixAutomaton {
public:
    vector<State> st; // 存储所有状态
    int last;         // 最后一个状态的索引

    // 构造函数，初始化自动机，创建初始状态
    SuffixAutomaton() {
        st.emplace_back(0, -1); // 初始状态，长度为0，无后缀链接
        last = 0;
    }

    // 扩展后缀自动机，添加一个新的字符
    void extend(char c) {
        int cur = st.size(); // 当前状态索引为当前状态数量
        st.emplace_back(st[last].len + 1); // 创建新状态，长度为最后一个状态长度加1
        int p = last; // 从最后一个状态开始
        while (p != -1 && st[p].next[c] == -1) { // 如果当前状态没有通过字符c转移到的状态
            st[p].next[c] = cur; // 创建转移
            p = st[p].link; // 移动到后缀链接指向的状态
        }
        if (p == -1) {
            // 如果状态p不存在，说明当前状态的后缀链接指向初始状态
            st[cur].link = 0;
        } else {
            int q = st[p].next[c]; // 状态p通过字符c转移到的状态索引
            if (st[p].len + 1 == st[q].len) {
                // 如果状态p的长度加1等于状态q的长度，说明q就是cur的后缀链接
                st[cur].link = q;
            } else {
                // 否则，需要克隆状态q
                int clone = st.size(); // 克隆状态索引为当前状态数量
                st.push_back(st[q]); // 克隆状态q
                st[clone].len = st[p].len + 1; // 克隆状态的长度为状态p的长度加1
                // 调整所有通过字符c转移到状态q的状态的后缀链接，使其指向克隆状态
                while (p != -1 && st[p].next[c] == q) {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }
                // 调整状态q和cur的后缀链接，使其指向克隆状态
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur; // 更新最后一个状态为当前状态
    }
};

int main() {
    string s = "banana"; // 测试字符串
    SuffixAutomaton sam; // 创建后缀自动机实例
    for (char c : s) { // 遍历字符串中的每个字符
        sam.extend(c); // 扩展自动机
    }
    cout << "后缀自动机中的状态数量: " << sam.st.size() << endl; // 输出自动机中的状态数量
    for (int i = 0; i < sam.st.size(); i++) { // 遍历每个状态
        cout << "状态" << i << "的转移表为: ";
        for (int j = 0; j < 128; j++) { // 遍历转移表中的每个字符
            if (sam.st[i].next[j] != -1) { // 如果字符j有转移
                cout << (char)j << " -> " << sam.st[i].next[j] << " "; // 输出字符j及其转移状态
            }
        }
        cout << endl;
    } 
    return 0;
}
