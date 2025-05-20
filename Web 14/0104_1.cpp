#include <algorithm>
#include <queue>
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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;        
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        
        while (q.size()){
            depth += 1;
            int n = q.size();            
            for (int i =0; i<n; i++){ 
                TreeNode * node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);                    
            }
        }
        return depth;   
    }
};