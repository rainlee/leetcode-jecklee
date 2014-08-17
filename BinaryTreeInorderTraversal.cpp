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
 * 递归
 * 左孩子 -> 根节点 -> 右孩子
 ***/
/*
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        if (!root)
            return vtree;
        inorderTraversal(root->left);
        vtree.push_back(root->val);
        inorderTraversal(root->right);
        return vtree;
    }
private:
    vector<int> vtree;
};
*/

/***
 * 非递归
 * 用栈保存遍历路径
 * 左孩子入栈，一直到最左孩子
 * 出栈，访问右孩子
 ***/
/*
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> vtree;
        if (!root)
            return vtree;
            
        stack<TreeNode *> stree;
        TreeNode *node = root;
        while (node || !stree.empty())
        {
            while (node)
            {
                stree.push(node);
                node = node->left;      // visit left
            }
            node = stree.top();
            stree.pop();
            vtree.push_back(node->val); // visit root
            node = node->right;         // visit right, may be null
        }
        return vtree;
    }
};
*/

/***
 * 法3：O(1)空间遍历树，Morris算法
 * 要使用O(1)空间进行遍历，最大的难点在于，遍历到子节点的时候怎样重新返回到父节点
 *（假设节点中没有指向父节点的p指针）
 * Morris方法使用线索二叉树（threaded binary tree）。
 * 在Morris方法中不需要为每个节点额外分配指针指向其前驱和后继节点，只需要利用叶子节点
 * 中的左右空指针指向某种顺序遍历下的前驱节点或后继节点就可以了。
 * 利用所有叶子结点的右指针，指向其后继结点，组成一个环，在第二次遍历到这个结点时，
 * 由于其左子树已经遍历完了，则访问该结点
 * 也就是，第一次访问root时，将根的左子树(root->left)的最右节点指向根(root)
 * 当左子树的最右节点(node->right)等于root，说明是第二次访问root
 * 按照中序的规则，此时应该输出root
 * 注意：还原左子树的最右节点node->right = NULL
 ***/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> vtree;
        if (!root)
            return vtree;
        
        TreeNode *node = root;
        while (node)
        {
            if (!(node->left))  // the leftest leaf node
            {
                vtree.push_back(node->val);
                node = node->right;
            }
            else
            {
                TreeNode *tmp = node->left;
                while (tmp->right && (node != tmp->right))  // find the rightest node of lchild
                    tmp = tmp->right;
                if (!(tmp->right))      // first visit
                {
                    tmp->right = node;  // connect rightest node to root
                    node = node->left;  // continue, back to root->left
                }
                else                    // second visit
                {
                    vtree.push_back(node->val);
                    tmp->right = NULL;  // caution: break the connection between rightest node and root
                    node = node->right;
                }
            }
        }
        return vtree;
    }
};