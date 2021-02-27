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