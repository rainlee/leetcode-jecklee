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
 * 将中序遍历的结果组成一单链表，即为所求
 * 中序遍历，递归实现
 * 由于单链表由右孩子组成，原来的左孩子要覆盖右孩子，所以要保存右孩子
 * 由于左子树处理完了，右子树要跟在左子树转换的链表后面next
 * 所以得知道左子树的最后一个节点（上一个处理的节点）
 ***/
class Solution {
public:
    void flatlr(TreeNode *root, TreeNode * &prenode)  // prenode, last node; caution, prenode must be returned!!!
    {
        if (NULL == root)
            return;
            
        prenode->right = root;   // add cur node(root) to linked list
        prenode = root;
        
        TreeNode *rchild = root->right; // right child will be replaced by lchild
        
        flatlr(root->left, prenode);
        root->left = NULL;            // update left child
        
        flatlr(rchild, prenode);
    }
    
    void flatten(TreeNode *root) {
        if (NULL == root)
            return;
        
        TreeNode *prenode = new TreeNode(-1);  // fake prenode
        flatlr(root, prenode);
        
        return;
    }
};