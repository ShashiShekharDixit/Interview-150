class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL or head -> next == NULL) return NULL;
        ListNode *slow = head, *fast = head, * prev = NULL;
        while(fast != NULL and fast -> next != NULL) {
            fast = fast -> next -> next;
            prev = slow;
            slow = slow -> next;
        } 
        prev -> next = slow -> next;
        slow -> next = NULL;
        delete slow;
        return head;
    }
};