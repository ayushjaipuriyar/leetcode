class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // Move the fast pointer n nodes ahead
        for (int i = 0; i <= n; i++) {
            if (fast == NULL) {
                // If the value of n is greater than the number of nodes in the list
                delete dummy;
                return head;
            }
            fast = fast->next;
        }

        // Move both the slow and fast pointers until the fast pointer reaches the end
        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        // Remove the nth node from the end
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;

        ListNode* result = dummy->next;
        delete dummy;

        return result;
    }
};
