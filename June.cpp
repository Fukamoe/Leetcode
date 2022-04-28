class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> res;
        for (auto & num : nums) {
            if (num % 2 == 0) {
                res.push_back(num);
            }
        }
        for (auto & num : nums) {
            if (num % 2 == 1) {
                res.push_back(num);
            }
        }
        return res;
    }
};
