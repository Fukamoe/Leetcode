#include "February.h"




//class Solution {
//public:
//    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
//        int sumA = accumulate(A.begin(), A.end(), 0);
//        int sumB = accumulate(B.begin(), B.end(), 0);
//        int delta = (sumA - sumB) / 2;
//        unordered_set<int> rec(A.begin(), A.end());
//        vector<int> ans;
//        for (auto& y : B) {
//            int x = y + delta;
//            if (rec.count(x)) {
//                ans = vector<int>{ x, y };
//                break;
//            }
//        }
//        return ans;
//    }
//};
//
//class DualHeap {
//private:
//    // 大根堆，维护较小的一半元素
//    priority_queue<int> small;
//    // 小根堆，维护较大的一半元素
//    priority_queue<int, vector<int>, greater<int>> large;
//    // 哈希表，记录「延迟删除」的元素，key 为元素，value 为需要删除的次数
//    unordered_map<int, int> delayed;
//
//    int k;
//    // small 和 large 当前包含的元素个数，需要扣除被「延迟删除」的元素
//    int smallSize, largeSize;
//
//public:
//    DualHeap(int _k) : k(_k), smallSize(0), largeSize(0) {}
//
//private:
//    // 不断地弹出 heap 的堆顶元素，并且更新哈希表
//    template<typename T>
//    void prune(T& heap) {
//        while (!heap.empty()) {
//            int num = heap.top();
//            if (delayed.count(num)) {
//                --delayed[num];
//                if (!delayed[num]) {
//                    delayed.erase(num);
//                }
//                heap.pop();
//            }
//            else {
//                break;
//            }
//        }
//    }
//
//    // 调整 small 和 large 中的元素个数，使得二者的元素个数满足要求
//    void makeBalance() {
//        if (smallSize > largeSize + 1) {
//            // small 比 large 元素多 2 个
//            large.push(small.top());
//            small.pop();
//            --smallSize;
//            ++largeSize;
//            // small 堆顶元素被移除，需要进行 prune
//            prune(small);
//        }
//        else if (smallSize < largeSize) {
//            // large 比 small 元素多 1 个
//            small.push(large.top());
//            large.pop();
//            ++smallSize;
//            --largeSize;
//            // large 堆顶元素被移除，需要进行 prune
//            prune(large);
//        }
//    }
//
//public:
//    void insert(int num) {
//        if (small.empty() || num <= small.top()) {
//            small.push(num);
//            ++smallSize;
//        }
//        else {
//            large.push(num);
//            ++largeSize;
//        }
//        makeBalance();
//    }
//
//    void erase(int num) {
//        ++delayed[num];
//        if (num <= small.top()) {
//            --smallSize;
//            if (num == small.top()) {
//                prune(small);
//            }
//        }
//        else {
//            --largeSize;
//            if (num == large.top()) {
//                prune(large);
//            }
//        }
//        makeBalance();
//    }
//
//    double getMedian() {
//        return k & 1 ? small.top() : ((double)small.top() + large.top()) / 2;
//    }
//};
//
//class Solution {
//public:
//    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
//        DualHeap dh(k);
//        for (int i = 0; i < k; ++i) {
//            dh.insert(nums[i]);
//        }
//        vector<double> ans = { dh.getMedian() };
//        for (int i = k; i < nums.size(); ++i) {
//            dh.insert(nums[i]);
//            dh.erase(nums[i - k]);
//            ans.push_back(dh.getMedian());
//        }
//        return ans;
//    }
//};
//class Solution {
//public:
//    double findMaxAverage(vector<int>& nums, int k) {
//        int sum = 0;
//        int n = nums.size();
//        for (int i = 0; i < k; i++) {
//            sum += nums[i];
//        }
//        int maxSum = sum;
//        for (int i = k; i < n; i++) {
//            sum = sum - nums[i - k] + nums[i];
//            maxSum = max(maxSum, sum);
//        }
//        return static_cast<double>(maxSum) / k;
//    }
////};
//class Solution {
//public:
//    int binarySearch(const vector<int>& accDiff, int endIndex, int target) {
//        int low = 0, high = endIndex;
//        while (low < high) {
//            int mid = (high - low) / 2 + low;
//            if (accDiff[mid] < target) {
//                low = mid + 1;
//            }
//            else {
//                high = mid;
//            }
//        }
//        return low;
//    }
//
//    int equalSubstring(string s, string t, int maxCost) {
//        int n = s.length();
//        vector<int> accDiff(n + 1, 0);
//        for (int i = 0; i < n; i++) {
//            accDiff[i + 1] = accDiff[i] + abs(s[i] - t[i]);
//        }
//        int maxLength = 0;
//        for (int i = 1; i <= n; i++) {
//            int start = binarySearch(accDiff, i, accDiff[i] - maxCost);
//            maxLength = max(maxLength, i - start);
//        }
//        return maxLength;
//    }
////};
//class Solution {
//public:
//    int maxScore(vector<int>& cardPoints, int k) {
//        int n = cardPoints.size();
//        // 滑动窗口大小为 n-k
//        int windowSize = n - k;
//        // 选前 n-k 个作为初始值
//        int sum = accumulate(cardPoints.begin(), cardPoints.begin() + windowSize, 0);
//        int minSum = sum;
//        for (int i = windowSize; i < n; ++i) {
//            // 滑动窗口每向右移动一格，增加从右侧进入窗口的元素值，并减少从左侧离开窗口的元素值
//            sum += cardPoints[i] - cardPoints[i - windowSize];
//            minSum = min(minSum, sum);
//        }
//        return accumulate(cardPoints.begin(), cardPoints.end(), 0) - minSum;
//    }
////};
//class Solution {
//public:
//    bool checkPossibility(vector<int>& nums) {
//        int n = nums.size();
//        for (int i = 0; i < n - 1; ++i) {
//            int x = nums[i], y = nums[i + 1];
//            if (x > y) {
//                nums[i] = y;
//                if (is_sorted(nums.begin(), nums.end())) {
//                    return true;
//                }
//                nums[i] = x; // 复原
//                nums[i + 1] = x;
//                return is_sorted(nums.begin(), nums.end());
//            }
//        }
//        return true;
//    }
//};
//class Solution {
//public:
//    int maxTurbulenceSize(vector<int>& arr) {
//        int n = arr.size();
//        int ret = 1;
//        int left = 0, right = 0;
//
//        while (right < n - 1) {
//            if (left == right) {
//                if (arr[left] == arr[left + 1]) {
//                    left++;
//                }
//                right++;
//            }
//            else {
//                if (arr[right - 1] < arr[right] && arr[right] > arr[right + 1]) {
//                    right++;
//                }
//                else if (arr[right - 1] > arr[right] && arr[right] < arr[right + 1]) {
//                    right++;
//                }
//                else {
//                    left = right;
//                }
//            }
//            ret = max(ret, right - left + 1);
//        }
//        return ret;
//    }
//};
//class Solution {
//public:
//    int subarraysWithKDistinct(vector<int>& A, int K) {
//        int n = A.size();
//        vector<int> num1(n + 1), num2(n + 1);
//        int tot1 = 0, tot2 = 0;
//        int left1 = 0, left2 = 0, right = 0;
//        int ret = 0;
//        while (right < n) {
//            if (!num1[A[right]]) {
//                tot1++;
//            }
//            num1[A[right]]++;
//            if (!num2[A[right]]) {
//                tot2++;
//            }
//            num2[A[right]]++;
//            while (tot1 > K) {
//                num1[A[left1]]--;
//                if (!num1[A[left1]]) {
//                    tot1--;
//                }
//                left1++;
//            }
//            while (tot2 > K - 1) {
//                num2[A[left2]]--;
//                if (!num2[A[left2]]) {
//                    tot2--;
//                }
//                left2++;
//            }
//            ret += left2 - left1;
//            right++;
//        }
//        return ret;
//    }
//};
//class Solution {
//public:
//    bool checkInclusion(string s1, string s2) {
//        int n = s1.length(), m = s2.length();
//        if (n > m) {
//            return false;
//        }
//        vector<int> cnt1(26), cnt2(26);
//        for (int i = 0; i < n; ++i) {
//            ++cnt1[s1[i] - 'a'];
//            ++cnt2[s2[i] - 'a'];
//        }
//        if (cnt1 == cnt2) {
//            return true;
//        }
//        for (int i = n; i < m; ++i) {
//            ++cnt2[s2[i] - 'a'];
//            --cnt2[s2[i - n] - 'a'];
//            if (cnt1 == cnt2) {
//                return true;
//            }
//        }
//        return false;
//    }
//};
//class KthLargest {
//public:
//    priority_queue<int, vector<int>, greater<int>> q;
//    int k;
//    KthLargest(int k, vector<int>& nums) {
//        this->k = k;
//        for (auto& x : nums) {
//            add(x);
//        }
//    }
//
//    int add(int val) {
//        q.push(val);
//        if (q.size() > k) {
//            q.pop();
//        }
//        return q.top();
//    }
//};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
//class Solution {
//public:
//    vector<int> getRow(int rowIndex) {
//        vector<vector<int>> C(rowIndex + 1);
//        for (int i = 0; i <= rowIndex; ++i) {
//            C[i].resize(i + 1);
//            C[i][0] = C[i][i] = 1;
//            for (int j = 1; j < i; ++j) {
//                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
//            }
//        }
//        return C[rowIndex];
//    }
//};
//class Solution {
//public:
//    vector<int> findDisappearedNumbers(vector<int>& nums) {
//        int n = nums.size();
//        for (auto& num : nums) {
//            int x = (num - 1) % n;
//            nums[x] += n;
//        }
//        vector<int> ret;
//        for (int i = 0; i < n; i++) {
//            if (nums[i] <= n) {
//                ret.push_back(i + 1);
//            }
//        }
//        return ret;
//    }
//};
//class Solution {
//public:
//    int getf(vector<int>& f, int x) {
//        if (f[x] == x) {
//            return x;
//        }
//        int newf = getf(f, f[x]);
//        f[x] = newf;
//        return newf;
//    }
//
//    void add(vector<int>& f, int x, int y) {
//        int fx = getf(f, x);
//        int fy = getf(f, y);
//        f[fx] = fy;
//    }
//
//    int minSwapsCouples(vector<int>& row) {
//        int n = row.size();
//        int tot = n / 2;
//        vector<int> f(tot, 0);
//        for (int i = 0; i < tot; i++) {
//            f[i] = i;
//        }
//
//        for (int i = 0; i < n; i += 2) {
//            int l = row[i] / 2;
//            int r = row[i + 1] / 2;
//            add(f, l, r);
//        }
//
//        unordered_map<int, int> m;
//        for (int i = 0; i < tot; i++) {
//            int fx = getf(f, i);
//            m[fx]++;
//        }
//
//        int ret = 0;
//        for (const auto& [f, sz] : m) {
//            ret += sz - 1;
//        }
//        return ret;
//    }
//};
//class Solution {
//public:
//    int findMaxConsecutiveOnes(vector<int>& nums) {
//        int maxCount = 0, count = 0;
//        int n = nums.size();
//        for (int i = 0; i < n; i++) {
//            if (nums[i] == 1) {
//                count++;
//            }
//            else {
//                maxCount = max(maxCount, count);
//                count = 0;
//            }
//        }
//        maxCount = max(maxCount, count);
//        return maxCount;
//    }
//};
//class Solution {
//public:
//    int arrayPairSum(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//        int ans = 0;
//        for (int i = 0; i < nums.size(); i += 2) {
//            ans += nums[i];
//        }
//        return ans;
//    }
//};
//class Solution {
//public:
//    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
//        int m = nums.size();
//        int n = nums[0].size();
//        if (m * n != r * c) {
//            return nums;
//        }
//
//        vector<vector<int>> ans(r, vector<int>(c));
//        for (int x = 0; x < m * n; ++x) {
//            ans[x / c][x % c] = nums[x / n][x % n];
//        }
//        return ans;
//    }
//};
//class Solution {
//public:
//    int minKBitFlips(vector<int>& A, int K) {
//        int n = A.size();
//        vector<int> diff(n + 1);
//        int ans = 0, revCnt = 0;
//        for (int i = 0; i < n; ++i) {
//            revCnt += diff[i];
//            if ((A[i] + revCnt) % 2 == 0) {
//                if (i + K > n) {
//                    return -1;
//                }
//                ++ans;
//                ++revCnt;
//                --diff[i + K];
//            }
//        }
//        return ans;
//    }
//};
//class Solution {
//public:
//    int longestOnes(vector<int>& A, int K) {
//        int n = A.size();
//        vector<int> P(n + 1);
//        for (int i = 1; i <= n; ++i) {
//            P[i] = P[i - 1] + (1 - A[i - 1]);
//        }
//
//        int ans = 0;
//        for (int right = 0; right < n; ++right) {
//            int left = lower_bound(P.begin(), P.end(), P[right + 1] - K) - P.begin();
//            ans = max(ans, right - left + 1);
//        }
//        return ans;
//    }
//};
//class Solution {
//public:
//    int findShortestSubArray(vector<int>& nums) {
//        unordered_map<int, vector<int>> mp;
//        int n = nums.size();
//        for (int i = 0; i < n; i++) {
//            if (mp.count(nums[i])) {
//                mp[nums[i]][0]++;
//                mp[nums[i]][2] = i;
//            }
//            else {
//                mp[nums[i]] = { 1, i, i };
//            }
//        }
//        int maxNum = 0, minLen = 0;
//        for (auto& [_, vec] : mp) {
//            if (maxNum < vec[0]) {
//                maxNum = vec[0];
//                minLen = vec[2] - vec[1] + 1;
//            }
//            else if (maxNum == vec[0]) {
//                if (minLen > vec[2] - vec[1] + 1) {
//                    minLen = vec[2] - vec[1] + 1;
//                }
//            }
//        }
//        return minLen;
//    }
//};
//class Solution {
//public:
//    int longestSubarray(vector<int>& nums, int limit) {
//        multiset<int> s;
//        int n = nums.size();
//        int left = 0, right = 0;
//        int ret = 0;
//        while (right < n) {
//            s.insert(nums[right]);
//            while (*s.rbegin() - *s.begin() > limit) {
//                s.erase(s.find(nums[left++]));
//            }
//            ret = max(ret, right - left + 1);
//            right++;
//        }
//        return ret;
//    }
//};
//class Solution {
//public:
//    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
//        int m = matrix.size(), n = matrix[0].size();
//        for (int i = 1; i < m; i++) {
//            for (int j = 1; j < n; j++) {
//                if (matrix[i][j] != matrix[i - 1][j - 1]) {
//                    return false;
//                }
//            }
//        }
//        return true;
//    }
//};
//class Solution {
//public:
//    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
//        int total = 0;
//        int n = customers.size();
//        for (int i = 0; i < n; i++) {
//            if (grumpy[i] == 0) {
//                total += customers[i];
//            }
//        }
//        int increase = 0;
//        for (int i = 0; i < X; i++) {
//            increase += customers[i] * grumpy[i];
//        }
//        int maxIncrease = increase;
//        for (int i = X; i < n; i++) {
//            increase = increase - customers[i - X] * grumpy[i - X] + customers[i] * grumpy[i];
//            maxIncrease = max(maxIncrease, increase);
//        }
//        return total + maxIncrease;
//    }
//};
//class Solution {
//public:
//    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
//        int n = A.size();
//        for (int i = 0; i < n; i++) {
//            int left = 0, right = n - 1;
//            while (left < right) {
//                if (A[i][left] == A[i][right]) {
//                    A[i][left] ^= 1;
//                    A[i][right] ^= 1;
//                }
//                left++;
//                right--;
//            }
//            if (left == right) {
//                A[i][left] ^= 1;
//            }
//        }
//        return A;
//    }
//};
//class Solution {
//public:
//    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
//        int m = matrix.size(), n = matrix[0].size();
//        vector<vector<int>> transposed(n, vector<int>(m));
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                transposed[j][i] = matrix[i][j];
//            }
//        }
//        return transposed;
//    }
//};
//class Solution {
//public:
//    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
//        unordered_map<int, int> frequency;
//
//        for (const string& word : words) {
//            int mask = 0;
//            for (char ch : word) {
//                mask |= (1 << (ch - 'a'));
//            }
//            if (__builtin_popcount(mask) <= 7) {
//                ++frequency[mask];
//            }
//        }
//
//        vector<int> ans;
//        for (const string& puzzle : puzzles) {
//            int total = 0;
//
//            // 枚举子集方法一
//            // for (int choose = 0; choose < (1 << 6); ++choose) {
//            //     int mask = 0;
//            //     for (int i = 0; i < 6; ++i) {
//            //         if (choose & (1 << i)) {
//            //             mask |= (1 << (puzzle[i + 1] - 'a'));
//            //         }
//            //     }
//            //     mask |= (1 << (puzzle[0] - 'a'));
//            //     if (frequency.count(mask)) {
//            //         total += frequency[mask];
//            //     }
//            // }
//
//            // 枚举子集方法二
//            int mask = 0;
//            for (int i = 1; i < 7; ++i) {
//                mask |= (1 << (puzzle[i] - 'a'));
//            }
//            int subset = mask;
//            do {
//                int s = subset | (1 << (puzzle[0] - 'a'));
//                if (frequency.count(s)) {
//                    total += frequency[s];
//                }
//                subset = (subset - 1) & mask;
//            } while (subset != mask);
//
//            ans.push_back(total);
//        }
//        return ans;
//    }
//};

//class Solution {
//public:
//    int dfs(const string& s, int l, int r, int k) {
//        vector<int> cnt(26, 0);
//        for (int i = l; i <= r; i++) {
//            cnt[s[i] - 'a']++;
//        }
//
//        char split = 0;
//        for (int i = 0; i < 26; i++) {
//            if (cnt[i] > 0 && cnt[i] < k) {
//                split = i + 'a';
//                break;
//            }
//        }
//        if (split == 0) {
//            return r - l + 1;
//        }
//
//        int i = l;
//        int ret = 0;
//        while (i <= r) {
//            while (i <= r && s[i] == split) {
//                i++;
//            }
//            if (i > r) {
//                break;
//            }
//            int start = i;
//            while (i <= r && s[i] != split) {
//                i++;
//            }
//
//            int length = dfs(s, start, i - 1, k);
//            ret = max(ret, length);
//        }
//        return ret;
//    }
//
//    int longestSubstring(string s, int k) {
//        int n = s.length();
//        return dfs(s, 0, n - 1, k);
//    }
//};
//class Solution {
//public:
//    bool isMonotonic(vector<int>& A) {
//        return is_sorted(A.begin(), A.end()) || is_sorted(A.rbegin(), A.rend());
//    }
//};
//class NumArray {
//public:
//    vector<int> sums;
//
//    NumArray(vector<int>& nums) {
//        int n = nums.size();
//        sums.resize(n + 1);
//        for (int i = 0; i < n; i++) {
//            sums[i + 1] = sums[i] + nums[i];
//        }
//    }
//
//    int sumRange(int i, int j) {
//        return sums[j + 1] - sums[i];
//    }
//};
//class NumMatrix {
//public:
//    vector<vector<int>> sums;
//
//    NumMatrix(vector<vector<int>>& matrix) {
//        int m = matrix.size();
//        if (m > 0) {
//            int n = matrix[0].size();
//            sums.resize(m, vector<int>(n + 1));
//            for (int i = 0; i < m; i++) {
//                for (int j = 0; j < n; j++) {
//                    sums[i][j + 1] = sums[i][j] + matrix[i][j];
//                }
//            }
//        }
//    }
//
//    int sumRegion(int row1, int col1, int row2, int col2) {
//        int sum = 0;
//        for (int i = row1; i <= row2; i++) {
//            sum += sums[i][col2 + 1] - sums[i][col1];
//        }
//        return sum;
//    }
//};
//class Solution {
//public:
//    int countOnes(int x) {
//        int ones = 0;
//        while (x > 0) {
//            x &= (x - 1);
//            ones++;
//        }
//        return ones;
//    }
//
//    vector<int> countBits(int num) {
//        vector<int> bits(num + 1);
//        for (int i = 0; i <= num; i++) {
//            bits[i] = countOnes(i);
//        }
//        return bits;
//    }
//};
//class Solution {
//public:
//    int maxEnvelopes(vector<vector<int>>& envelopes) {
//        if (envelopes.empty()) {
//            return 0;
//        }
//
//        int n = envelopes.size();
//        sort(envelopes.begin(), envelopes.end(), [](const auto& e1, const auto& e2) {
//            return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
//            });
//
//        vector<int> f(n, 1);
//        for (int i = 1; i < n; ++i) {
//            for (int j = 0; j < i; ++j) {
//                if (envelopes[j][1] < envelopes[i][1]) {
//                    f[i] = max(f[i], f[j] + 1);
//                }
//            }
//        }
//        return *max_element(f.begin(), f.end());
//    }
//};
//class MyQueue {
//private:
//    stack<int> inStack, outStack;
//
//    void in2out() {
//        while (!inStack.empty()) {
//            outStack.push(inStack.top());
//            inStack.pop();
//        }
//    }
//
//public:
//    MyQueue() {}
//
//    void push(int x) {
//        inStack.push(x);
//    }
//
//    int pop() {
//        if (outStack.empty()) {
//            in2out();
//        }
//        int x = outStack.top();
//        outStack.pop();
//        return x;
//    }
//
//    int peek() {
//        if (outStack.empty()) {
//            in2out();
//        }
//        return outStack.top();
//    }
//
//    bool empty() {
//        return inStack.empty() && outStack.empty();
//    }
//};
//
//class Solution {
//public:
//    vector<int> nextGreaterElements(vector<int>& nums) {
//        int n = nums.size();
//        vector<int> ret(n, -1);
//        stack<int> stk;
//        for (int i = 0; i < n * 2 - 1; i++) {
//            while (!stk.empty() && nums[stk.top()] < nums[i % n]) {
//                ret[stk.top()] = nums[i % n];
//                stk.pop();
//            }
//            stk.push(i % n);
//        }
//        return ret;
//    }
//};
//class Solution {
//private:
//    vector<vector<int>> f;
//    vector<vector<string>> ret;
//    vector<string> ans;
//    int n;
//
//public:
//    void dfs(const string& s, int i) {
//        if (i == n) {
//            ret.push_back(ans);
//            return;
//        }
//        for (int j = i; j < n; ++j) {
//            if (f[i][j]) {
//                ans.push_back(s.substr(i, j - i + 1));
//                dfs(s, j + 1);
//                ans.pop_back();
//            }
//        }
//    }
//
//    vector<vector<string>> partition(string s) {
//        n = s.size();
//        f.assign(n, vector<int>(n, true));
//
//        for (int i = n - 1; i >= 0; --i) {
//            for (int j = i + 1; j < n; ++j) {
//                f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
//            }
//        }
//
//        dfs(s, 0);
//        return ret;
//    }
//};
//class Solution {
//public:
//    int minCut(string s) {
//        int n = s.size();
//        vector<vector<int>> g(n, vector<int>(n, true));
//
//        for (int i = n - 1; i >= 0; --i) {
//            for (int j = i + 1; j < n; ++j) {
//                g[i][j] = (s[i] == s[j]) && g[i + 1][j - 1];
//            }
//        }
//
//        vector<int> f(n, INT_MAX);
//        for (int i = 0; i < n; ++i) {
//            if (g[0][i]) {
//                f[i] = 0;
//            }
//            else {
//                for (int j = 0; j < i; ++j) {
//                    if (g[j + 1][i]) {
//                        f[i] = min(f[i], f[j] + 1);
//                    }
//                }
//            }
//        }
//
//        return f[n - 1];
//    }
//};
//class Solution {
//public:
//    string removeDuplicates(string S) {
//        string stk;
//        for (char ch : S) {
//            if (!stk.empty() && stk.back() == ch) {
//                stk.pop_back();
//            }
//            else {
//                stk.push_back(ch);
//            }
//        }
//        return stk;
//    }
//};
//class Solution {
//public:
//    int calculate(string s) {
//        stack<int> ops;
//        ops.push(1);
//        int sign = 1;
//
//        int ret = 0;
//        int n = s.length();
//        int i = 0;
//        while (i < n) {
//            if (s[i] == ' ') {
//                i++;
//            }
//            else if (s[i] == '+') {
//                sign = ops.top();
//                i++;
//            }
//            else if (s[i] == '-') {
//                sign = -ops.top();
//                i++;
//            }
//            else if (s[i] == '(') {
//                ops.push(sign);
//                i++;
//            }
//            else if (s[i] == ')') {
//                ops.pop();
//                i++;
//            }
//            else {
//                long num = 0;
//                while (i < n && s[i] >= '0' && s[i] <= '9') {
//                    num = num * 10 + s[i] - '0';
//                    i++;
//                }
//                ret += sign * num;
//            }
//        }
//        return ret;
//    }
//};
//class Solution {
//public:
//    int calculate(string s) {
//        vector<int> stk;
//        char preSign = '+';
//        int num = 0;
//        int n = s.length();
//        for (int i = 0; i < n; ++i) {
//            if (isdigit(s[i])) {
//                num = num * 10 + int(s[i] - '0');
//            }
//            if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1) {
//                switch (preSign) {
//                case '+':
//                    stk.push_back(num);
//                    break;
//                case '-':
//                    stk.push_back(-num);
//                    break;
//                case '*':
//                    stk.back() *= num;
//                    break;
//                default:
//                    stk.back() /= num;
//                }
//                preSign = s[i];
//                num = 0;
//            }
//        }
//        return accumulate(stk.begin(), stk.end(), 0);
//    }
//};
//class MyHashSet {
//private:
//    vector<list<int>> data;
//    static const int base = 769;
//    static int hash(int key) {
//        return key % base;
//    }
//public:
//    /** Initialize your data structure here. */
//    MyHashSet() : data(base) {}
//
//    void add(int key) {
//        int h = hash(key);
//        for (auto it = data[h].begin(); it != data[h].end(); it++) {
//            if ((*it) == key) {
//                return;
//            }
//        }
//        data[h].push_back(key);
//    }
//
//    void remove(int key) {
//        int h = hash(key);
//        for (auto it = data[h].begin(); it != data[h].end(); it++) {
//            if ((*it) == key) {
//                data[h].erase(it);
//                return;
//            }
//        }
//    }
//
//    /** Returns true if this set contains the specified element */
//    bool contains(int key) {
//        int h = hash(key);
//        for (auto it = data[h].begin(); it != data[h].end(); it++) {
//            if ((*it) == key) {
//                return true;
//            }
//        }
//        return false;
//    }
//};
//class MyHashMap {
//private:
//    vector<list<pair<int, int>>> data;
//    static const int base = 769;
//    static int hash(int key) {
//        return key % base;
//    }
//public:
//    /** Initialize your data structure here. */
//    MyHashMap() : data(base) {}
//
//    /** value will always be non-negative. */
//    void put(int key, int value) {
//        int h = hash(key);
//        for (auto it = data[h].begin(); it != data[h].end(); it++) {
//            if ((*it).first == key) {
//                (*it).second = value;
//                return;
//            }
//        }
//        data[h].push_back(make_pair(key, value));
//    }
//
//    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
//    int get(int key) {
//        int h = hash(key);
//        for (auto it = data[h].begin(); it != data[h].end(); it++) {
//            if ((*it).first == key) {
//                return (*it).second;
//            }
//        }
//        return -1;
//    }
//
//    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
//    void remove(int key) {
//        int h = hash(key);
//        for (auto it = data[h].begin(); it != data[h].end(); it++) {
//            if ((*it).first == key) {
//                data[h].erase(it);
//                return;
//            }
//        }
//    }
//};
//class Solution {
//private:
//    static constexpr int directions[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
//public:
//    vector<int> spiralOrder(vector<vector<int>>& matrix) {
//        if (matrix.size() == 0 || matrix[0].size() == 0) {
//            return {};
//        }
//
//        int rows = matrix.size(), columns = matrix[0].size();
//        vector<vector<bool>> visited(rows, vector<bool>(columns));
//        int total = rows * columns;
//        vector<int> order(total);
//
//        int row = 0, column = 0;
//        int directionIndex = 0;
//        for (int i = 0; i < total; i++) {
//            order[i] = matrix[row][column];
//            visited[row][column] = true;
//            int nextRow = row + directions[directionIndex][0], nextColumn = column + directions[directionIndex][1];
//            if (nextRow < 0 || nextRow >= rows || nextColumn < 0 || nextColumn >= columns || visited[nextRow][nextColumn]) {
//                directionIndex = (directionIndex + 1) % 4;
//            }
//            row += directions[directionIndex][0];
//            column += directions[directionIndex][1];
//        }
//        return order;
//    }
//};
//class Solution {
//public:
//    vector<vector<int>> generateMatrix(int n) {
//        int maxNum = n * n;
//        int curNum = 1;
//        vector<vector<int>> matrix(n, vector<int>(n));
//        int row = 0, column = 0;
//        vector<vector<int>> directions = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };  // 右下左上
//        int directionIndex = 0;
//        while (curNum <= maxNum) {
//            matrix[row][column] = curNum;
//            curNum++;
//            int nextRow = row + directions[directionIndex][0], nextColumn = column + directions[directionIndex][1];
//            if (nextRow < 0 || nextRow >= n || nextColumn < 0 || nextColumn >= n || matrix[nextRow][nextColumn] != 0) {
//                directionIndex = (directionIndex + 1) % 4;  // 顺时针旋转至下一个方向
//            }
//            row = row + directions[directionIndex][0];
//            column = column + directions[directionIndex][1];
//        }
//        return matrix;
//    }
//};
//class Solution {
//public:
//    int numDistinct(string s, string t) {
//        int m = s.length(), n = t.length();
//        if (m < n) {
//            return 0;
//        }
//        vector<vector<long>> dp(m + 1, vector<long>(n + 1));
//        for (int i = 0; i <= m; i++) {
//            dp[i][n] = 1;
//        }
//        for (int i = m - 1; i >= 0; i--) {
//            char sChar = s.at(i);
//            for (int j = n - 1; j >= 0; j--) {
//                char tChar = t.at(j);
//                if (sChar == tChar) {
//                    dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
//                }
//                else {
//                    dp[i][j] = dp[i + 1][j];
//                }
//            }
//        }
//        return dp[0][0];
//    }
//};
//class Solution {
//private:
//    void reverseLinkedList(ListNode* head) {
//        // 也可以使用递归反转一个链表
//        ListNode* pre = nullptr;
//        ListNode* cur = head;
//
//        while (cur != nullptr) {
//            ListNode* next = cur->next;
//            cur->next = pre;
//            pre = cur;
//            cur = next;
//        }
//    }
//
//public:
//    ListNode* reverseBetween(ListNode* head, int left, int right) {
//        // 因为头节点有可能发生变化，使用虚拟头节点可以避免复杂的分类讨论
//        ListNode* dummyNode = new ListNode(-1);
//        dummyNode->next = head;
//
//        ListNode* pre = dummyNode;
//        // 第 1 步：从虚拟头节点走 left - 1 步，来到 left 节点的前一个节点
//        // 建议写在 for 循环里，语义清晰
//        for (int i = 0; i < left - 1; i++) {
//            pre = pre->next;
//        }
//
//        // 第 2 步：从 pre 再走 right - left + 1 步，来到 right 节点
//        ListNode* rightNode = pre;
//        for (int i = 0; i < right - left + 1; i++) {
//            rightNode = rightNode->next;
//        }
//
//        // 第 3 步：切断出一个子链表（截取链表）
//        ListNode* leftNode = pre->next;
//        ListNode* curr = rightNode->next;
//
//        // 注意：切断链接
//        pre->next = nullptr;
//        rightNode->next = nullptr;
//
//        // 第 4 步：同第 206 题，反转链表的子区间
//        reverseLinkedList(leftNode);
//
//        // 第 5 步：接回到原来的链表中
//        pre->next = rightNode;
//        leftNode->next = curr;
//        return dummyNode->next;
//    }
//};
//class ParkingSystem {
//public:
//    int b, m, s;
//    ParkingSystem(int big, int medium, int small) : b(big), m(medium), s(small) {}
//
//    bool addCar(int carType) {
//        if (carType == 1) {
//            if (b > 0) {
//                b--;
//                return true;
//            }
//        }
//        else if (carType == 2) {
//            if (m > 0) {
//                m--;
//                return true;
//            }
//        }
//        else if (carType == 3) {
//            if (s > 0) {
//                s--;
//                return true;
//            }
//        }
//        return false;
//    }
//};
//class Solution {
//public:
//    int evalRPN(vector<string>& tokens) {
//        stack<int> stk;
//        int n = tokens.size();
//        for (int i = 0; i < n; i++) {
//            string& token = tokens[i];
//            if (isNumber(token)) {
//                stk.push(atoi(token.c_str()));
//            }
//            else {
//                int num2 = stk.top();
//                stk.pop();
//                int num1 = stk.top();
//                stk.pop();
//                switch (token[0]) {
//                case '+':
//                    stk.push(num1 + num2);
//                    break;
//                case '-':
//                    stk.push(num1 - num2);
//                    break;
//                case '*':
//                    stk.push(num1 * num2);
//                    break;
//                case '/':
//                    stk.push(num1 / num2);
//                    break;
//                }
//            }
//        }
//        return stk.top();
//    }
//
//    bool isNumber(string& token) {
//        return !(token == "+" || token == "-" || token == "*" || token == "/");
//    }
//};
//class Solution {
//public:
//    void setZeroes(vector<vector<int>>& matrix) {
//        int m = matrix.size();
//        int n = matrix[0].size();
//        vector<int> row(m), col(n);
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                if (!matrix[i][j]) {
//                    row[i] = col[j] = true;
//                }
//            }
//        }
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                if (row[i] || col[j]) {
//                    matrix[i][j] = 0;
//                }
//            }
//        }
//    }
//};
//class Solution {
//public:
//    int hammingWeight(uint32_t n) {
//        int ret = 0;
//        for (int i = 0; i < 32; i++) {
//            if (n & (1 << i)) {
//                ret++;
//            }
//        }
//        return ret;
//    }
//};
//class NestedIterator {
//private:
//    vector<int> vals;
//    vector<int>::iterator cur;
//
//    void dfs(const vector<NestedInteger>& nestedList) {
//        for (auto& nest : nestedList) {
//            if (nest.isInteger()) {
//                vals.push_back(nest.getInteger());
//            }
//            else {
//                dfs(nest.getList());
//            }
//        }
//    }
//
//public:
//    NestedIterator(vector<NestedInteger>& nestedList) {
//        dfs(nestedList);
//        cur = vals.begin();
//    }
//
//    int next() {
//        return *cur++;
//    }
//
//    bool hasNext() {
//        return cur != vals.end();
//    }
//};
//class Solution {
//public:
//    bool find132pattern(vector<int>& nums) {
//        int n = nums.size();
//        if (n < 3) {
//            return false;
//        }
//
//        // 左侧最小值
//        int left_min = nums[0];
//        // 右侧所有元素
//        multiset<int> right_all;
//
//        for (int k = 2; k < n; ++k) {
//            right_all.insert(nums[k]);
//        }
//
//        for (int j = 1; j < n - 1; ++j) {
//            if (left_min < nums[j]) {
//                auto it = right_all.upper_bound(left_min);
//                if (it != right_all.end() && *it < nums[j]) {
//                    return true;
//                }
//            }
//            left_min = min(left_min, nums[j]);
//            right_all.erase(right_all.find(nums[j + 1]));
//        }
//
//        return false;
//    }
//};
//class Solution {
//public:
//    ListNode* deleteDuplicates(ListNode* head) {
//        if (!head) {
//            return head;
//        }
//
//        ListNode* dummy = new ListNode(0, head);
//
//        ListNode* cur = dummy;
//        while (cur->next && cur->next->next) {
//            if (cur->next->val == cur->next->next->val) {
//                int x = cur->next->val;
//                while (cur->next && cur->next->val == x) {
//                    cur->next = cur->next->next;
//                }
//            }
//            else {
//                cur = cur->next;
//            }
//        }
//
//        return dummy->next;
//    }
//}
//class Solution {
//public:
//    ListNode* deleteDuplicates(ListNode* head) {
//        if (!head) {
//            return head;
//        }
//
//        ListNode* cur = head;
//        while (cur->next) {
//            if (cur->val == cur->next->val) {
//                cur->next = cur->next->next;
//            }
//            else {
//                cur = cur->next;
//            }
//        }
//
//        return head;
//    }
//};
//class BSTIterator {
//private:
//    void inorder(TreeNode* root, vector<int>& res) {
//        if (!root) {
//            return;
//        }
//        inorder(root->left, res);
//        res.push_back(root->val);
//        inorder(root->right, res);
//    }
//    vector<int> inorderTraversal(TreeNode* root) {
//        vector<int> res;
//        inorder(root, res);
//        return res;
//    }
//
//    vector<int> arr;
//    int idx;
//public:
//    BSTIterator(TreeNode* root) : idx(0), arr(inorderTraversal(root)) {}
//
//    int next() {
//        return arr[idx++];
//    }
//
//    bool hasNext() {
//        return (idx < arr.size());
//    }
//};
//class Solution {
//public:
//    uint32_t reverseBits(uint32_t n) {
//        uint32_t rev = 0;
//        for (int i = 0; i < 32 && n > 0; ++i) {
//            rev |= (n & 1) << (31 - i);
//            n >>= 1;
//        }
//        return rev;
//    }
//};
