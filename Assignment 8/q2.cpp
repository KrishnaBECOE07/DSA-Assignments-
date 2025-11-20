#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data; Node* left; Node* right;
    Node(int v): data(v), left(nullptr), right(nullptr) {}
}

;

Node* bst_insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data) root->left = bst_insert(root->left, key);
    else if (key > root->data) root->right = bst_insert(root->right, key);
    // duplicates ignored
    return root;
}

// recursive search
Node* search_rec(Node* root, int key) {
    if (!root) return nullptr;
    if (root->data == key) return root;
    return key < root->data ? search_rec(root->left, key) : search_rec(root->right, key);
}
// iterative search
Node* search_iter(Node* root, int key) {
    while (root) {
        if (root->data == key) return root;
        root = (key < root->data) ? root->left : root->right;
    }
    return nullptr;
}

int bst_min(Node* root) {
    if (!root) return INT_MIN;
    while (root->left) root = root->left;
    return root->data;
}
int bst_max(Node* root) {
    if (!root) return INT_MIN;
    while (root->right) root = root->right;
    return root->data;
}

Node* min_node(Node* r) { while (r && r->left) r = r->left; return r; }

// inorder successor: if node has right child -> min(right)
// else walk from root keeping candidate
Node* inorder_successor(Node* root, int key) {
    Node* t = search_iter(root, key);
    if (!t) return nullptr;
    if (t->right) return min_node(t->right);
    Node* succ = nullptr;
    Node* cur = root;
    while (cur) {
        if (key < cur->data) { succ = cur; cur = cur->left; }
        else if (key > cur->data) cur = cur->right;
        else break;
    }
    return succ;
}

Node* inorder_predecessor(Node* root, int key) {
    Node* t = search_iter(root, key);
    if (!t) return nullptr;
    if (t->left) {
        Node* p = t->left; while (p->right) p = p->right; return p;
    }
    Node* pred = nullptr;
    Node* cur = root;
    while (cur) {
        if (key > cur->data) { pred = cur; cur = cur->right; }
        else if (key < cur->data) cur = cur->left;
        else break;
    }
    return pred;
}

int main() {
    Node* root = nullptr;
    int vals[] = {20, 10, 5, 15, 30, 25, 35};
    for (int i = 0; i < 7; ++i) root = bst_insert(root, vals[i]);

    cout << "Min: " << bst_min(root) << "  Max: " << bst_max(root) << "\n";

    int key = 15;
    cout << "Search recursive " << (search_rec(root, key) ? "Found\n" : "Not found\n");
    cout << "Search iterative " << (search_iter(root, 100) ? "Found\n" : "Not found\n");

    Node* s = inorder_successor(root, 15);
    Node* p = inorder_predecessor(root, 15);
    cout << "Successor of 15: " << (s ? to_string(s->data) : string("None")) << "\n";
    cout << "Predecessor of 15: " << (p ? to_string(p->data) : string("None")) << "\n";
    return 0;
}
