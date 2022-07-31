class Solution {
    vector<int> sum;

    void dfs(TreeNode *node, int level) {
        if (level == sum.size()) {
            sum.push_back(node->val);
        } else {
            sum[level] += node->val;
        }
        if (node->left) {
            dfs(node->left, level + 1);
        }
        if (node->right) {
            dfs(node->right, level + 1);
        }
    }

public:
    int maxLevelSum(TreeNode *root) {
        dfs(root, 0);
        int ans = 0;
        for (int i = 0; i < sum.size(); ++i) {
            if (sum[i] > sum[ans]) {
                ans = i;
            }
        }
        return ans + 1; // 层号从 1 开始
    }
};
