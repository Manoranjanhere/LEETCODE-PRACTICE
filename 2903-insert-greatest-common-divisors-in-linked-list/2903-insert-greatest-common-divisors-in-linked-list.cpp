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
    int gcd(int a,int b)
    {
        while(b!=0)
        {
            int temp=b;
            b=a%b;
            a=temp;
        }
        return a;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *temp=head;
        while(temp->next!=NULL)
        {
            ListNode *hcf= new ListNode;
            hcf->val=gcd(temp->val,temp->next->val);
            ListNode* nextp= temp->next;
            temp->next=hcf;
            hcf->next=nextp;
            temp=nextp;
        }
        return head;
    }
};