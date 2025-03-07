#include <iostream>
#include <vector>
using namespace std;

// 定义最大节点数，通常需要是问题规模的四倍以适应线段树的结构
const int Manx = 100005;
// 定义线段树数组，用于存储每个节点的值
int segTree[4 * Manx];
// 定义懒惰传播数组，用于存储延迟更新的信息
int lazy[4 * Manx];
// 定义数组的大小和查询的数量
int n, q;

// 构建线段树的函数
// node 是当前节点的索引，start 和 end 是当前节点所代表的区间
void build(int node, int start, int end) {
    // 如果 start 等于 end，说明这个节点是叶子节点，存储的是单个元素的值
    if (start == end) {
        segTree[node] = 0; // 初始化为0，根据具体问题可以改为其他值
    } else {
        // 否则，计算中间位置，将区间分为两部分
        int mid = (start + end) / 2;
        // 递归构建左子树
        build(2 * node, start, mid);
        // 递归构建右子树
        build(2 * node + 1, mid + 1, end);
        // 当前节点存储的是其左右子节点的最小值
        segTree[node] = min(segTree[2 * node], segTree[2 * node + 1]);
    }
}

// 懒惰传播函数，用于将延迟更新的信息传播到子节点
// node 是当前节点的索引，start 和 end 是当前节点所代表的区间
void propagate(int node, int start, int end) {
    // 如果当前节点有延迟更新的信息
    if (lazy[node] != 0) {
        // 将延迟更新的信息应用到当前节点
        segTree[node] = lazy[node];
        // 如果当前节点不是叶子节点，将延迟更新的信息传递给子节点
        if (start != end) {
            lazy[2 * node] = lazy[node]; // 左子节点
            lazy[2 * node + 1] = lazy[node]; // 右子节点
        }
        // 清除当前节点的延迟更新信息
        lazy[node] = 0;
    }
}

// 区间更新函数
// node 是当前节点的索引，start 和 end 是当前节点所代表的区间
// l 和 r 是需要更新的区间，val 是要更新的值
void updateRange(int node, int start, int end, int l, int r, int& val) {
    // 传播延迟更新的信息
    propagate(node, start, end);
    // 如果当前节点的区间和需要更新的区间不重合，直接返回
    if (start > end || start > r || end < l) return;
    // 如果当前节点的区间完全包含在需要更新的区间内
    if (start >= l && end <= r) {
        // 设置延迟更新信息
        lazy[node] = val++;
        //  传播延迟更新的信息
        propagate(node, start, end);
        return;
    }
    // 否则，计算中间位置，将区间分为两部分
    int mid = (start + end) / 2;
    // 递归更新左子树
    updateRange(2 * node, start, mid, l, r, val);
    // 递归更新右子树
    updateRange(2 * node + 1, mid + 1, end, l, r, val);
    // 更新当前节点的值为左右子节点的最小值
    segTree[node] = min(segTree[2 * node], segTree[2 * node + 1]);
}

// 单点查询函数
// node 是当前节点的索引，start 和 end 是当前节点所代表的区间
// index 是需要查询的单点位置
int query(int node, int start, int end, int index) {
    // 传播延迟更新的信息
    propagate(node, start, end);
    // 如果 start 等于 end，说明这个节点是叶子节点，返回这个节点的值
    if (start == end) {
        return segTree[node];
    }
    // 否则，计算中间位置，将区间分为两部分
    int mid = (start + end) / 2;
    // 如果查询的索引在左子树的区间内，递归查询左子树
    if (index <= mid) {
        return query(2 * node, start, mid, index);
    } else {
        // 否则，递归查询右子树
        return query(2 * node + 1, mid + 1, end, index);
    }
}

int main() {
    // 输入数组的大小和查询的数量
    cin >> n >> q;
    // 构建线段树，从根节点开始，区间为 [1, n]
    build(1, 1, n);
    // 定义更新的值，每次更新时都会加1
    int t = 1;
    // 定义操作类型、区间更新的左右边界、查询的索引
    int op, l, r, x;
    // 循环处理每个查询
    while (q--) {
        // 输入操作类型
        cin >> op;
        // 如果操作类型为1，进行区间更新
        if (op == 1) {
            // 输入需要更新的区间的左右边界
            cin >> l >> r;
            // 调用区间更新函数，更新区间 [l, r]，更新的值为 t，并在每次更新后 t 加1
            updateRange(1, 1, n, l, r, t);
        } else {
            // 如果操作类型为其他值（在这个例子中为2），进行单点查询
            // 输入需要查询的单点位置
            cin >> x;
            // 调用单点查询函数，查询位置 x 的值
            cout << query(1, 1, n, x) << endl;
        }
    }
    return 0;
}
