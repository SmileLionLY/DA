#include <iostream>
#include <stack>

template <typename T>
class BinaryTreeNode {
 public:
    BinaryTreeNode(T data, BinaryTreeNode<T> *left_child, BinaryTreeNode<T> *right_child) :
        data_(data),
        left_child_(left_child),
        right_child_(right_child) {}
    T data_;
    BinaryTreeNode<T> *left_child_;
    BinaryTreeNode<T> *right_child_;
};

template <typename T>
class BinaryTree {
 public :
    BinaryTree() : root(NULL) {}

 private:
    BinaryTreeNode<T> *root;
};

//input A(D(F(M,),),B(,C))#
//操作关键点是碰到'('就将父节点压入栈中,碰到一个真正的节点,则取栈中的最顶端元素,根据left_node判断是右子女还是左子女,当碰到')'时,说明这个栈顶的元素已经完成了链接左右子女的任务,可以弹出堆栈了
void CreateBinaryTree(std::istream &in, BinaryTreeNode<char> *&root) {
    std::stack<BinaryTreeNode<char> *> stack_;
    BinaryTreeNode<char> *node = NULL;
    bool left_node = false;
    char value;
    while(in >> value && value != '#') {
        switch(value) {
            case '(' : {
                stack_.push(node);
                left_node = true;
                break;
            }
            case ',' : {
                left_node = false;
                break;
            }
            case ')' : {
                stack_.pop();
                break;
            }
            default : {
                node = new BinaryTreeNode<char>(value, NULL, NULL);
                if (NULL == root) {
                    root = node;    
                } else if (true == left_node) {
                    BinaryTreeNode<char> *parent_node = stack_.top();
                    parent_node->left_child_ = node;
                } else {
                    BinaryTreeNode<char> *parent_node = stack_.top();
                    parent_node->right_child_ = node;
                }
            }
        }
    }
}

int main() {
    BinaryTreeNode<char> *root = NULL;
    CreateBinaryTree(std::cin, root);
    return 0;
}
