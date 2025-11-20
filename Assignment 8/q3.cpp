#include <iostream>
using namespace std;

struct Node { int data; Node* left; Node* right; Node(int v): data(v), left(nullptr), right(nullptr) {} };

Node* bst_insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data) root->left = bst_insert(root->left, key);
    else if (key > root->data) root->right = bst_insert(root->right, key);
    else cout << "Duplicate ignored: " << key << "\n";
    return root;
}
Node* min_node(Node* r) { while (r && r->left) r = r->left; return r; }

Node* bst_delete(Node* root, int key) {
    if (!root) return nullptr;
    if (key < root->data) root->left = bst_delete(root->left, key);
    else if (key > root->data) root->right = bst_delete(root->right, key);
    else {
        if (!root->left) { Node* t = root->right; delete root; return t; }
        else if (!root->right) { Node* t = root->left; delete root; return t; }
        else {
            Node* succ = min_node(root->right);
            root->data = succ->data;
            root->right = bst_delete(root->right, succ->data);
        }
    }
    return root;
}

int max_depth(Node* r) {
    if (!r) return 0;
    int l = max_depth(r->left), rr = max_depth(r->right);
    return 1 + (l > rr ? l : rr);
}
int min_depth(Node* r) {
    if (!r) return 0;
    if (!r->left && !r->right) return 1;
    if (!r->left) return 1 + min_depth(r->right);
    if (!r->right) return 1 + min_depth(r->left);
    int l = min_depth(r->left), rr = min_depth(r->right);
    return 1 + (l < rr ? l : rr);
}

void inorder(Node* r) { if (!r) return; inorder(r->left); cout << r->data << " "; inorder(r->right); }

int main() {
    Node* root = nullptr;
    int a[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; ++i) root = bst_insert(root, a[i]);

    cout << "BST inorder: "; inorder(root); cout << "\n";
    cout << "Max depth: " << max_depth(root) << "\n";
    cout << "Min depth: " << min_depth(root) << "\n";

    cout << "Delete 30\n"; root = bst_delete(root, 30);
    cout << "Inorder now: "; inorder(root); cout << "\n";
    return 0;
}
