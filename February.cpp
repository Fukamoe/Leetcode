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
//};
