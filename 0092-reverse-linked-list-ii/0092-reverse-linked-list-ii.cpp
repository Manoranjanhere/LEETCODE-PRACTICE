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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int c=1;
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(c!=left)
        {
            prev=curr;
            curr=curr->next;
            c++;
        }
        ListNode* prev2=NULL;
        ListNode* curr2 = curr;
        ListNode* next2 = curr->next;
        while(c!=right+1)
        {
            curr2->next=prev2;
            prev2=curr2;
            curr2= next2;
            if(next2!=NULL)
            {
                next2=next2->next;
            }
            c++;
        }
        if(prev!=NULL)
        {
            prev->next=prev2;
        }
        if(curr!=NULL)
        {
            curr->next=curr2;
        }
        if(left==1)
        {
            head =  prev2;
        }
        return head;

    }
};