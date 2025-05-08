#include <iostream>

// 定义 AVL 树节点结构
class TreeNode {
public:
    int key;
    TreeNode* left;
    TreeNode* right;
    int height;

    TreeNode(int value) : key(value), left(nullptr), right(nullptr), height(1) {}
};

// 定义 AVL 树类
class AVLTree {
private:
    // 获取节点的高度
    int height(TreeNode* node) {
        return node ? node->height : 0;
    }

    // 获取平衡因子
    int getBalance(TreeNode* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    // 右旋操作
    TreeNode* rightRotate(TreeNode* y) {
        TreeNode* x = y->left;
        TreeNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = std::max(height(y->left), height(y->right)) + 1;
        x->height = std::max(height(x->left), height(x->right)) + 1;

        return x;
    }

    // 左旋操作
    TreeNode* leftRotate(TreeNode* x) {
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = std::max(height(x->left), height(x->right)) + 1;
        y->height = std::max(height(y->left), height(y->right)) + 1;

        return y;
    }

    // 插入节点
    TreeNode* insert(TreeNode* node, int key) {
        if (!node)
            return new TreeNode(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node;

        node->height = 1 + std::max(height(node->left), height(node->right));

        int balance = getBalance(node);

        // 左左情况
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        // 右右情况
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        // 左右情况
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // 右左情况
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // 前序遍历
    void preOrder(TreeNode* node) {
        if (node) {
            std::cout << node->key << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

public:
    TreeNode* root;

    AVLTree() : root(nullptr) {}

    void insert(int key) {
        root = insert(root, key);
    }

    void preOrder() {
        preOrder(root);
    }
};

int main() {
    AVLTree tree;

    int nums[] = {9, 5, 10, 0, 6, 11, -1, 1, 2};
    int n = sizeof(nums) / sizeof(nums[0]);

    for (int i = 0; i < n; i++) {
        tree.insert(nums[i]);
    }

    std::cout << "Preorder traversal of the constructed AVL tree is: ";
    tree.preOrder();
    std::cout << std::endl;

    return 0;
}    