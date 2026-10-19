/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int levelOrder(TreeNode* root, int p) {
        int count = 0;
        if (root == NULL) return count;

        queue<pair<TreeNode*, int>> q;  // store node + max so far
        q.push({root, p});

        while (!q.empty()) {
            auto [curr, maxSoFar] = q.front();
            q.pop();

            if (curr->val >= maxSoFar)
                count++;

            int newMax = max(maxSoFar, curr->val);

            if (curr->left != NULL)
                q.push({curr->left, newMax});
            if (curr->right != NULL)
                q.push({curr->right, newMax});
        }

        return count;
    }

    int goodNodes(TreeNode* root) {
        if (root == NULL) return 0;
        int p = root->val;
        return levelOrder(root, p);
    }
};
