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
//
//class may
//{
//public:
//	may();
//	~may();
//
//private:
//	void tt(int n);
//};
//
//may::may()
//{
//}
//
//may::~may()
//{
//}
//
//void may::tt(int n)
//{
//	 n = 0;
//}
//class Solution {
//private:
//    unordered_map<char, int> symbolValues = {
//        {'I', 1},
//        {'V', 5},
//        {'X', 10},
//        {'L', 50},
//        {'C', 100},
//        {'D', 500},
//        {'M', 1000},
//    };
//
//public:
//    int romanToInt(string s) {
//        int ans = 0;
//        int n = s.length();
//        for (int i = 0; i < n; ++i) {
//            int value = symbolValues[s[i]];
//            if (i < n - 1 && value < symbolValues[s[i + 1]]) {
//                ans -= value;
//            }
//            else {
//                ans += value;
//            }
//        }
//        return ans;
//    }
//}; class Solution {
//private:
//    // 最高位的二进制位编号为 30
//    static constexpr int HIGH_BIT = 30;
//
//public:
//    int findMaximumXOR(vector<int>& nums) {
//        int x = 0;
//        for (int k = HIGH_BIT; k >= 0; --k) {
//            unordered_set<int> seen;
//            // 将所有的 pre^k(a_j) 放入哈希表中
//            for (int num : nums) {
//                // 如果只想保留从最高位开始到第 k 个二进制位为止的部分
//                // 只需将其右移 k 位
//                seen.insert(num >> k);
//            }
//
//            // 目前 x 包含从最高位开始到第 k+1 个二进制位为止的部分
//            // 我们将 x 的第 k 个二进制位置为 1，即为 x = x*2+1
//            int x_next = x * 2 + 1;
//            bool found = false;
//
//            // 枚举 i
//            for (int num : nums) {
//                if (seen.count(x_next ^ (num >> k))) {
//                    found = true;
//                    break;
//                }
//            }
//
//            if (found) {
//                x = x_next;
//            }
//            else {
//                // 如果没有找到满足等式的 a_i 和 a_j，那么 x 的第 k 个二进制位只能为 0
//                // 即为 x = x*2
//                x = x_next - 1;
//            }
//        }
//        return x;
//    }
//};
//class Solution {
//private:
//    // x 的信息
//    int x;
//    TreeNode* x_parent;
//    int x_depth;
//    bool x_found = false;
//
//    // y 的信息
//    int y;
//    TreeNode* y_parent;
//    int y_depth;
//    bool y_found = false;
//
//public:
//    void dfs(TreeNode* node, int depth, TreeNode* parent) {
//        if (!node) {
//            return;
//        }
//
//        if (node->val == x) {
//            tie(x_parent, x_depth, x_found) = tuple{ parent, depth, true };
//        }
//        else if (node->val == y) {
//            tie(y_parent, y_depth, y_found) = tuple{ parent, depth, true };
//        }
//
//        // 如果两个节点都找到了，就可以提前退出遍历
//        // 即使不提前退出，对最坏情况下的时间复杂度也不会有影响
//        if (x_found && y_found) {
//            return;
//        }
//
//        dfs(node->left, depth + 1, node);
//
//        if (x_found && y_found) {
//            return;
//        }
//
//        dfs(node->right, depth + 1, node);
//    }
//
//    bool isCousins(TreeNode* root, int x, int y) {
//        this->x = x;
//        this->y = y;
//        dfs(root, 0, nullptr);
//        return x_depth == y_depth && x_parent != y_parent;
//    }
//};
//class Solution {
//public:
//    int countTriplets(vector<int>& arr) {
//        int n = arr.size();
//        vector<int> s(n + 1);
//        for (int i = 0; i < n; ++i) {
//            s[i + 1] = s[i] ^ arr[i];
//        }
//        int ans = 0;
//        for (int i = 0; i < n; ++i) {
//            for (int j = i + 1; j < n; ++j) {
//                for (int k = j; k < n; ++k) {
//                    if (s[i] == s[k + 1]) {
//                        ++ans;
//                    }
//                }
//            }
//        }
//        return ans;
//    }
//};
//class Solution {
//public:
//    int kthLargestValue(vector<vector<int>>& matrix, int k) {
//        int m = matrix.size(), n = matrix[0].size();
//        vector<vector<int>> pre(m + 1, vector<int>(n + 1));
//        vector<int> results;
//        for (int i = 1; i <= m; ++i) {
//            for (int j = 1; j <= n; ++j) {
//                pre[i][j] = pre[i - 1][j] ^ pre[i][j - 1] ^ pre[i - 1][j - 1] ^ matrix[i - 1][j - 1];
//                results.push_back(pre[i][j]);
//            }
//        }
//
//        sort(results.begin(), results.end(), greater<int>());
//        return results[k - 1];
//    }
//};
//class Solution {
//public:
//    vector<string> topKFrequent(vector<string>& words, int k) {
//        unordered_map<string, int> cnt;
//        for (auto& word : words) {
//            ++cnt[word];
//        }
//        vector<string> rec;
//        for (auto& [key, value] : cnt) {
//            rec.emplace_back(key);
//        }
//        sort(rec.begin(), rec.end(), [&](const string& a, const string& b) -> bool {
//            return cnt[a] == cnt[b] ? a < b : cnt[a] > cnt[b];
//            });
//        rec.erase(rec.begin() + k, rec.end());
//        return rec;
//    }
//};
//class Solution {
//public:
//    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
//        int m = nums1.size(), n = nums2.size();
//        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
//        for (int i = 1; i <= m; i++) {
//            int num1 = nums1[i - 1];
//            for (int j = 1; j <= n; j++) {
//                int num2 = nums2[j - 1];
//                if (num1 == num2) {
//                    dp[i][j] = dp[i - 1][j - 1] + 1;
//                }
//                else {
//                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//                }
//            }
//        }
//        return dp[m][n];
//    }
//};
//class Solution {
//public:
//    bool xorGame(vector<int>& nums) {
//        if (nums.size() % 2 == 0) {
//            return true;
//        }
//        int xorsum = 0;
//        for (int num : nums) {
//            xorsum ^= num;
//        }
//        return xorsum == 0;
//    }
//};
//class Trie {
//public:
//    const int L = 30;
//
//    Trie* children[2] = {};
//
//    void insert(int val) {
//        Trie* node = this;
//        for (int i = L - 1; i >= 0; --i) {
//            int bit = (val >> i) & 1;
//            if (node->children[bit] == nullptr) {
//                node->children[bit] = new Trie();
//            }
//            node = node->children[bit];
//        }
//    }
//
//    int getMaxXor(int val) {
//        int ans = 0;
//        Trie* node = this;
//        for (int i = L - 1; i >= 0; --i) {
//            int bit = (val >> i) & 1;
//            if (node->children[bit ^ 1] != nullptr) {
//                ans |= 1 << i;
//                bit ^= 1;
//            }
//            node = node->children[bit];
//        }
//        return ans;
//    }
//};
//
//class Solution {
//public:
//    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
//        sort(nums.begin(), nums.end());
//        int numQ = queries.size();
//        for (int i = 0; i < numQ; ++i) {
//            queries[i].push_back(i);
//        }
//        sort(queries.begin(), queries.end(), [](auto& x, auto& y) { return x[1] < y[1]; });
//
//        vector<int> ans(numQ);
//        Trie* t = new Trie();
//        int idx = 0, n = nums.size();
//        for (auto& q : queries) {
//            int x = q[0], m = q[1], qid = q[2];
//            while (idx < n && nums[idx] <= m) {
//                t->insert(nums[idx]);
//                ++idx;
//            }
//            if (idx == 0) { // 字典树为空
//                ans[qid] = -1;
//            }
//            else {
//                ans[qid] = t->getMaxXor(x);
//            }
//        }
//        return ans;
//    }
//};
//class Solution {
//public:
//    int strangePrinter(string s) {
//        int n = s.length();
//        vector<vector<int>> f(n, vector<int>(n));
//        for (int i = n - 1; i >= 0; i--) {
//            f[i][i] = 1;
//            for (int j = i + 1; j < n; j++) {
//                if (s[i] == s[j]) {
//                    f[i][j] = f[i][j - 1];
//                }
//                else {
//                    int minn = INT_MAX;
//                    for (int k = i; k < j; k++) {
//                        minn = min(minn, f[i][k] + f[k + 1][j]);
//                    }
//                    f[i][j] = minn;
//                }
//            }
//        }
//        return f[0][n - 1];
//    }
//};
//class Solution {
//private:
//    // x 的范围为 [0, 2^10)
//    static constexpr int MAXX = 1 << 10;
//    // 极大值，为了防止整数溢出选择 INT_MAX / 2
//    static constexpr int INFTY = INT_MAX / 2;
//
//public:
//    int minChanges(vector<int>& nums, int k) {
//        int n = nums.size();
//        vector<int> f(MAXX, INFTY);
//        // 边界条件 f(-1,0)=0
//        f[0] = 0;
//
//        for (int i = 0; i < k; ++i) {
//            // 第 i 个组的哈希映射
//            unordered_map<int, int> cnt;
//            int size = 0;
//            for (int j = i; j < n; j += k) {
//                ++cnt[nums[j]];
//                ++size;
//            }
//
//            // 求出 t2
//            int t2min = *min_element(f.begin(), f.end());
//
//            vector<int> g(MAXX, t2min);
//            for (int mask = 0; mask < MAXX; ++mask) {
//                // t1 则需要枚举 x 才能求出
//                for (auto [x, countx] : cnt) {
//                    g[mask] = min(g[mask], f[mask ^ x] - countx);
//                }
//            }
//
//            // 别忘了加上 size
//            for_each(g.begin(), g.end(), [&](int& val) {val += size; });
//            f = move(g);
//        }
//
//        return f[0];
//    }
//};
//class Solution {
//public:
//    string reverseParentheses(string s) {
//        stack<string> stk;
//        string str;
//        for (auto& ch : s) {
//            if (ch == '(') {
//                stk.push(str);
//                str = "";
//            }
//            else if (ch == ')') {
//                reverse(str.begin(), str.end());
//                str = stk.top() + str;
//                stk.pop();
//            }
//            else {
//                str.push_back(ch);
//            }
//        }
//        return str;
//    }
//};
//class Solution {
//public:
//    int hammingDistance(int x, int y) {
//        return __builtin_popcount(x ^ y);
//    }
//};
//class Solution {
//public:
//    int totalHammingDistance(vector<int>& nums) {
//        int ans = 0, n = nums.size();
//        for (int i = 0; i < 30; ++i) {
//            int c = 0;
//            for (int val : nums) {
//                c += (val >> i) & 1;
//            }
//            ans += c * (n - c);
//        }
//        return ans;
//    }
//};
//class Solution {
//private:
//    int subarraySum(vector<int>& nums, int k) {
//        unordered_map<int, int> mp;
//        mp[0] = 1;
//        int count = 0, pre = 0;
//        for (auto& x : nums) {
//            pre += x;
//            if (mp.find(pre - k) != mp.end()) {
//                count += mp[pre - k];
//            }
//            mp[pre]++;
//        }
//        return count;
//    }
//
//public:
//    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
//        int ans = 0;
//        int m = matrix.size(), n = matrix[0].size();
//        for (int i = 0; i < m; ++i) { // 枚举上边界
//            vector<int> sum(n);
//            for (int j = i; j < m; ++j) { // 枚举下边界
//                for (int c = 0; c < n; ++c) {
//                    sum[c] += matrix[j][c]; // 更新每列的元素和
//                }
//                ans += subarraySum(sum, target);
//            }
//        }
//        return ans;
//    }
//};
//class Solution {
//public:
//    bool isPowerOfTwo(int n) {
//        return n > 0 && (n & -n) == n;
//    }
//};
//class Solution {
//public:
//    bool isPowerOfFour(int n) {
//        return n > 0 && (n & (n - 1)) == 0 && (n & 0xaaaaaaaa) == 0;
//    }
//};
//class Solution {
//private:
//    using LL = long long;
//
//public:
//    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
//        int n = candiesCount.size();
//
//        // 前缀和
//        vector<LL> sum(n);
//        sum[0] = candiesCount[0];
//        for (int i = 1; i < n; ++i) {
//            sum[i] = sum[i - 1] + candiesCount[i];
//        }
//
//        vector<bool> ans;
//        for (const auto& q : queries) {
//            int favoriteType = q[0], favoriteDay = q[1], dailyCap = q[2];
//
//            LL x1 = favoriteDay + 1;
//            LL y1 = (LL)(favoriteDay + 1) * dailyCap;
//            LL x2 = (favoriteType == 0 ? 1 : sum[favoriteType - 1] + 1);
//            LL y2 = sum[favoriteType];
//
//            ans.push_back(!(x1 > y2 || y1 < x2));
//        }
//        return ans;
//    }
//};
//class Solution {
//public:
//    bool checkSubarraySum(vector<int>& nums, int k) {
//        int m = nums.size();
//        if (m < 2) {
//            return false;
//        }
//        unordered_map<int, int> mp;
//        mp[0] = -1;
//        int remainder = 0;
//        for (int i = 0; i < m; i++) {
//            remainder = (remainder + nums[i]) % k;
//            if (mp.count(remainder)) {
//                int prevIndex = mp[remainder];
//                if (i - prevIndex >= 2) {
//                    return true;
//                }
//            }
//            else {
//                mp[remainder] = i;
//            }
//        }
//        return false;
//    }
//};
//class Solution {
//public:
//    int findMaxLength(vector<int>& nums) {
//        int maxLength = 0;
//        unordered_map<int, int> mp;
//        int counter = 0;
//        mp[counter] = -1;
//        int n = nums.size();
//        for (int i = 0; i < n; i++) {
//            int num = nums[i];
//            if (num == 1) {
//                counter++;
//            }
//            else {
//                counter--;
//            }
//            if (mp.count(counter)) {
//                int prevIndex = mp[counter];
//                maxLength = max(maxLength, i - prevIndex);
//            }
//            else {
//                mp[counter] = i;
//            }
//        }
//        return maxLength;
//    }
//};
//class Solution {
//public:
//    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
//        unordered_set<ListNode*> visited;
//        ListNode* temp = headA;
//        while (temp != nullptr) {
//            visited.insert(temp);
//            temp = temp->next;
//        }
//        temp = headB;
//        while (temp != nullptr) {
//            if (visited.count(temp)) {
//                return temp;
//            }
//            temp = temp->next;
//        }
//        return nullptr;
//    }
//};
//class Solution {
//public:
//    ListNode* removeElements(ListNode* head, int val) {
//        if (head == nullptr) {
//            return head;
//        }
//        head->next = removeElements(head->next, val);
//        return head->val == val ? head->next : head;
//    }
//};
//class Solution {
//public:
//    vector<int> getZerosOnes(string& str) {
//        vector<int> zerosOnes(2);
//        int length = str.length();
//        for (int i = 0; i < length; i++) {
//            zerosOnes[str[i] - '0']++;
//        }
//        return zerosOnes;
//    }
//
//    int findMaxForm(vector<string>& strs, int m, int n) {
//        int length = strs.size();
//        vector<vector<vector<int>>> dp(length + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));
//        for (int i = 1; i <= length; i++) {
//            vector<int>&& zerosOnes = getZerosOnes(strs[i - 1]);
//            int zeros = zerosOnes[0], ones = zerosOnes[1];
//            for (int j = 0; j <= m; j++) {
//                for (int k = 0; k <= n; k++) {
//                    dp[i][j][k] = dp[i - 1][j][k];
//                    if (j >= zeros && k >= ones) {
//                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - zeros][k - ones] + 1);
//                    }
//                }
//            }
//        }
//        return dp[length][m][n];
//    }
//};
//class Solution {
//public:
//    int count = 0;
//
//    int findTargetSumWays(vector<int>& nums, int target) {
//        backtrack(nums, target, 0, 0);
//        return count;
//    }
//
//    void backtrack(vector<int>& nums, int target, int index, int sum) {
//        if (index == nums.size()) {
//            if (sum == target) {
//                count++;
//            }
//        }
//        else {
//            backtrack(nums, target, index + 1, sum + nums[index]);
//            backtrack(nums, target, index + 1, sum - nums[index]);
//        }
//    }
//};
// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         vector<int> dp(amount + 1);
//         dp[0] = 1;
//         for (int& coin : coins) {
//             for (int i = coin; i <= amount; i++) {
//                 dp[i] += dp[i - coin];
//             }
//         }
//         return dp[amount];
//     }
// };
// class Solution {
// public:
//     int numSquares(int n) {
//         vector<int> f(n + 1);
//         for (int i = 1; i <= n; i++) {
//             int minn = INT_MAX;
//             for (int j = 1; j * j <= i; j++) {
//                 minn = min(minn, f[i - j * j]);
//             }
//             f[i] = minn + 1;
//         }
//         return f[n];
//     }
// };
// class Solution {
// public:
//     int firstBadVersion(int n) {
//         int left = 1, right = n;
//         while (left < right) { // 循环直至区间左右端点相同
//             int mid = left + (right - left) / 2; // 防止计算时溢出
//             if (isBadVersion(mid)) {
//                 right = mid; // 答案在区间 [left, mid] 中
//             } else {
//                 left = mid + 1; // 答案在区间 [mid+1, right] 中
//             }
//         }
//         // 此时有 left == right，区间缩为一个点，即为答案
//         return left;
//     }
// };
//class Solution {
//public:
//    int peakIndexInMountainArray(vector<int>& arr) {
//        int n = arr.size();
//        int ans = -1;
//        for (int i = 1; i < n - 1; ++i) {
//            if (arr[i] > arr[i + 1]) {
//                ans = i;
//                break;
//            }
//        }
//        return ans;
//    }
//};
//class Solution {
//public:
//    vector<string> readBinaryWatch(int turnedOn) {
//        vector<string> ans;
//        for (int i = 0; i < 1024; ++i) {
//            int h = i >> 6, m = i & 63; // 用位运算取出高 4 位和低 6 位
//            if (h < 12 && m < 60 && __builtin_popcount(i) == turnedOn) {
//                ans.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
//            }
//        }
//        return ans;
//    }
//};



