class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> ans;
        unordered_map<string, int> counts;
        for (auto &&cpdomain : cpdomains) {
            int space = cpdomain.find(' ');
            int count = stoi(cpdomain.substr(0, space));
            string domain = cpdomain.substr(space + 1);
            counts[domain] += count;
            for (int i = 0; i < domain.size(); i++) {
                if (domain[i] == '.') {
                    string subdomain = domain.substr(i + 1);
                    counts[subdomain] += count;
                }
            }
        }
        for (auto &&[subdomain, count] : counts) {
            ans.emplace_back(to_string(count) + " " + subdomain);
        }
        return ans;
    }
};class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (sum % 3 != 0) {
            return {-1, -1};
        }
        if (sum == 0) {
            return {0, 2};
        }

        int partial = sum / 3;
        int first = 0, second = 0, third = 0, cur = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 1) {
                if (cur == 0) {
                    first = i;
                }
                else if (cur == partial) {
                    second = i;
                }
                else if (cur == 2 * partial) {
                    third = i;
                }
                cur++;
            }
        }

        int len = (int)arr.size() - third;
        if (first + len <= second && second + len <= third) {
            int i = 0;
            while (third + i < arr.size()) {
                if (arr[first + i] != arr[second + i] || arr[first + i] != arr[third + i]) {
                    return {-1, -1};
                }
                i++;
            }
            return {first + len - 1, second + len};
        }
        return {-1, -1};
    }
};

