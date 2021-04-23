#include "April.h"

//class Solution {
//public:
//    int clumsy(int N) {
//        stack<int> stk;
//        stk.push(N);
//        N--;
//
//        int index = 0; // 用于控制乘、除、加、减
//        while (N > 0) {
//            if (index % 4 == 0) {
//                stk.top() *= N;
//            }
//            else if (index % 4 == 1) {
//                stk.top() /= N;
//            }
//            else if (index % 4 == 2) {
//                stk.push(N);
//            }
//            else {
//                stk.push(-N);
//            }
//            index++;
//            N--;
//        }
//
//        // 把栈中所有的数字依次弹出求和
//        int sum = 0;
//        while (!stk.empty()) {
//            sum += stk.top();
//            stk.pop();
//        }
//        return sum;
//    }
//};
//class Solution {
//public:
//    int trap(vector<int>& height) {
//        int n = height.size();
//        if (n == 0) {
//            return 0;
//        }
//        vector<int> leftMax(n);
//        leftMax[0] = height[0];
//        for (int i = 1; i < n; ++i) {
//            leftMax[i] = max(leftMax[i - 1], height[i]);
//        }
//
//        vector<int> rightMax(n);
//        rightMax[n - 1] = height[n - 1];
//        for (int i = n - 2; i >= 0; --i) {
//            rightMax[i] = max(rightMax[i + 1], height[i]);
//        }
//
//        int ans = 0;
//        for (int i = 0; i < n; ++i) {
//            ans += min(leftMax[i], rightMax[i]) - height[i];
//        }
//        return ans;
//    }
//};
//class Solution {
//public:
//    int numRabbits(vector<int>& answers) {
//        unordered_map<int, int> count;
//        for (int y : answers) {
//            ++count[y];
//        }
//        int ans = 0;
//        for (auto& [y, x] : count) {
//            ans += (x + y) / (y + 1) * (y + 1);
//        }
//        return ans;
//    }
//};
//class Solution {
//public:
//    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//        for (int i = 0; i != n; ++i) {
//            nums1[m + i] = nums2[i];
//        }
//        sort(nums1.begin(), nums1.end());
//    }
//};
//class Solution {
//public:
//    int removeDuplicates(vector<int>& nums) {
//        int n = nums.size();
//        if (n <= 2) {
//            return n;
//        }
//        int slow = 2, fast = 2;
//        while (fast < n) {
//            if (nums[slow - 2] != nums[fast]) {
//                nums[slow] = nums[fast];
//                ++slow;
//            }
//            ++fast;
//        }
//        return slow;
//    }
//};
//class Solution {
//public:
//    bool search(vector<int>& nums, int target) {
//        int n = nums.size();
//        if (n == 0) {
//            return false;
//        }
//        if (n == 1) {
//            return nums[0] == target;
//        }
//        int l = 0, r = n - 1;
//        while (l <= r) {
//            int mid = (l + r) / 2;
//            if (nums[mid] == target) {
//                return true;
//            }
//            if (nums[l] == nums[mid] && nums[mid] == nums[r]) {
//                ++l;
//                --r;
//            }
//            else if (nums[l] <= nums[mid]) {
//                if (nums[l] <= target && target < nums[mid]) {
//                    r = mid - 1;
//                }
//                else {
//                    l = mid + 1;
//                }
//            }
//            else {
//                if (nums[mid] < target && target <= nums[n - 1]) {
//                    l = mid + 1;
//                }
//                else {
//                    r = mid - 1;
//                }
//            }
//        }
//        return false;
//    }
//};
//class Solution {
//public:
//    int findMin(vector<int>& nums) {
//        int low = 0;
//        int high = nums.size() - 1;
//        while (low < high) {
//            int pivot = low + (high - low) / 2;
//            if (nums[pivot] < nums[high]) {
//                high = pivot;
//            }
//            else {
//                low = pivot + 1;
//            }
//        }
//        return nums[low];
//    }
//};
//class Solution {
//public:
//    int findMin(vector<int>& nums) {
//        int low = 0;
//        int high = nums.size() - 1;
//        while (low < high) {
//            int pivot = low + (high - low) / 2;
//            if (nums[pivot] < nums[high]) {
//                high = pivot;
//            }
//            else if (nums[pivot] > nums[high]) {
//                low = pivot + 1;
//            }
//            else {
//                high -= 1;
//            }
//        }
//        return nums[low];
//    }
//};
//class Solution {
//public:
//    bool isUgly(int n) {
//        if (n <= 0) {
//            return false;
//        }
//        vector<int> factors = { 2, 3, 5 };
//        for (int factor : factors) {
//            while (n % factor == 0) {
//                n /= factor;
//            }
//        }
//        return n == 1;
//    }
//};
//class Solution {
//public:
//    int nthUglyNumber(int n) {
//        vector<int> factors = { 2, 3, 5 };
//        unordered_set<long> seen;
//        priority_queue<long, vector<long>, greater<long>> heap;
//        seen.insert(1L);
//        heap.push(1L);
//        int ugly = 0;
//        for (int i = 0; i < n; i++) {
//            long curr = heap.top();
//            heap.pop();
//            ugly = (int)curr;
//            for (int factor : factors) {
//                long next = curr * factor;
//                if (!seen.count(next)) {
//                    seen.insert(next);
//                    heap.push(next);
//                }
//            }
//        }
//        return ugly;
//    }
//};
//class Solution {
//public:
//    string largestNumber(vector<int>& nums) {
//        sort(nums.begin(), nums.end(), [](const int& x, const int& y) {
//            long sx = 10, sy = 10;
//            while (sx <= x) {
//                sx *= 10;
//            }
//            while (sy <= y) {
//                sy *= 10;
//            }
//            return sy * x + y > sx * y + x;
//            });
//        if (nums[0] == 0) {
//            return "0";
//        }
//        string ret;
//        for (int& x : nums) {
//            ret += to_string(x);
//        }
//        return ret;
//    }
//};
//class Solution {
//public:
//    void dfs(TreeNode* root, int& pre, int& ans) {
//        if (root == nullptr) {
//            return;
//        }
//        dfs(root->left, pre, ans);
//        if (pre == -1) {
//            pre = root->val;
//        }
//        else {
//            ans = min(ans, root->val - pre);
//            pre = root->val;
//        }
//        dfs(root->right, pre, ans);
//    }
//    int minDiffInBST(TreeNode* root) {
//        int ans = INT_MAX, pre = -1;
//        dfs(root, pre, ans);
//        return ans;
//    }
//};
//class Trie {
//private:
//    vector<Trie*> children;
//    bool isEnd;
//
//    Trie* searchPrefix(string prefix) {
//        Trie* node = this;
//        for (char ch : prefix) {
//            ch -= 'a';
//            if (node->children[ch] == nullptr) {
//                return nullptr;
//            }
//            node = node->children[ch];
//        }
//        return node;
//    }
//
//public:
//    Trie() : children(26), isEnd(false) {}
//
//    void insert(string word) {
//        Trie* node = this;
//        for (char ch : word) {
//            ch -= 'a';
//            if (node->children[ch] == nullptr) {
//                node->children[ch] = new Trie();
//            }
//            node = node->children[ch];
//        }
//        node->isEnd = true;
//    }
//
//    bool search(string word) {
//        Trie* node = this->searchPrefix(word);
//        return node != nullptr && node->isEnd;
//    }
//
//    bool startsWith(string prefix) {
//        return this->searchPrefix(prefix) != nullptr;
//    }
//};
//
//class Solution {
//public:
//    int robRange(vector<int>& nums, int start, int end) {
//        int first = nums[start], second = max(nums[start], nums[start + 1]);
//        for (int i = start + 2; i <= end; i++) {
//            int temp = second;
//            second = max(first + nums[i], second);
//            first = temp;
//        }
//        return second;
//    }
//
//    int rob(vector<int>& nums) {
//        int length = nums.size();
//        if (length == 1) {
//            return nums[0];
//        }
//        else if (length == 2) {
//            return max(nums[0], nums[1]);
//        }
//        return max(robRange(nums, 0, length - 2), robRange(nums, 1, length - 1));
//    }
//};
//class Solution {
//private:
//    // 记忆化搜索存储状态的数组
//    // -1 表示 false，1 表示 true，0 表示未计算
//    int memo[30][30][31];
//    string s1, s2;
//
//public:
//    bool checkIfSimilar(int i1, int i2, int length) {
//        unordered_map<int, int> freq;
//        for (int i = i1; i < i1 + length; ++i) {
//            ++freq[s1[i]];
//        }
//        for (int i = i2; i < i2 + length; ++i) {
//            --freq[s2[i]];
//        }
//        if (any_of(freq.begin(), freq.end(), [](const auto& entry) {return entry.second != 0; })) {
//            return false;
//        }
//        return true;
//    }
//
//    // 第一个字符串从 i1 开始，第二个字符串从 i2 开始，子串的长度为 length，是否和谐
//    bool dfs(int i1, int i2, int length) {
//        if (memo[i1][i2][length]) {
//            return memo[i1][i2][length] == 1;
//        }
//
//        // 判断两个子串是否相等
//        if (s1.substr(i1, length) == s2.substr(i2, length)) {
//            memo[i1][i2][length] = 1;
//            return true;
//        }
//
//        // 判断是否存在字符 c 在两个子串中出现的次数不同
//        if (!checkIfSimilar(i1, i2, length)) {
//            memo[i1][i2][length] = -1;
//            return false;
//        }
//
//        // 枚举分割位置
//        for (int i = 1; i < length; ++i) {
//            // 不交换的情况
//            if (dfs(i1, i2, i) && dfs(i1 + i, i2 + i, length - i)) {
//                memo[i1][i2][length] = 1;
//                return true;
//            }
//            // 交换的情况
//            if (dfs(i1, i2 + length - i, i) && dfs(i1 + i, i2, length - i)) {
//                memo[i1][i2][length] = 1;
//                return true;
//            }
//        }
//
//        memo[i1][i2][length] = -1;
//        return false;
//    }
//
//    bool isScramble(string s1, string s2) {
//        memset(memo, 0, sizeof(memo));
//        this->s1 = s1;
//        this->s2 = s2;
//        return dfs(0, 0, s1.size());
//    }
//};
//class Solution {
//public:
//    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
//        int n = nums.size();
//        set<int> rec;
//        for (int i = 0; i < n; i++) {
//            auto iter = rec.lower_bound(max(nums[i], INT_MIN + t) - t);
//            if (iter != rec.end() && *iter <= min(nums[i], INT_MAX - t) + t) {
//                return true;
//            }
//            rec.insert(nums[i]);
//            if (i >= k) {
//                rec.erase(nums[i - k]);
//            }
//        }
//        return false;
//    }
//};
//class Solution {
//public:
//    int removeDuplicates(vector<int>& nums) {
//        int n = nums.size();
//        if (n == 0) {
//            return 0;
//        }
//        int fast = 1, slow = 1;
//        while (fast < n) {
//            if (nums[fast] != nums[fast - 1]) {
//                nums[slow] = nums[fast];
//                ++slow;
//            }
//            ++fast;
//        }
//        return slow;
//    }
//};
//class Solution {
//public:
//    int removeElement(vector<int>& nums, int val) {
//        int n = nums.size();
//        int left = 0;
//        for (int right = 0; right < n; right++) {
//            if (nums[right] != val) {
//                nums[left] = nums[right];
//                left++;
//            }
//        }
//        return left;
//    }
//};
//class Solution {
//public:
//    int strStr(string haystack, string needle) {
//        int n = haystack.size(), m = needle.size();
//        for (int i = 0; i + m <= n; i++) {
//            bool flag = true;
//            for (int j = 0; j < m; j++) {
//                if (haystack[i + j] != needle[j]) {
//                    flag = false;
//                    break;
//                }
//            }
//            if (flag) {
//                return i;
//            }
//        }
//        return -1;
//    }
//};
//class Solution {
//public:
//    int numDecodings(string s) {
//        int n = s.size();
//        vector<int> f(n + 1);
//        f[0] = 1;
//        for (int i = 1; i <= n; ++i) {
//            if (s[i - 1] != '0') {
//                f[i] += f[i - 1];
//            }
//            if (i > 1 && s[i - 2] != '0' && ((s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26)) {
//                f[i] += f[i - 2];
//            }
//        }
//        return f[n];
//    }
//};
//class Solution {
//public:
//    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
//        int ans = INT_MIN;
//        int m = matrix.size(), n = matrix[0].size();
//        for (int i = 0; i < m; ++i) { // 枚举上边界
//            vector<int> sum(n);
//            for (int j = i; j < m; ++j) { // 枚举下边界
//                for (int c = 0; c < n; ++c) {
//                    sum[c] += matrix[j][c]; // 更新每列的元素和
//                }
//                set<int> sumSet{ 0 };
//                int s = 0;
//                for (int v : sum) {
//                    s += v;
//                    auto lb = sumSet.lower_bound(s - k);
//                    if (lb != sumSet.end()) {
//                        ans = max(ans, s - *lb);
//                    }
//                    sumSet.insert(s);
//                }
//            }
//        }
//        return ans;
//    }
//};
//class Solution {
//public:
//    vector<int> largestDivisibleSubset(vector<int>& nums) {
//        int len = nums.size();
//        sort(nums.begin(), nums.end());
//
//        // 第 1 步：动态规划找出最大子集的个数、最大子集中的最大整数
//        vector<int> dp(len, 1);
//        int maxSize = 1;
//        int maxVal = dp[0];
//        for (int i = 1; i < len; i++) {
//            for (int j = 0; j < i; j++) {
//                // 题目中说「没有重复元素」很重要
//                if (nums[i] % nums[j] == 0) {
//                    dp[i] = max(dp[i], dp[j] + 1);
//                }
//            }
//
//            if (dp[i] > maxSize) {
//                maxSize = dp[i];
//                maxVal = nums[i];
//            }
//        }
//
//        // 第 2 步：倒推获得最大子集
//        vector<int> res;
//        if (maxSize == 1) {
//            res.push_back(nums[0]);
//            return res;
//        }
//
//        for (int i = len - 1; i >= 0 && maxSize > 0; i--) {
//            if (dp[i] == maxSize && maxVal % nums[i] == 0) {
//                res.push_back(nums[i]);
//                maxVal = nums[i];
//                maxSize--;
//            }
//        }
//        return res;
//    }
//};
