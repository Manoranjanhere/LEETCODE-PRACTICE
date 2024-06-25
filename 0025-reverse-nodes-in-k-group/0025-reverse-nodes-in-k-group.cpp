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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp= head;
        ListNode* lastprev =NULL;
        while(true)
        {
            ListNode* kth=kthnode(temp,k);
            if(kth==NULL)
            {
             if (lastprev != NULL) 
                {
                    lastprev->next = temp;
                }
                 break;
            }
            
            ListNode* store= kth->next;
            kth->next=NULL;
            ListNode* prev = NULL;
            ListNode* curr= temp;
            ListNode* next = curr->next;
            while(next!=NULL)
            {
                curr->next=prev;
                prev=curr;
                curr=next;
                next=next->next;
            }
            curr->next=prev;
            if(temp==head)
            {
                head=curr;
            }
            else
            {
                lastprev->next=curr;
            }
           lastprev=temp;
            temp=store;

        }
        return head;
    }
    ListNode* kthnode(ListNode* temp,int k)
    {
        k-=1;
        while(temp!=NULL&&k>0)
        {
            temp=temp->next;
            k--;
        }
        if(k>0)return NULL;
        return temp;
   }
};