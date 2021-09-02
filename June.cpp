class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        int n = 0;
        ListNode* node = nullptr;

        for (node = head; node; node = node->next) {
            n++;
        }
        for (node = head; n > k; n--) {
            node = node->next;
        }
      
        return node;
    }
};
