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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)return NULL;
        if(head->next==NULL)return head;
        ListNode* temp = head;
        ListNode* l3 = new ListNode();
        ListNode* temp1 = l3;

        while(temp!=NULL)
        {
            ListNode* a=new ListNode(temp->val);
            l3->next=a;
            l3=l3->next;
            temp=temp->next;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = head->next;
        while(next!=NULL)
        {
            curr->next=prev;
            prev=curr;
            curr=next;
            next=next->next;
        }
        curr->next=prev;
        // return temp1->next;
        return curr;

    }
};