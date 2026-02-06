class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* root = head;
        
        while(root != NULL && root->next != NULL){
            ListNode* temp;
            temp = root->next;
            swap(temp->val,root->val);
            root = temp->next;
        }
        return head;
    }
};