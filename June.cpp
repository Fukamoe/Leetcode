class Solution {
private:
    int maxLevel = -1;
    int sum = 0;

public:
    int deepestLeavesSum(TreeNode* root) {
        dfs(root, 0);
        return sum;
    }

    void dfs(TreeNode* node, int level) {
        if (node == nullptr) {
            return;
        }
        if (level > maxLevel) {
            maxLevel = level;
            sum = node->val;
        } else if (level == maxLevel) {
            sum += node->val;
        }
        dfs(node->left, level + 1);
        dfs(node->right, level + 1);
    }
};
