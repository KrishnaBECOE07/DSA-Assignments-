#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v): data(v), left(nullptr), right(nullptr) {}
};

void preorder(Node* r) {
    if (!r) return;
    cout << r->data << " ";
    preorder(r->left);
    preorder(r->right);
}
void inorder(Node* r) {
    if (!r) return;
    inorder(r->left);
    cout << r->data << " ";
    inorder(r->right);
}
void postorder(Node* r) {
    if (!r) return;
    postorder(r->left);
    postorder(r->right);
    cout << r->data << " ";
}

int main() {
    // small sample tree:
    //      8
    //     / \
    //    3  10
    //   / \   \
    //  1  6   14
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(14);

    cout << "Preorder: "; preorder(root); cout << "\n";
    cout << "Inorder:  "; inorder(root);  cout << "\n";
    cout << "Postorder:"; postorder(root);cout << "\n";
    return 0;
}
