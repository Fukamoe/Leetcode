class Solution {
public:
    int getKthMagicNumber(int k) {
        vector<int> factors = {3, 5, 7};
        unordered_set<long> seen;
        priority_queue<long, vector<long>, greater<long>> heap;
        seen.insert(1L);
        heap.push(1L);
        int magic = 0;
        for (int i = 0; i < k; i++) {
            long curr = heap.top();
            heap.pop();
            magic = (int)curr;
            for (int factor : factors) {
                long next = curr * factor;
                if (!seen.count(next)) {
                    seen.insert(next);
                    heap.push(next);
                }
            }
        }
        return magic;
    }
};
