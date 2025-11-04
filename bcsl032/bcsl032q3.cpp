#include <iostream>
#include <vector>
using namespace std;

// Input format (simple):
// Line 1: N (number of nodes)
// Line 2: N integers (node values)
// Line 3: N integers (parent indices, 0-based; use -1 for root)
//
// Example for the original tree:
// 7
// 1 2 3 4 5 6 7
// -1 0 0 0 1 1 3

// Structure for a general tree node
struct TreeNode {
    int data;
    vector<TreeNode*> children;
    TreeNode(int val) : data(val) {}
};

// Structure for a binary tree node (LCRS representation)
struct BinaryTreeNode {
    int data;
    BinaryTreeNode* left;  // First child
    BinaryTreeNode* right; // Next sibling
    BinaryTreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to convert general tree to binary tree
BinaryTreeNode* convertToBinaryTree(TreeNode* root) {
    if (!root)
        return nullptr;
    BinaryTreeNode* binaryRoot = new BinaryTreeNode(root->data);
    if (!root->children.empty()) {
        // Convert first child and assign to left
        binaryRoot->left = convertToBinaryTree(root->children[0]);
        // Convert remaining children and link them as right siblings
        BinaryTreeNode* current = binaryRoot->left;
        for (size_t i = 1; i < root->children.size(); ++i) {
            current->right = convertToBinaryTree(root->children[i]);
            current = current->right;
        }
    }
    return binaryRoot;
}

// Helper function to print binary tree (preorder)
void printBinaryTree(BinaryTreeNode* root) {
    if (!root)
        return;
    cout << root->data << " ";
    printBinaryTree(root->left);
    printBinaryTree(root->right);
}

// Cleanup helpers
void deleteGeneralTree(TreeNode* root) {
    if (!root) return;
    for (TreeNode* c : root->children)
        deleteGeneralTree(c);
    delete root;
}
void deleteBinaryTree(BinaryTreeNode* root) {
    if (!root) return;
    deleteBinaryTree(root->left);
    deleteBinaryTree(root->right);
    delete root;
}

int main() {
    int N;
    cout << "Enter number of nodes (N): ";
    if (!(cin >> N) || N <= 0) {
        cerr << "Invalid number of nodes\n";
        return 1;
    }

    vector<int> values(N);
    cout << "Enter " << N << " node values (space or newline separated): ";
    for (int i = 0; i < N; ++i) {
        if (!(cin >> values[i])) {
            cerr << "Failed to read node value " << i << "\n";
            return 1;
        }
    }

    vector<int> parent(N);
    cout << "Enter " << N << " parent indices (0-based, use -1 for root), space or newline separated:\n";
    for (int i = 0; i < N; ++i) {
        if (!(cin >> parent[i])) {
            cerr << "Failed to read parent index for node " << i << "\n";
            return 1;
        }
    }

    vector<TreeNode*> nodes;
    nodes.reserve(N);
    for (int i = 0; i < N; ++i)
        nodes.push_back(new TreeNode(values[i]));

    int rootIndex = -1;
    for (int i = 0; i < N; ++i) {
        if (parent[i] == -1) {
            rootIndex = i;
        }
    }
    
    // Build tree relationships and validate
    cout << "Building tree relationships:\n";
    for (int i = 0; i < N; ++i) {
        cout << "Node " << i << " (value=" << values[i] << ") parent=" << parent[i] << "\n";
        if (parent[i] != -1) {
            if (parent[i] < 0 || parent[i] >= N) {
                cerr << "Invalid parent index for node " << i << "\n";
                for (TreeNode* t : nodes) delete t;
                return 1;
            }
            nodes[parent[i]]->children.push_back(nodes[i]);
            cout << "Added node " << i << " as child of node " << parent[i] << "\n";
        }
    }
    if (rootIndex == -1) {
        cerr << "No root found\n";
        for (TreeNode* t : nodes) delete t;
        return 1;
    }

    TreeNode* root = nodes[rootIndex];
    BinaryTreeNode* binaryRoot = convertToBinaryTree(root);

    cout << "Preorder traversal of converted binary tree (LCRS representation): ";
    printBinaryTree(binaryRoot);
    cout << endl;

    // Cleanup
    deleteBinaryTree(binaryRoot);
    // Note: nodes are owned by general tree; delete the general tree root will free them all
    deleteGeneralTree(root);

    return 0;
}