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
 * 法1：递归
 * 后序遍历，左孩子 -> 右孩子 -> 根节点
 ***/
/*
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        if (!root)
            return vtree;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        vtree.push_back(root->val);
        return vtree;
    }
private:
    vector<int> vtree;
};
*/

/***
 * 法2：非递归
 * 用一个栈保存遍历路径
 * 根结点入栈，找到最左孩子，路径所有结点入栈
 * 访问最左孩子，访问右子树（右孩子入栈）
 * 有两个时刻需要出栈，当左右孩子为空时 & 当左右孩子都已访问时
 * 故每次出栈时，标记上一个已访问的结点
 ***/
/*
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        if (NULL == root)
            return vtree;
        
        stack<TreeNode *> stree;
        TreeNode *node = root;
        TreeNode *prenode = NULL;
        
        while (node || (!stree.empty()))
        {
            while (node)
            {
                stree.push(node);
                node = node->left;
            }
            
            node = stree.top();
            
            if ((NULL == node->right) || (prenode == node->right))
            {
                vtree.push_back(node->val);   // visit cur node
                prenode = node;               // mark the pre node
                stree.pop();
                node = NULL;                  // cur node has been visited
            }
            else
                node = node->right;
        }
        return vtree;
    }
private:
    vector<int> vtree;
};
*/

/***
 * 法3：Morris 时间复杂度O(n) 空间复杂度O(1)
 * 后续遍历稍显复杂，需要建立一个临时节点dummy，令其左孩子是root。
 * 并且还需要一个子过程，就是倒序输出某两个节点之间路径上的各个节点。
 * 同样是一直往左走，到最左孩子，再往右走
 * 第一次访问左子树的最右孩子时，将其连接到root上（后继）
 * 第二次访问时，倒序输出从当前节点的左孩子到该前驱节点这条路径上的所有节点。
 * 并且断开前驱节点和root
 * 注意倒序输出需要先逆转链表，然后输出，之后再逆转链表
 ***/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        if (!root)
            return vtree;
        
        TreeNode dummy(-1);
        dummy.left = root;
        TreeNode *node = &dummy;
        while (node)
        {
            if (!(node->left))
                node = node->right;
            else
            {
                TreeNode *tmp = node->left;
                while (tmp->right && (tmp->right != node))
                    tmp = tmp->right;
                if (!(tmp->right))      // first visit
                {
                    tmp->right = node;  // connect
                    node = node->left;
                }
                else
                {
                    reverseVisitNodes(node->left, tmp);
                    tmp->right = NULL;  // break
                    node = node->right;
                }
            }
        }
        return vtree;
    }
private:
    vector<int> vtree;
    
    void reverseTreeList(TreeNode *start, TreeNode *end)
    {
        if (start == end)
            return;
        TreeNode *pre = start;
        TreeNode *cur = start->right;
        while (true)
        {
            TreeNode *next = cur->right;
            cur->right = pre;
            if (cur == end)
                break;
            pre = cur;
            cur = next;
        }
    }
    // visit nodes from end to start
    void reverseVisitNodes(TreeNode *start, TreeNode *end)
    {
        if (!start)
            return;
        reverseTreeList(start, end);
        TreeNode *node = end;
        while (true)
        {
            vtree.push_back(node->val);
            if (node == start)
                break;
            node = node->right;
        }
        reverseTreeList(end, start);   // reduce
    }
};

/**********************************************************/
// 后序遍历 左右根
// 逆序就是 根右左，观察发现，恰好是前序遍历的对称形式
// 所以可以用类似前序遍历的方法，先求出根右左，然后逆序
/*
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        if (!root)
            return vtree;
        reversePreorderTree(root);
        reverse(vtree.begin(), vtree.end());
        return vtree;
    }
private:
    vector<int> vtree;
    void reversePreorderTree(TreeNode *root)
    {
        if (!root)
            return;
        
        vtree.push_back(root->val);
        reversePreorderTree(root->right);
        reversePreorderTree(root->left);
        return;
    }
};
*/

/*
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        if (!root)
            return vtree;
        reversePreorderTree(root);
        reverse(vtree.begin(), vtree.end());
        return vtree;
    }
private:
    vector<int> vtree;
    
    void reversePreorderTree(TreeNode *root)
    {
        if (!root)
            return;
        
        stack<TreeNode *> stree;
        TreeNode *node = root;
        while (node || !stree.empty())
        {
            while (node)
            {
                vtree.push_back(node->val);
                stree.push(node);
                node = node->right;
            }
            node = stree.top();
            stree.pop();
            node = node->left;
        }
        return;
    }
};
*/

// morris
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        if (!root)
            return vtree;
        reversePreorderTree(root);
        reverse(vtree.begin(), vtree.end());
        return vtree;
    }
private:
    vector<int> vtree;
    
    void reversePreorderTree(TreeNode *root)
    {
        if (!root)
            return;
        
        TreeNode *node = root;
        while (node)
        {
            if (!node->right)
            {
                vtree.push_back(node->val);
                node = node->left;
            }
            else
            {
                TreeNode *tmp = node->right;
                while ((NULL != tmp->left) && (node != tmp->left))
                    tmp = tmp->left;
                if (!tmp->left)
                {
                    vtree.push_back(node->val);
                    tmp->left = node;
                    node = node->right;
                }
                else
                {
                    tmp->left = NULL;
                    node = node->left;
                }
            }
        }
    }
};