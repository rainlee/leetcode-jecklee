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
 * 将先序遍历的结果组成一单链表，即为所求
 * 先序遍历，递归实现
 * 由于单链表由右孩子组成，原来的左孩子要覆盖右孩子，所以要保存右孩子
 * 由于左子树处理完了，右子树要跟在左子树转换的链表后面next
 * 所以得知道左子树的最后一个节点（上一个处理的节点）
 ***/
class Solution {
public:
    void flatten(TreeNode *root) {
        TreeNode *last = NULL;
        preorderTravel(root, last);
    }
private:
    // caution, last node must be returned!!!
    void preorderTravel(TreeNode *root, TreeNode *&last)
    {
        if (NULL == root)
            return;
        TreeNode *rchild = root->right;  // right child will be replaced by lchild
        if (last)     // add cur node(root) to linked list
            last->right = root;
        last = root;
        
        preorderTravel(root->left, last);
        root->left = NULL;    // update left child
        preorderTravel(rchild, last);
        return;
    }
};

// 加一个虚头，可以不用判断上一个节点是否为空
class Solution {
public:
    void flatten(TreeNode *root) {
        TreeNode dummy(-1);
        TreeNode *last = &dummy;
        flattenRec(root, last);
    }
private:
    void flattenRec(TreeNode *root, TreeNode *&last)  // preorder
    {
        if (!root)
            return;
        TreeNode *rchild = root->right;
        last->right = root;
        last = root;
        flattenRec(root->left, last);
        root->left = NULL;   // break left subtree here!!!
        flattenRec(rchild, last);
    }
};