////class Solution {
////public:
////    int reverse(int x) {
////        int rev = 0;
////        while (x != 0) {
////            if (rev < INT_MIN / 10 || rev > INT_MAX / 10) {
////                return 0;
////            }
////            int digit = x % 10;
////            x /= 10;
////            rev = rev * 10 + digit;
////        }
////        return rev;
////    }
////};
////class Solution {
////private:
////    // 极大值
////    // 选择 INT_MAX / 2 的原因是防止整数相加溢出
////    static constexpr int INFTY = INT_MAX / 2;
////
////public:
////    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
////        // 将颜色调整为从 0 开始编号，没有被涂色标记为 -1
////        for (int& c : houses) {
////            --c;
////        }
////
////        // dp 所有元素初始化为极大值
////        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(target, INFTY)));
////
////        for (int i = 0; i < m; ++i) {
////            for (int j = 0; j < n; ++j) {
////                if (houses[i] != -1 && houses[i] != j) {
////                    continue;
////                }
////
////                for (int k = 0; k < target; ++k) {
////                    for (int j0 = 0; j0 < n; ++j0) {
////                        if (j == j0) {
////                            if (i == 0) {
////                                if (k == 0) {
////                                    dp[i][j][k] = 0;
////                                }
////                            }
////                            else {
////                                dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
////                            }
////                        }
////                        else if (i > 0 && k > 0) {
////                            dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j0][k - 1]);
////                        }
////                    }
////
////                    if (dp[i][j][k] != INFTY && houses[i] == -1) {
////                        dp[i][j][k] += cost[i][j];
////                    }
////                }
////            }
////        }
////
////        int ans = INFTY;
////        for (int j = 0; j < n; ++j) {
////            ans = min(ans, dp[m - 1][j][target - 1]);
////        }
////        return ans == INFTY ? -1 : ans;
////    }
////};
////class Solution {
////private:
////    int rob(vector<int>& nums) {
////        int size = nums.size();
////        int first = nums[0], second = max(nums[0], nums[1]);
////        for (int i = 2; i < size; i++) {
////            int temp = second;
////            second = max(first + nums[i], second);
////            first = temp;
////        }
////        return second;
////    }
////
////public:
////    int deleteAndEarn(vector<int>& nums) {
////        int maxVal = 0;
////        for (int val : nums) {
////            maxVal = max(maxVal, val);
////        }
////        vector<int> sum(maxVal + 1);
////        for (int val : nums) {
////            sum[val] += val;
////        }
////        return rob(sum);
////    }
////};
////class Solution {
////public:
////    vector<int> decode(vector<int>& encoded, int first) {
////        int n = encoded.size() + 1;
////        vector<int> arr(n);
////        arr[0] = first;
////        for (int i = 1; i < n; i++) {
////            arr[i] = arr[i - 1] ^ encoded[i - 1];
////        }
////        return arr;
////    }
////};
////class Solution {
////public:
////    int xorOperation(int n, int start) {
////        int ans = 0;
////        for (int i = 0; i < n; ++i) {
////            ans ^= (start + i * 2);
////        }
////        return ans;
////    }
////};
////class Solution {
////public:
////    bool backtrack(vector<int>& jobs, vector<int>& workloads, int idx, int limit) {
////        if (idx >= jobs.size()) {
////            return true;
////        }
////        int cur = jobs[idx];
////        for (auto& workload : workloads) {
////            if (workload + cur <= limit) {
////                workload += cur;
////                if (backtrack(jobs, workloads, idx + 1, limit)) {
////                    return true;
////                }
////                workload -= cur;
////            }
////            // 如果当前工人未被分配工作，那么下一个工人也必然未被分配工作
////            // 或者当前工作恰能使该工人的工作量达到了上限
////            // 这两种情况下我们无需尝试继续分配工作
////            if (workload == 0 || workload + cur == limit) {
////                break;
////            }
////        }
////        return false;
////    }
////
////    bool check(vector<int>& jobs, int k, int limit) {
////        vector<int> workloads(k, 0);
////        return backtrack(jobs, workloads, 0, limit);
////    }
////
////    int minimumTimeRequired(vector<int>& jobs, int k) {
////        sort(jobs.begin(), jobs.end(), greater<int>());
////        int l = jobs[0], r = accumulate(jobs.begin(), jobs.end(), 0);
////        while (l < r) {
////            int mid = (l + r) >> 1;
////            if (check(jobs, k, mid)) {
////                r = mid;
////            }
////            else {
////                l = mid + 1;
////            }
////        }
////        return l;
////    }
////};
////class Solution {
////public:
////    int minDays(vector<int>& bloomDay, int m, int k) {
////        if (m > bloomDay.size() / k) {
////            return -1;
////        }
////        int low = INT_MAX, high = 0;
////        int length = bloomDay.size();
////        for (int i = 0; i < length; i++) {
////            low = min(low, bloomDay[i]);
////            high = max(high, bloomDay[i]);
////        }
////        while (low < high) {
////            int days = (high - low) / 2 + low;
////            if (canMake(bloomDay, days, m, k)) {
////                high = days;
////            }
////            else {
////                low = days + 1;
////            }
////        }
////        return low;
////    }
////
////    bool canMake(vector<int>& bloomDay, int days, int m, int k) {
////        int bouquets = 0;
////        int flowers = 0;
////        int length = bloomDay.size();
////        for (int i = 0; i < length && bouquets < m; i++) {
////            if (bloomDay[i] <= days) {
////                flowers++;
////                if (flowers == k) {
////                    bouquets++;
////                    flowers = 0;
////                }
////            }
////            else {
////                flowers = 0;
////            }
////        }
////        return bouquets >= m;
////    }
////};
////class Solution {
////public:
////    void dfs(TreeNode* node, vector<int>& seq) {
////        if (!node->left && !node->right) {
////            seq.push_back(node->val);
////        }
////        else {
////            if (node->left) {
////                dfs(node->left, seq);
////            }
////            if (node->right) {
////                dfs(node->right, seq);
////            }
////        }
////    }
////
////    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
////        vector<int> seq1;
////        if (root1) {
////            dfs(root1, seq1);
////        }
////
////        vector<int> seq2;
////        if (root2) {
////            dfs(root2, seq2);
////        }
////
////        return seq1 == seq2;
////    }
////};
//
//#define ； ;
//#define  itn  int;
//
//class MyClass
//{
//public:
//	MyClass();
//	~MyClass();
//private:
//
//};
//
//MyClass::MyClass()
//{
//}
//
//MyClass::~MyClass()
//{
//}class Solution {
//public:
//    vector<int> decode(vector<int>& encoded) {
//        int n = encoded.size() + 1;
//        int total = 0;
//        for (int i = 1; i <= n; i++) {
//            total ^= i;
//        }
//        int odd = 0;
//        for (int i = 1; i < n - 1; i += 2) {
//            odd ^= encoded[i];
//        }
//        vector<int> perm(n);
//        perm[0] = total ^ odd;
//        for (int i = 0; i < n - 1; i++) {
//            perm[i + 1] = perm[i] ^ encoded[i];
//        }
//        return perm;
//    }
//};
//class Solution {
//public:
//    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
//        int n = arr.size();
//        vector<int> xors(n + 1);
//        for (int i = 0; i < n; i++) {
//            xors[i + 1] = xors[i] ^ arr[i];
//        }
//        int m = queries.size();
//        vector<int> ans(m);
//        for (int i = 0; i < m; i++) {
//            ans[i] = xors[queries[i][0]] ^ xors[queries[i][1] + 1];
//        }
//        return ans;
//    }
//};
//class Solution {
//public:
//    const int MODULO = 1000000007;
//
//    int numWays(int steps, int arrLen) {
//        int maxColumn = min(arrLen - 1, steps);
//        vector<vector<int>> dp(steps + 1, vector<int>(maxColumn + 1));
//        dp[0][0] = 1;
//        for (int i = 1; i <= steps; i++) {
//            for (int j = 0; j <= maxColumn; j++) {
//                dp[i][j] = dp[i - 1][j];
//                if (j - 1 >= 0) {
//                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MODULO;
//                }
//                if (j + 1 <= maxColumn) {
//                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MODULO;
//                }
//            }
//        }
//        return dp[steps][0];
//    }
//};
//const pair<int, string> valueSymbols[] = {
//    {1000, "M"},
//    {900,  "CM"},
//    {500,  "D"},
//    {400,  "CD"},
//    {100,  "C"},
//    {90,   "XC"},
//    {50,   "L"},
//    {40,   "XL"},
//    {10,   "X"},
//    {9,    "IX"},
//    {5,    "V"},
//    {4,    "IV"},
//    {1,    "I"},
//};
//
//class Solution {
//public:
//    string intToRoman(int num) {
//        string roman;
//        for (const auto& [value, symbol] : valueSymbols) {
//            while (num >= value) {
//                num -= value;
//                roman += symbol;
//            }
//            if (num == 0) {
//                break;
//            }
//        }
//        return roman;
//    }
//};
