class Solution {
public:
    vector<int> maxSumOfOneSubarray(vector<int> &nums, int k) {
        vector<int> ans;
        int sum1 = 0, maxSum1 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum1 += nums[i];
            if (i >= k - 1) {
                if (sum1 > maxSum1) {
                    maxSum1 = sum1;
                    ans = {i - k + 1};
                }
                sum1 -= nums[i - k + 1];
            }
        }
        return ans;
    }
};
