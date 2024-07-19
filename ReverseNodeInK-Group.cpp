class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int s = 0; 
        ListNode* curr = head; 
        while (curr != NULL) { 
            s++;
            if (s >= k) break;
            curr = curr->next;
        } 
        if (s < k) {
            return head;
        }
        
        ListNode* h = head;
        curr = head; 
        for (int i = 0; i < k - 1; ++i) { 
            curr = curr->next;
        } 
        ListNode* nh = curr->next; 
        curr->next = NULL;
        ListNode* p = NULL;
        ListNode* c = h;
        ListNode* n = NULL;
        while(c != NULL) { 
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        h->next = reverseKGroup(nh, k); 
        return curr;
    }
};