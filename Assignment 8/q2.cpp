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
    // if equal, ignore (no duplicates)
    return root;
}
Node* searchRecursive(Node* root, int key) {
    if (!root) return nullptr;
    if (root->key == key) return root;
    if (key < root->key) return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}
Node* searchIterative(Node* root, int key) {
    Node* cur = root;
    while (cur) {
        if (cur->key == key) return cur;
        if (key < cur->key) cur = cur->left;
        else cur = cur->right;
    }
    return nullptr;
}
Node* findMin(Node* root) {
    if (!root) return nullptr;
    Node* cur = root;
    while (cur->left) cur = cur->left;
    return cur;
}
Node* findMax(Node* root) {
    if (!root) return nullptr;
    Node* cur = root;
    while (cur->right) cur = cur->right;
    return cur;
}
Node* inorderSuccessor(Node* root, int key) {
    Node* target = searchIterative(root, key);
    if (!target) return nullptr;

    // case 1: if right subtree exists -> successor is min of right subtree
    if (target->right) return findMin(target->right);

    // case 2: no right subtree -> successor is the lowest ancestor for which target is in left subtree
    Node* succ = nullptr;
    Node* cur = root;
    while (cur) {
        if (key < cur->key) {
            succ = cur;
            cur = cur->left;
        } else if (key > cur->key) {
            cur = cur->right;
        } else break; // found node
    }
    return succ;
}
Node* inorderPredecessor(Node* root, int key) {
    Node* target = searchIterative(root, key);
    if (!target) return nullptr;
    if (target->left) return findMax(target->left);
    Node* pred = nullptr;
    Node* cur = root;
    while (cur) {
        if (key > cur->key) {
            pred = cur;
            cur = cur->right;
        } else if (key < cur->key) {
            cur = cur->left;
        } else break; 
    }
    return pred;
}
void inorderPrint(Node* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->key << " ";
    inorderPrint(root->right);
}

int main() {
    Node* root = nullptr;
    // build a sample BST
    int vals[] = {50, 30, 70, 20, 40, 60, 80};
    for (int v : vals) root = insert(root, v);

    cout << "In-order traversal: ";
    inorderPrint(root);
    cout << "\n";
    int k = 40;
    cout << "Search recursive for " << k << ": "
         << (searchRecursive(root, k) ? "Found" : "Not found") << "\n";
    cout << "Search iterative for " << 25 << ": "
         << (searchIterative(root, 25) ? "Found" : "Not found") << "\n";
    Node* mn = findMin(root);
    Node* mx = findMax(root);
    if (mn) cout << "Minimum element: " << mn->key << "\n";
    if (mx) cout << "Maximum element: " << mx->key << "\n";
    int q = 50;
    Node* succ = inorderSuccessor(root, q);
    Node* pred = inorderPredecessor(root, q);
    if (succ) cout << "In-order successor of " << q << " is " << succ->key << "\n";
    else cout << "In-order successor of " << q << " does not exist\n";
    if (pred) cout << "In-order predecessor of " << q << " is " << pred->key << "\n";
    else cout << "In-order predecessor of " << q << " does not exist\n";

    return 0;
}
