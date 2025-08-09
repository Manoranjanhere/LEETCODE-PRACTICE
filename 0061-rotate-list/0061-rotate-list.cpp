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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||!head->next||k==0)return head;
        ListNode* temp=head;
        int c=0;
        while(temp)
        {
            c++;
            temp=temp->next;
        }
        if(k==c)return head;
        k%=c;
        k= c-k;
        c=1;
        temp=head;
        ListNode *head2 = head;
        while(c<k)
        {
            temp=temp->next;
            c++;
        }
        ListNode *next = temp->next;
        ListNode *head1= next;
        temp->next=NULL;
        while(next->next)
        {
            next=next->next;
        }
        next->next=head2;
        return head1;
    }
};