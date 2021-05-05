//class Solution {
//public:
//    int reverse(int x) {
//        int rev = 0;
//        while (x != 0) {
//            if (rev < INT_MIN / 10 || rev > INT_MAX / 10) {
//                return 0;
//            }
//            int digit = x % 10;
//            x /= 10;
//            rev = rev * 10 + digit;
//        }
//        return rev;
//    }
//};
//class Solution {
//private:
//    // 极大值
//    // 选择 INT_MAX / 2 的原因是防止整数相加溢出
//    static constexpr int INFTY = INT_MAX / 2;
//
//public:
//    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
//        // 将颜色调整为从 0 开始编号，没有被涂色标记为 -1
//        for (int& c : houses) {
//            --c;
//        }
//
//        // dp 所有元素初始化为极大值
//        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(target, INFTY)));
//
//        for (int i = 0; i < m; ++i) {
//            for (int j = 0; j < n; ++j) {
//                if (houses[i] != -1 && houses[i] != j) {
//                    continue;
//                }
//
//                for (int k = 0; k < target; ++k) {
//                    for (int j0 = 0; j0 < n; ++j0) {
//                        if (j == j0) {
//                            if (i == 0) {
//                                if (k == 0) {
//                                    dp[i][j][k] = 0;
//                                }
//                            }
//                            else {
//                                dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
//                            }
//                        }
//                        else if (i > 0 && k > 0) {
//                            dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j0][k - 1]);
//                        }
//                    }
//
//                    if (dp[i][j][k] != INFTY && houses[i] == -1) {
//                        dp[i][j][k] += cost[i][j];
//                    }
//                }
//            }
//        }
//
//        int ans = INFTY;
//        for (int j = 0; j < n; ++j) {
//            ans = min(ans, dp[m - 1][j][target - 1]);
//        }
//        return ans == INFTY ? -1 : ans;
//    }
//};
//class Solution {
//private:
//    int rob(vector<int>& nums) {
//        int size = nums.size();
//        int first = nums[0], second = max(nums[0], nums[1]);
//        for (int i = 2; i < size; i++) {
//            int temp = second;
//            second = max(first + nums[i], second);
//            first = temp;
//        }
//        return second;
//    }
//
//public:
//    int deleteAndEarn(vector<int>& nums) {
//        int maxVal = 0;
//        for (int val : nums) {
//            maxVal = max(maxVal, val);
//        }
//        vector<int> sum(maxVal + 1);
//        for (int val : nums) {
//            sum[val] += val;
//        }
//        return rob(sum);
//    }
//};
