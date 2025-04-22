
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 定义二叉树节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 线段树节点
struct SegmentTreeNode {
    int depth;  // 节点深度
    TreeNode* node; // 对应的树节点
    SegmentTreeNode() : depth(INT_MAX), node(nullptr) {}
};

// 线段树类
class SegmentTree {
private:
    vector<SegmentTreeNode> tree;
    int n;

    // 合并两个线段树节点
    SegmentTreeNode merge(const SegmentTreeNode& a, const SegmentTreeNode& b) {
        if (a.depth < b.depth) return a;
        return b;
    }

    // 构建线段树
    void build(int idx, int l, int r, const vector<SegmentTreeNode>& data) {
        if (l == r) {
            tree[idx] = data[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * idx + 1, l, mid, data);
        build(2 * idx + 2, mid + 1, r, data);
        tree[idx] = merge(tree[2 * idx + 1], tree[2 * idx + 2]);
    }

    // 查询区间最小值
    SegmentTreeNode query(int idx, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return {INT_MAX, nullptr};
        if (ql <= l && qr >= r) return tree[idx];
        int mid = (l + r) / 2;
        SegmentTreeNode left = query(2 * idx + 1, l, mid, ql, qr);
        SegmentTreeNode right = query(2 * idx + 2, mid + 1, r, ql, qr);
        return merge(left, right);
    }

public:
    SegmentTree(const vector<SegmentTreeNode>& data) {
        n = data.size();
        tree.resize(4 * n);
        build(0, 0, n - 1, data);
    }

    // 查询区间最小值
    SegmentTreeNode query(int ql, int qr) {
        return query(0, 0, n - 1, ql, qr);
    }
};

// DFS 遍历，生成 DFS 序和深度信息
void dfs(TreeNode* root, int depth, vector<SegmentTreeNode>& euler, vector<int>& in, vector<int>& out, int& index) {
    if (!root) return;

    // 记录进入时间
    in[root->val] = index;
    euler[index] = {depth, root};
    index++;

    // 递归遍历左子树
    if (root->left) {
        dfs(root->left, depth + 1, euler, in, out, index);
        euler[index] = {depth, root};
        index++;
    }

    // 递归遍历右子树
    if (root->right) {
        dfs(root->right, depth + 1, euler, in, out, index);
        euler[index] = {depth, root};
        index++;
    }

    // 记录离开时间
    out[root->val] = index;
}

// 查找 LCA
TreeNode* findLCA(TreeNode* root, TreeNode* u, TreeNode* v, SegmentTree& st, const vector<int>& in, const vector<int>& out) {
    int l = in[u->val];
    int r = in[v->val];
    if (l > r) swap(l, r);
    SegmentTreeNode res = st.query(l, r);
    return res.node;
}

// 主函数
int main() {
    // 构建示例二叉树
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    // 初始化 DFS 序和深度信息
    vector<SegmentTreeNode> euler(100); // 欧拉序
    vector<int> in(100, -1); // 进入时间
    vector<int> out(100, -1); // 离开时间
    int index = 0;
    dfs(root, 0, euler, in, out, index);

    // 构建线段树
    SegmentTree st(euler);

    // 查询 LCA(5, 4)
    TreeNode* lca = findLCA(root, root->left, root->left->right->right, st, in, out);
    cout << "LCA of 5 and 4 is: " << lca->val << endl;

    return 0;
}