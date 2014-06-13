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
 * 先序遍历 根节点在头部
 * 中序遍历 根节点在中间
 * 每次在先序遍历的序列中取第一个根节点，然后在中序遍历的序列中找到该节点
 * 先序 中序 分别取左右子树 递归
 ***/
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if ((0 == preorder.size()) || (0 == inorder.size()))
            return NULL;
        
        return buildlr(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
private:
    TreeNode *buildlr(vector<int> &preorder, int preL, int preR,
                      vector<int> &inorder,  int inL,  int inR)
    {
        if ((preL > preR) || (inL > inR))
            return NULL;
        
        TreeNode *root = new TreeNode(preorder[preL]);  // get the head of preorder
        
        // find root in inorder
        int iroot;
        for (iroot = inL; iroot <= inR; ++iroot)
            if (inorder[iroot] == preorder[preL])
                break;
        
        int preM = preL + (iroot - inL);  // left child
        root->left = buildlr(preorder, preL+1, preM, inorder, inL, iroot-1);
        root->right = buildlr(preorder, preM+1, preR, inorder, iroot+1, inR);
        
        return root;
    }
};