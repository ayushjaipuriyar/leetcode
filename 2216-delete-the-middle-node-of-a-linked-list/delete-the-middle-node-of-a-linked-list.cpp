/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL)
            return NULL;
        ListNode* p = head;
        ListNode* p2 = head->next->next;
        while(p2 != NULL && p2->next != NULL){
            p2 = p2->next->next;
        p = p->next;
        }
        p->next = p->next->next;
        return head;
    }
};