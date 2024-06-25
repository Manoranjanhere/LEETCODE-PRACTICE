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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int c=1;
        if(head->next==NULL&&n==1)return NULL;
        int len=1;
        while(temp!=NULL)
        {
            len++;
            temp=temp->next;
        }
        if(n==len-1)
        {
            head=head->next;
            return head;
        }
        temp=head;
        if(n>len)return head;
        n=len-n;
        cout<<len;
        cout<<n;
        c=1;
        while(c<n-1)
        {
            c++;
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
    }
};