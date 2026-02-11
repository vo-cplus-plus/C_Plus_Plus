#include <initializer_list>

template <typename T>
class Tree{
    struct Node{
        T info;
        Node*left;
        Node*right;
        Node(const T& value):info(value), left(nullptr), right(nullptr){}
    };
    Node *head;
    public:
    Tree():head(nullptr){}
    Tree(const std::initializer_list<T> &list):Tree(){
        for(const T& value: list){
            addNode(value);
        }
    }
    void add(Node * cur, const T& value){
        if (cur->info < value){
            if (cur->right) add(cur->right, value);
            else cur->right = new Node(value);
        }
        else{
            if (cur->left) add(cur->left, value);
            else cur->left = new Node(value);
        }
    }
    void addNode(const T&value){
        if(!head){head = new Node(value);}
        else{
            add(head, value);
        }
    }
};

int main(){
    Tree<int> tree({10,5, 15,1, 12 ,17,8});
    tree.addNode(6);
    tree.addNode(7);
    tree.addNode(9);
    tree.addNode(2);
    return 0;
}