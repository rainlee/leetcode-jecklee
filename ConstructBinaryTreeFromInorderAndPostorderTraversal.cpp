/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/***
 * 中序遍历：左子树 + 根节点 + 左子树
 * 后序遍历：左子树 + 左子树 + 根节点
 * 先在后序遍历的序列中取得根节点，然后在中序遍历的序列中找到根节点
 * 中序 后序分为左右子树，分别递归
 ***/
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if ((0 == inorder.size()) || (0 == postorder.size()))
            return NULL;
        
        return buildlr(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
private:
    TreeNode *buildlr(vector<int> &inorder,   int inL,   int inR,
                      vector<int> &postorder, int postL, int postR) 
    {
        if ((inL > inR) || (postL > postR))
            return NULL;
        
        TreeNode *root = new TreeNode(postorder[postR]);  // get root in postorder
        
        // find root in inorder
        int iroot;
        //for (int iroot = inL; iroot <= inR; ++iroot)  // I should remember this bug……
        for (iroot = inL; iroot <= inR; ++iroot)
            if (inorder[iroot] == postorder[postR])
                break;
        
        int postM = postL + (iroot - inL) - 1;
        root->left = buildlr(inorder, inL, iroot-1, postorder, postL, postM);
        root->right = buildlr(inorder, iroot+1, inR, postorder, postM+1, postR-1);
        
        return root;
    }
};