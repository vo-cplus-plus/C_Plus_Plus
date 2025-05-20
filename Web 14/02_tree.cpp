#include <initializer_list>
#include <memory>
#include <limits>
#include <iostream>

template <typename T>
class Tree{
    struct Node{
        T info;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
        std::shared_ptr<Node> parent;
        Node(const T& value):info(value){}
    };
    
    std::shared_ptr<Node> head;
    std::shared_ptr<Node> end;
    public:
    Tree():end(new Node(std::numeric_limits<T>::max())){}
    Tree(const std::initializer_list<T> &list):Tree(){
        for(const T& value: list){
            addNode(value);
        }
    }
    void add(std::shared_ptr<Node>& cur, const T& value){
        if (cur->info < value){
            if (cur->right){
                if (cur->right == end){
                    cur->right = std::make_shared<Node>(Node(value));
                    cur->right->parent = cur;
                    cur->right->right = end;
                }
                else add(cur->right, value);
            } 
            else {
                cur->right = std::make_shared<Node>(Node(value));
                cur->right->parent = cur;
            }
        }
        else{
            if (cur->left) add(cur->left, value);
            else {
                cur->left = std::make_shared<Node>(Node(value));
                cur->left->parent = cur;
            }
        }
    }
    void addNode(const T&value){
        if(!head){
            head = std::make_shared<Node>(Node(value));
            head->right = end;
        }
        else{
            add(head, value);
        }
    }

    std::shared_ptr<Node> find(const std::shared_ptr<Node> & node, const T& value) const{
        if (node->info == value) return node;
        if (node->left && node->info > value) return find(node->left, value);
        if (node->right && node->info < value) return find(node->right, value);
        return end;
    }
    std::shared_ptr<Node> find(int value) const{
        return find(head, value);
    }
    void print_sorted(std::ostream & out, const std::shared_ptr<Node> & node){
        if (node->left) print_sorted(out, node->left);
        out << node->info << " ";
        if (node->right && node->right != end) print_sorted(out, node->right);
        
    }
    void print_deep(std::ostream & out, const std::shared_ptr<Node> & node){
        out << node->info << " ";
        if (node->left) print_deep(out, node->left);
        if (node->right && node->right != end) print_deep(out, node->right);        
    }
    friend std::ostream &operator << (std::ostream & out, Tree &tree){
        tree.print_deep(out, tree.head);
        out << std::endl;
        return out;
    }
};

int main(){
    Tree<int> tree({10,5, 15,1, 12 ,17,8});
    tree.addNode(6);
    tree.addNode(7);
    tree.addNode(9);
    tree.addNode(2); 
    auto ptr1 = tree.find(2);
    auto ptr2 = tree.find(3);
    auto ptr3 = tree.find(25); 
    std::cout << tree; 
    return 0;
}