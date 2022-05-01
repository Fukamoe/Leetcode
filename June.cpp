class Solution {
    void inorder(TreeNode *node, vector<int> &res) {
        if (node) {
            inorder(node->left, res);
            res.push_back(node->val);
            inorder(node->right, res);
        }
    }

public:
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
        vector<int> nums1, nums2;
        inorder(root1, nums1);
        inorder(root2, nums2);

        vector<int> merged;
        auto p1 = nums1.begin(), p2 = nums2.begin();
        while (true) {
            if (p1 == nums1.end()) {
                merged.insert(merged.end(), p2, nums2.end());
                break;
            }
            if (p2 == nums2.end()) {
                merged.insert(merged.end(), p1, nums1.end());
                break;
            }
            if (*p1 < *p2) {
                merged.push_back(*p1++);
            } else {
                merged.push_back(*p2++);
            }
        }
        return merged;
    }
};
