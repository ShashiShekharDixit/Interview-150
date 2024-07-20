class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head -> next)
        return head;
        ListNode* greater = new ListNode(-1);
        ListNode* smaller = new ListNode(-1);
        ListNode* g = greater;
        ListNode* s = smaller;
        while(head) {
            if(head -> val >= x) {
                g -> next = head;
                g = head;
            }
            else {
                s -> next = head;
                s = head;
            }
            head = head -> next;
        }
        g -> next = NULL;
        s -> next = greater -> next;
        return smaller -> next;
    }
};