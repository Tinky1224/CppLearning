#include<iostream>
#include<vector>
#include<algorithm>

class TreapNode{
    private:
        int val, priority;
        TreapNode *left=nullptr, *right=nullptr;
        void L_rotate(TreapNode &p){
            TreapNode tmp=*(p.right);
            p.right = tmp.left;
            tmp.left = new TreapNode();
            tmp.left->val = p.val;
            tmp.left->priority = p.priority;
            tmp.left->left = p.left;
            tmp.left->right = p.right;
            p = tmp;
        }
        void R_rotate(TreapNode &p){
            TreapNode tmp=*(p.left);
            p.left = tmp.right;
            tmp.right = new TreapNode();
            tmp.right->val = p.val;
            tmp.right->priority = p.priority;
            tmp.right->left = p.left;
            tmp.right->right = p.right;
            p = tmp;
        }
        bool _insert(TreapNode &root, TreapNode &p){
            if (root.val == p.val){
                delete &p;
                return false;
            }else if (root.val > p.val){
                if (!root.left){
                    root.left = &p;
                    if (root.priority > root.left->priority) R_rotate(root);
                    return true;
                }else{
                    bool res = _insert(*(root.left), p);
                    if (root.priority > root.left->priority) R_rotate(root);
                    return res;
                }
            }else if (root.val < p.val){
                if (!root.right){
                    root.right = &p;
                    if (root.priority > root.right->priority) L_rotate(root);
                    return true;
                }else{
                    bool res = _insert(*(root.right), p);
                    if (root.priority > root.right->priority) L_rotate(root);
                    return res;
                }
            }
            return false;
        }

        bool _remove(TreapNode *p){
            if (!p) return false;
            while (p->left && p->right){
                if (p->left->priority < p->right->priority){
                    R_rotate(*p);
                    p = p->right;
                }else{
                    L_rotate(*p);
                    p = p->left;
                }
            }
            if (!p->left){
                p = p->right;
            }else{
                p = p->left;
            }
            return true;
        }

    public:
        TreapNode() : val(0), priority(0){}
        TreapNode(int value, int priority_value): val(value), priority(priority_value) {}

        bool insert(int value, int priority_value){
            TreapNode *node = new TreapNode(value, priority_value);
            return _insert(*this, *node);
        }

        bool remove(int value){
            TreapNode *node = this;
            while (node && node->val != value){
                if (node->val > value) node = node->left;
                else if (node->val < value) node = node->right;
            }
            return _remove(node);
        }

        void preorder(){
            std::cout << "[" << val << ", " << priority << "]" << " ";
            if (left) left->preorder();
            if (right) right->preorder();
        }

        void inorder(){
            if (left) left->inorder();
            std::cout << "[" << val << ", " << priority << "]" << " ";
            if (right) right->inorder();
        }
        
        void cout_val(){
            std::cout << val << std::endl;
        }
};

int main(){
    TreapNode root(11,19);
    root.preorder();
    std::cout << std::endl;
    root.inorder();
    std::cout << std::endl;
    root.insert(7,13);
    root.preorder();
    std::cout << std::endl;
    root.inorder();
    std::cout << std::endl;
    root.insert(14,14);
    root.preorder();
    std::cout << std::endl;
    root.inorder();
    std::cout << std::endl;
    root.insert(3,18);
    root.preorder();
    std::cout << std::endl;
    root.inorder();
    std::cout << std::endl;
    root.insert(9,22);
    root.preorder();
    std::cout << std::endl;
    root.inorder();
    std::cout << std::endl;
    root.insert(18,20);
    root.preorder();
    std::cout << std::endl;
    root.inorder();
    std::cout << std::endl;
    root.insert(16,26);
    root.preorder();
    std::cout << std::endl;
    root.inorder();
    std::cout << std::endl;
    root.insert(15,30);
    root.preorder();
    std::cout << std::endl;
    root.inorder();
    std::cout << std::endl;
    root.insert(17,12);
    root.preorder();
    std::cout << std::endl;
    root.inorder();
    std::cout << std::endl;
    return 0;
}