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
