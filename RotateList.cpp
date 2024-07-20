class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL || k == 0) {
            return head;
        }
        int len = 1;
        ListNode* tail = head;
        while(tail -> next != NULL){
            tail = tail -> next;
            len++;
        }
        if(k > len) {
            k = k % len;
            if(k == 0){
                return head;
            }
        }
        if(k <= len){
            k = len - k;
            if(k == 0) {
                return head;
            }
        }
        int count = 1;
        ListNode* curr = head;
        while(count < k && curr != NULL){
            curr = curr -> next;
            count++;
        }
        ListNode* temp = curr -> next;
        curr -> next = NULL;
        tail -> next = head;
        return temp;
    }
};