/*
Definition for binary tree:
	struct TreeNode {
	    int val;
	    TreeNode *left;
	    TreeNode *right;
	    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};
*/
 
void rootToLeafPaths(TreeNode *root, int sum, vector<vector<int>> &res, deque<int> q) {
    
    if(!root)                           //return if root is null
        return;
    
    if(!root->left && !root->right && sum==root->val) {
        q.push_back(root->val);
        vector<int> v;                  //stores the path if a leaf node is reached and the sum is satisfied
        while(!q.empty()) {
            v.push_back(q.front());
            q.pop_front();
        }
        res.push_back(v);
    }
    
    q.push_back(root->val);
    
    if(root->left)                      //go to left child recursively
        rootToLeafPaths(root->left,sum-(root->val),res,q);
    if(root->right)                     //got to right child recursively
        rootToLeafPaths(root->right,sum-(root->val),res,q);
    
    q.pop_back();
    
}
 
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    
    vector<vector<int>> res;
    deque<int> q;
    
    rootToLeafPaths(A,B,res,q);         //call helper function to get the desired paths
    
    return res;
    
}

