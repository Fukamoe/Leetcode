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
