#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    
    int getHeight(TreeNode* node, bool &isBalancedTree){
        if(!node || !isBalancedTree) return 0;
        int left = getHeight(node->left, isBalancedTree);
        int right = getHeight(node->right, isBalancedTree);
        if(abs(left - right) > 1){
            isBalancedTree = false;
        }
        return 1 + max(left, right);
    }
    
    
    bool isBalanced(TreeNode* root) {
        bool isBalancedTree = true;
        getHeight(root, isBalancedTree);
        return isBalancedTree;
    }
};