// Leetcode: https://leetcode.com/problems/maximum-width-of-binary-tree/

#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int res =1;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            int cnt = q.size();
            int s = q.front().second;
            int e = q.back().second;
            res = max(res, e-s+1);
            for(int i=0; i< cnt; i++)
            {
                pair<TreeNode*,int> p = q.front();
                int idx = p.second - s;
                q.pop();
                if(p.first->left != NULL)
                {
                    q.push({p.first->left,(long long)2*idx });
                }
                if(p.first->right != NULL)
                {
                    q.push({p.first->right, (long long)2*idx +1});
                }
            }
        }
        return res;
    }
};

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    Solution s;
    cout << s.widthOfBinaryTree(root) << endl;
    return 0;
}