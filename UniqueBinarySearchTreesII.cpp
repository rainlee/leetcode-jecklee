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
    vector<TreeNode *> gTrees(int low, int high)
    {
        vector <TreeNode *> vtree;
        if (low > high)
        {
            vtree.push_back(NULL);  // note: ����ս��!
            return vtree;
        }
        
        for (int i = low; i <= high; i++)  // ��iΪ�����
        {
            vector<TreeNode *> vleft = gTrees(low, i-1);    // ������������
            vector<TreeNode *> vright = gTrees(i+1, high);
            
            // ���������������
            for (int j = 0; j < vleft.size(); j++)
            {
                for (int k = 0; k < vright.size(); k++)
                {
                    // ���ɸ���㣬���������ֱ�ȡһ��������
                    TreeNode *root = new TreeNode(i);  // val = i
                    root->left = vleft[j];
                    root->right = vright[k];
                    vtree.push_back(root);
                }
            }
        }
        
        return vtree;
    }
    vector<TreeNode *> generateTrees(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        return gTrees(1, n);
    } 
};