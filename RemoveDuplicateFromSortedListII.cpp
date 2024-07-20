class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head -> next) {
            return head;
        }
        ListNode* output = new ListNode(0, head);
        ListNode* prev = output;
        while(head) {
            if( head -> next && head -> val == head -> next -> val){
                while(head -> next && head -> val == head -> next -> val) {
                    head = head -> next;
                }
                prev -> next = head -> next;
            } else {
                prev = prev -> next;
            }
            head = head -> next;
        }
        return output -> next;
    }
};