/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int>> outter;
        
        int level = 0;
        this->traverse(root, level, outter);
        
        return outter;
        
    }
    
    void traverse(TreeNode *root, int level, vector<vector<int>> &outter) {
        if(root == NULL) {
            return;
        }
        if(level == outter.size()) {
            vector<int> v;
            outter.push_back(v);
        }
        
        outter[level].push_back(root->val);
        
        if(root->left) traverse(root->left, level+1, outter);
        if(root->right) traverse(root->right, level+1, outter);
        
    }
};
