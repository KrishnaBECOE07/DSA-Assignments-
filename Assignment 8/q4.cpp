#include <iostream>
using namespace std;
struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->key) root->left = insert(root->left, key);
    else if (key > root->key) root->right = insert(root->right, key);
    return root;
}
bool isBSTUtil(Node* root, Node*& prev) {
    if (!root) return true;
    if (!isBSTUtil(root->left, prev)) return false;
    if (prev != nullptr && root->key <= prev->key)
        return false;
    prev = root;
    return isBSTUtil(root->right, prev);
}
bool isBST(Node* root) {
    Node* prev = nullptr;
    return isBSTUtil(root, prev);
}
int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    if (isBST(root))
        cout << "The tree is a BST.\n";
    else
        cout << "The tree is NOT a BST.\n";

    return 0;
}
