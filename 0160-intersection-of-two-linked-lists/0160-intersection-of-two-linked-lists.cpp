/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=0;
        int l2=0;
        ListNode* temp=headA;
        while(temp!=NULL)
        {
            l1++;
            temp=temp->next;
        }
         temp=headB;
        while(temp!=NULL)
        {
            l2++;
            temp=temp->next;
        }
        if(l2>l1)
        {
            int big= l2-l1;
            int c=0;
            while(c<big)
            {
                c++;
                headB=headB->next;
            }

        }
        if(l2<l1)
        {
            int big= l1-l2;
            int c=0;
            while(c<big)
            {
                c++;
                headA=headA->next;
            }

        }
        while(headA!=NULL&&headB!=NULL)
        {
            if(headA==headB)
            {
                temp=headA;
               return temp;
            }
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
        }
};