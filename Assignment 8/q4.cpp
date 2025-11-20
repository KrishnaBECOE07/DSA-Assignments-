#include <iostream>
#include <climits>
using namespace std;

struct Node { int data; Node* left; Node* right; Node(int v): data(v), left(nullptr), right(nullptr) {} };

bool is_bst_util(Node* r, long long low, long long high) {
    if (!r) return true;
    if (r->data <= low || r->data >= high) return false;
    return is_bst_util(r->left, low, r->data) && is_bst_util(r->right, r->data, high);
}
bool is_bst(Node* root) { return is_bst_util(root, LLONG_MIN, LLONG_MAX); }

int main() {
    // make a tree that is not a BST:
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->right = new Node(12); // violates BST property

    cout << "Is tree BST? " << (is_bst(root) ? "Yes" : "No") << "\n";

    // Now a correct BST:
    Node* b = new Node(10);
    b->left = new Node(5);
    b->right = new Node(15);
    b->left->right = new Node(7);
    cout << "Is second tree BST? " << (is_bst(b) ? "Yes" : "No") << "\n";
    return 0;
}
