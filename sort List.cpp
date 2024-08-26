class Solution {
public:
    ListNode* middle(ListNode* &head){
        ListNode*slow= head;
        ListNode*fast= head->next;
        while(fast!=NULL &&fast->next!=NULL){
            slow=slow->next;
            fast= fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* &left, ListNode* &right){
        if(left==NULL) return right;
        if(right==NULL) return left;
        ListNode* temp= new ListNode(-1);
        ListNode* mptr= temp;
        while(left!=NULL && right!=NULL){
            if(left->val <= right->val){
                mptr->next=left;
                mptr=left;
                left=left->next;
            }
            else{
                mptr->next=right;
                mptr=right;
                right=right->next;
            }
        }
        while(left!=NULL){
            mptr->next=left;
            mptr=left;
            left=left->next;
        }
        while(right!=NULL){
            mptr->next=right;
            mptr=right;
            right=right->next;
        }
        return temp->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* mid= middle(head);
        ListNode* left= head;
        ListNode* right= mid->next;
        mid->next=NULL;
        left=sortList(left);
        right=sortList(right);
        ListNode* mergeLL= merge(left,right);
        return mergeLL;   

    }
};