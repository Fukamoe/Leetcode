class Solution {
public:
    int numRescueBoats(vector<int> &people, int limit) {
        int ans = 0;
        sort(people.begin(), people.end());
        int light = 0, heavy = people.size() - 1;
        while (light <= heavy) {
            if (people[light] + people[heavy] > limit) {
                --heavy;
            } else {
                ++light;
                --heavy;
            }
            ++ans;
        }
        return ans;
    }
};class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> queMin;
    priority_queue<int, vector<int>, greater<int>> queMax;

    MedianFinder() {}

    void addNum(int num) {
        if (queMin.empty() || num <= queMin.top()) {
            queMin.push(num);
            if (queMax.size() + 1 < queMin.size()) {
                queMax.push(queMin.top());
                queMin.pop();
            }
        } else {
            queMax.push(num);
            if (queMax.size() > queMin.size()) {
                queMin.push(queMax.top());
                queMax.pop();
            }
        }
    }

    double findMedian() {
        if (queMin.size() > queMax.size()) {
            return queMin.top();
        }
        return (queMin.top() + queMax.top()) / 2.0;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/find-median-from-data-stream/solution/shu-ju-liu-de-zhong-wei-shu-by-leetcode-ktkst/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
