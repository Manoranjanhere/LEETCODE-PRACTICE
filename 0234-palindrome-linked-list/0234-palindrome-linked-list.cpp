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
    bool isPalindrome(ListNode* head) {
        if(head==NULL)return NULL;
        if(head->next==NULL)return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL&&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *prev=NULL;
        ListNode *curr=slow;
        ListNode *next=curr->next;
        while(next!=NULL)
        {
            curr->next=prev;
            prev=curr;
            curr=next;
            next=next->next;
        }
        curr->next=prev;
        while(curr!=NULL)
        {
            if(curr->val!=head->val)
            {
                return false;
            }
            curr=curr->next;
            head=head->next;
        }
        return true;
    }
};