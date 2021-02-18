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
//    // ����ѣ�ά����С��һ��Ԫ��
//    priority_queue<int> small;
//    // С���ѣ�ά���ϴ��һ��Ԫ��
//    priority_queue<int, vector<int>, greater<int>> large;
//    // ��ϣ����¼���ӳ�ɾ������Ԫ�أ�key ΪԪ�أ�value Ϊ��Ҫɾ���Ĵ���
//    unordered_map<int, int> delayed;
//
//    int k;
//    // small �� large ��ǰ������Ԫ�ظ�������Ҫ�۳������ӳ�ɾ������Ԫ��
//    int smallSize, largeSize;
//
//public:
//    DualHeap(int _k) : k(_k), smallSize(0), largeSize(0) {}
//
//private:
//    // ���ϵص��� heap �ĶѶ�Ԫ�أ����Ҹ��¹�ϣ��
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
//    // ���� small �� large �е�Ԫ�ظ�����ʹ�ö��ߵ�Ԫ�ظ�������Ҫ��
//    void makeBalance() {
//        if (smallSize > largeSize + 1) {
//            // small �� large Ԫ�ض� 2 ��
//            large.push(small.top());
//            small.pop();
//            --smallSize;
//            ++largeSize;
//            // small �Ѷ�Ԫ�ر��Ƴ�����Ҫ���� prune
//            prune(small);
//        }
//        else if (smallSize < largeSize) {
//            // large �� small Ԫ�ض� 1 ��
//            small.push(large.top());
//            large.pop();
//            ++smallSize;
//            --largeSize;
//            // large �Ѷ�Ԫ�ر��Ƴ�����Ҫ���� prune
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
//        // �������ڴ�СΪ n-k
//        int windowSize = n - k;
//        // ѡǰ n-k ����Ϊ��ʼֵ
//        int sum = accumulate(cardPoints.begin(), cardPoints.begin() + windowSize, 0);
//        int minSum = sum;
//        for (int i = windowSize; i < n; ++i) {
//            // ��������ÿ�����ƶ�һ�����Ӵ��Ҳ���봰�ڵ�Ԫ��ֵ�������ٴ�����뿪���ڵ�Ԫ��ֵ
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
//                nums[i] = x; // ��ԭ
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
