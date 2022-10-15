class Solution {
public:
    int distinctSubseqII(string s) {
        vector<int> last(26, -1);
        
        int n = s.size();
        vector<int> f(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (last[j] != -1) {
                    f[i] = (f[i] + f[last[j]]) % mod;
                }
            }
            last[s[i] - 'a'] = i;
        }
        
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            if (last[i] != -1) {
                ans = (ans + f[last[i]]) % mod;
            }
        }
        return ans;
    }

private:
    static constexpr int mod = 1000000007;
};
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int prev = 0;
        for (int number : target) {
            for (int i = 0; i < number - prev - 1; i++) {
                res.emplace_back("Push");
                res.emplace_back("Pop");
            }
            res.emplace_back("Push");
            prev = number;
        }
        return res;
    }
};
