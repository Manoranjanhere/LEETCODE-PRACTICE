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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        int l=0,r=n-1,t=0,b=m-1;
        while(head!=NULL)
        {
            for(int i=l;i<=r;i++)
            {
                if(head!=NULL)
                {
                    ans[t][i]=head->val;
                    head=head->next;
                }
                else
                {
                    break;
                }
            }
            t++;
            for(int i=t;i<=b;i++)
            {
                if(head!=NULL)
                {
                    ans[i][r]=head->val;
                    head=head->next;
                }
                else
                {
                    break;
                }
            }
            r--;
            for(int i=r;i>=l;i--)
            {
                if(head!=NULL)
                {
                    ans[b][i]=head->val;
                    head=head->next;
                }
                else
                {
                    break;
                }
            }
            b--;
            for(int i=b;i>=t;i--)
            {
                if(head!=NULL)
                {
                    ans[i][l]=head->val;
                    head=head->next;
                }
                else
                {
                    break;
                }
            }
            l++;
        }
        return ans;
    }
};