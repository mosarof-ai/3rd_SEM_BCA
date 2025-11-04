#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int data;
    vector<TreeNode*> children;
    TreeNode(int val) : data(val) {}
};

struct BinaryTreeNode {
    int data;
    BinaryTreeNode* left;   // first child
    BinaryTreeNode* right;  // next sibling
    BinaryTreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

BinaryTreeNode* convertToBinaryTree(TreeNode* root) {
    if (!root) return nullptr;
    BinaryTreeNode* b = new BinaryTreeNode(root->data);
    if (!root->children.empty()) {
        b->left = convertToBinaryTree(root->children[0]);
        BinaryTreeNode* cur = b->left;
        for (size_t i = 1; i < root->children.size(); ++i) {
            cur->right = convertToBinaryTree(root->children[i]);
            cur = cur->right;
        }
    }
    return b;
}

void preorder(BinaryTreeNode* node, vector<int>& out) {
    if (!node) return;
    out.push_back(node->data);
    preorder(node->left, out);
    preorder(node->right, out);
}

void inorder(BinaryTreeNode* node, vector<int>& out) {
    if (!node) return;
    inorder(node->left, out);
    out.push_back(node->data);
    inorder(node->right, out);
}

int main() {
    int N;
    if (!(cin >> N) || N <= 0) {
        cerr << "Invalid number of nodes\n";
        return 1;
    }

    vector<int> values(N);
    for (int i = 0; i < N; ++i) cin >> values[i];

    vector<int> parent(N);
    for (int i = 0; i < N; ++i) cin >> parent[i];

    vector<TreeNode*> nodes;
    nodes.reserve(N);
    for (int i = 0; i < N; ++i) nodes.push_back(new TreeNode(values[i]));

    int rootIndex = -1;
    for (int i = 0; i < N; ++i) {
        if (parent[i] == -1) {
            if (rootIndex == -1) rootIndex = i;
        } else {
            if (parent[i] < 0 || parent[i] >= N) {
                cerr << "Invalid parent index for node " << i << "\n";
                return 1;
            }
            nodes[parent[i]]->children.push_back(nodes[i]);
        }
    }

    if (rootIndex == -1) {
        cerr << "No root specified (no -1 in parent list)\n";
        return 1;
    }

    TreeNode* root = nodes[rootIndex];
    BinaryTreeNode* broot = convertToBinaryTree(root);

    vector<int> pre, in;
    preorder(broot, pre);
    inorder(broot, in);

    cout << "Preorder: ";
    for (size_t i = 0; i < pre.size(); ++i) {
        if (i) cout << " ";
        cout << pre[i];
    }
    cout << "\nInorder: ";
    for (size_t i = 0; i < in.size(); ++i) {
        if (i) cout << " ";
        cout << in[i];
    }
    cout << "\n";
    return 0;
}
