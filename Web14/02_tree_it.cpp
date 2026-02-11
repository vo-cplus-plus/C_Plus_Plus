#include <initializer_list>
#include <memory>

template <typename T>
class Tree{
    struct Node{
        T info;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
        std::shared_ptr<Node> parent;
        Node(const T& value):info(value){}
    };
    struct Iterator{
        std::shared_ptr<Node> cur;
        
        int operator *(){
            return cur->info;
        }

        static std::shared_ptr<Node> go_left(std::shared_ptr<Node>& cur){
            if(cur->left) return go_left(cur->left);
            return cur;
        }        
        Iterator& operator ++(){
            if (cur->parent){
                if (cur == cur->parent->left){
                    return cur = cur->parent;
                }
                else{
                    if (cur->right) cur = go_left(cur->right);
                    else cur = find_next(cur->parent);
                }
            }
        }
    };
    std::shared_ptr<Node> head;
    public:
    Tree():head(nullptr){}
    Tree(const std::initializer_list<T> &list){
        for(T& value: list){
            addNode(value);
        }
    }
    void add(std::shared_ptr<Node>& cur, const T& value){
        if (cur->info < value){
            if (cur->right) add(cur->right, value);
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
        if(!head){head = std::make_shared<Node>(Node(value));}
        else{
            add(head, value);
        }
    }
   
    Iterator begin(){
        return Iterator::go_left(head);
    }
};

int main(){
    Tree<int> tree;
    tree.addNode(5);
    tree.addNode(7);
    tree.addNode(9);
    tree.addNode(2);
    auto it = tree.begin();
    int value = *it;
    return 0;
}