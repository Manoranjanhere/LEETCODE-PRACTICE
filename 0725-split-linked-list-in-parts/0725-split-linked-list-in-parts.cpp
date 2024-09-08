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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        ListNode *temp=head;
        int c=0;
        while(temp!=NULL)
        {
            c++;
            temp=temp->next;
        }
        int q = c/k;
        int r = c%k;
        temp=head;
        ListNode* h = temp;
        ans.push_back(h);
        while(temp!=NULL)
        {
            int run=1;
            int qu=q;
            if(r)
            {
                r--;
                qu++;
            }
            while(run<qu)
            {
                run++;
                temp=temp->next;
            }
            ListNode* cut = temp;
            h=temp->next;
            temp=temp->next;
            cut->next=NULL;
            if(h!=NULL)
            {
                ans.push_back(h);
            }
        }
        int n = ans.size();
        cout<<n;
        while(k>n)
        {
            n++;
            ans.push_back(NULL);
        }
        return ans;
    }
};