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
 * ͬ �������
 * �ö��м�¼����·��
 * ����������������Һ�����ӣ���������ӣ���level��1��ʼ��
 * ż����������ң�������ң�
 * �����ö��еķ����Ǵ�ġ�������������ġ���
 * Ӧ����ջ
 * ������������ң�ż�����������
 * ������ջ���ֱ��¼�������ż���㡭��
 ***/
/*
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        if (NULL == root)
            return vvtree;
        
        stack<TreeNode *> stree_odd;
        stack<TreeNode *> stree_even;
        stree_odd.push(root);
        
        int level = 1;
        int n1 = 1;
        int n2 = 0;
        TreeNode *node;
        vector<int> vlevel;
        
        while (!stree_odd.empty() || !stree_even.empty())
        {
            if (level & 0x01)
            {
                node = stree_odd.top();
                stree_odd.pop();                 // pop from stree_odd
                vlevel.push_back(node->val);
                
                if (node->left)
                {
                    stree_even.push(node->left); // push into stree_even
                    ++n2;
                }
                if (node->right)
                {
                    stree_even.push(node->right);
                    ++n2;
                }
            }
            else
            {
                node = stree_even.top();
                stree_even.pop();                 // pop from stree_even
                vlevel.push_back(node->val);
                
                if (node->right)
                {
                    stree_odd.push(node->right);  // push into stree_odd
                    ++n2;
                }
                if (node->left)
                {
                    stree_odd.push(node->left);
                    ++n2;
                }
            }
            
            if (0 == --n1)
            {
                vvtree.push_back(vlevel);
                vlevel.clear();
                
                n1 = n2;
                n2 = 0;
                ++level;
            }
        }
        return vvtree;
    }
private:
    vector<vector<int> > vvtree;
};
*/

/***
 * ��2��������ô�鷳����
 * ֱ�Ӱ���˳�������Ȼ��ż���еĽ������
 ***/
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        if (NULL == root)
            return vvtree;
            
        queue<TreeNode *> qtree;
        qtree.push(root);
        
        int n1 = 1;
        int n2 = 0;
        vector<int> vlevel;
        TreeNode *node;
        
        while (!qtree.empty())
        {
            node = qtree.front();
            qtree.pop();
            vlevel.push_back(node->val);
            
            if (node->left)
            {
                qtree.push(node->left);
                ++n2;
            }
            if (node->right)
            {
                qtree.push(node->right);
                ++n2;
            }
            
            if (0 == --n1)  // end of cur level
            {
                vvtree.push_back(vlevel);
                vlevel.clear();
                
                n1 = n2;
                n2 = 0;
            }
        }
        
        // reverse odd level
        for (int i = 1; i < vvtree.size(); i += 2)
            for (int j = 0; j < vvtree[i].size()/2; ++j)
                swap(vvtree[i][j], vvtree[i][vvtree[i].size() - j - 1]);
        
        return vvtree;
    }
private:
    vector<vector<int> > vvtree;
};