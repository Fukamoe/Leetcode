class Solution {
public:
    int sumOfUnique(vector<int> &nums) {
        unordered_map<int, int> cnt;
        for (int num : nums) {
            ++cnt[num];
        }
        int ans = 0;
        for (auto &[num, c] : cnt) {
            if (c == 1) {
                ans += num;
            }
        }
        return ans;
    }
};
