#include <iostream>
using namespace std;

struct Node{
    int val;
    Node **left=nullptr, **right=nullptr;
    Node(): val(0) {};
    Node(int a): val(a) {};
};
void preorder(Node &p){
    cout << p.val << " ";
    if (*(p.left)) preorder(**(p.left));
    if (*(p.right)) preorder(**(p.right));
};
void inorder(Node &p){
    if (*(p.left)) preorder(**(p.left));
    cout << p.val << " ";
    if (*(p.right)) preorder(**(p.right));
};
/*
void L_rotate(Node &p){
    Node **tmp = (p.right);
    *(p->right) = (**tmp->left);
    *(tmp->left) = p;
    p = tmp;
};
void R_rotate(Node &p){
    Node **tmp = (p.left);
    p->left = tmp->left;
    tmp->left = p;
    p = tmp;
};
*/
int main(){
    Node root(1), n1(2), n2(3);
    root.left = n1;
    root.left->right = new Node(3);
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    /*
    L_rotate(root.left);
    */
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    return 0;
}