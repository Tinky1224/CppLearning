//unfinished.
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

class RBTree{
    private:
        struct Node {
            int value;
            bool color;
            Node *left, *right, *parent;

            Node() : value(0), color(false), left(nullptr), right(nullptr), parent(nullptr) {}

            Node *grandparent(){
                if (!parent) return nullptr;
                return parent->parent;
            }
            Node* uncle(){
                if (!grandparent()) return nullptr;
                if (parent == grandparent()->left) return grandparent()->right;
                else return grandparent()->left;
            }
            Node* sibling(){
                if (!parent) return nullptr;
                if (parent->left == this) return parent->right;
                else return parent->left;
            }
        };

        Node *root, *NIL;

        void R_rotate(Node* p){
            Node *gp = p->grandparent(), *fa=p->parent, *y=p->right;
            
            fa->left = y;
            if (y != NIL) y->parent = fa;
            p->right = fa;
            fa->parent = p;

            if (root == fa) root = p;
            p->parent = gp;

            if (gp){
                if (gp->left == fa) gp->left = p;
                else gp->right = p;
            }
        }

        void L_rotate(Node* p){
            if (!p->parent){
                root = p;
                return ;
            }
            Node *gp = p->grandparent(), *fa = p->parent, *y = p->left;

            fa->left = p;

            if (y!=NIL) y->parent = fa;
            p->left = fa;
            fa->parent = p;

            if (root == fa) root = p;
            p->parent = gp;

            if (gp){
                if (gp->left == fa) gp->left = p;
                else gp->right = p;
            }
        }

        void inorder(Node* p){
            if (p==NIL) return;
            if (p->left) inorder(p->left);
            std::cout << p->value << ", ";
            if (p->right) inorder(p->right);
        }

        std::string outputcolor(Node* p){
            if (p->color) return "BLACK";
            return "RED";
        } 

        Node* getSmallestChild(Node* p){
            if (p->left == NIL) return p;
            return getSmallestChild(p->left);
        }

        bool delete_child(Node* p, int val){
            if (p->value > val){
                if (p->left == NIL) return false;
                return delete_child(p->left, val);
            }else if (p->value < val){
                if (p->right == NIL) return false;
                return delete_child(p->right, val);
            }else if (p->value == val){
                if (p->right == NIL){
                    delete_one_child(p);
                }else{
                    Node* smallest = getSmallestChild(p->right);
                    std::swap(p->value, smallest->value);
                    delete_one_child(smallest);
                }
                return true;
            }else{
                return false;
            }
        }

        void delete_one_child(Node *p){
            Node *child = (p->left == NIL ? p->right : p->left);
            if (p->parent == nullptr){
                if (p->left == NIL && p->left == NIL){
                    p = nullptr;
                    root = p;
                    return ;
                }else{
                    delete p;
                    child->parent = nullptr;
                    root = child;
                    root->color = true;
                    return ;
                }
            }
            if (p->parent->left == p) p->parent->left = child;
            else p->parent->right = child;
            child->parent = p;

            if (p->color){
                if (!child->color) child->color = true;
                else delete_case(child);
            }
            delete p;
        }

        void delete_case(Node* p){
            if (p->parent == nullptr) {
                p->color = true;
                return ;
            }
            if (!p->sibling()->color){
                p->parent->color = false;
                p->sibling()->color = true;
                if (p->parent->left == p) L_rotate(p->parent);
                else R_rotate(p->parent);
            }
            if (p->parent->color && p->sibling()->color && p->sibling()->left->color && p->sibling()->right->color){
                p->sibling()->color = false; // change to red.
                delete_case(p->parent);
            }else if (!p->parent->color && p->sibling()->color && p->sibling()->right->color && p->sibling()->left->color){
                p->sibling()->color = false;
                p->parent->color = true;
            }else{
                if (p->sibling()->color){
                    if(p==p->parent->left && !p->sibling()->left->color && p->sibling()->right->color){
                        p->sibling()->color = false;
                        p->sibling()->left->color = true;
                        R_rotate(p->sibling()->left);
                    }else if (p==p->parent->right && !p->sibling()->right->color && p->sibling()->left->color){
                        p->sibling()->color = false;
                        p->sibling()->right->color = true;
                        L_rotate(p->sibling()->right);
                    }
                }
                p->sibling()->color = p->parent->color;
                p->parent->color = true;
                if (p == p->parent->left){
                    p->sibling()->right->color = true;
                    L_rotate(p->sibling());
                }else{
                    p->sibling()->left->color = true;
                    R_rotate(p->sibling());
                }
            }
        }

        void insert(Node *p, int val){
            if (p->value >= val){
                if (p->left != NIL) insert(p->left, val);
                else {
                    Node *tmp = new Node();
                    tmp->value = val;
                    tmp->left = NIL;
                    tmp->right = NIL;
                    tmp->parent = p;
                    p->left = tmp;
                    insert_case(tmp);
                }
            }else{
                if (p->right != NIL) insert(p->right, val);
                else{
                    Node *tmp = new Node();
                    tmp->value = val;
                    tmp->left = NIL;
                    tmp->right = NIL;
                    tmp->parent = p;
                    p->right = tmp;
                    insert_case(tmp);
                }
            }
        }

        void insert_case(Node *p){
            if (!p->parent){
                root = p;
                p->color = true;
                return ;
            }
            if (!p->parent->color){
                if (!p->uncle()->color){
                    p->parent->color = true;
                    p->uncle()->color = true;
                    p->grandparent()->color = false;
                    R_rotate(p);
                }else{
                    if (p==p->parent->right && p->parent==p->grandparent()->left){
                        L_rotate(p);
                        p->color = true;
                        p->parent->color = false;
                        R_rotate(p);
                    }else if (p==p->parent->left && p->parent==p->grandparent()->right){
                        R_rotate(p);
                        p->color = true;
                        p->parent->color = false;
                        L_rotate(p);
                    }else if (p==p->parent->right && p->parent==p->grandparent()->right){
                        p->parent->color = true;
                        p->grandparent()->color = false;
                        L_rotate(p->parent);
                    }else if (p==p->parent->left && p->parent==p->grandparent()->left){
                        p->parent->color = true;
                        p->grandparent()->color = false;
                        R_rotate(p->parent);
                    }
                }
            }
        }

        void DeleteTree(Node *p){
            if (!p || p==NIL) return ;
            DeleteTree(p->left);
            DeleteTree(p->right);
            delete p;
        }
    public:
        RBTree(){
            NIL = new Node();
            NIL->color = true;
            root = nullptr; 
        }

        ~RBTree(){
            if (root) DeleteTree(root);
            delete NIL;
        }

        void inorder(){
            if (!root) return;
            inorder(root);
            std::cout << std::endl;
        }

        void insert(int val){
            if (!root){
                root = new Node();
                root->color = true;
                root->left = NIL;
                root->right = NIL;
                root->value = val;
            }else{
                insert(root, val);
            }
        }

        bool delete_value(int val){
            return delete_child(root, val);
        }
};

int main(){
    return 0;
}