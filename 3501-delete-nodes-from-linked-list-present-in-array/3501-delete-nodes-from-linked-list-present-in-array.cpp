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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    unordered_set<int> store;
    int n = nums.size();
    for(int i=0;i<n;i++)
    {
        store.insert(nums[i]);
    }
    while(store.find(head->val)!=store.end())
    {
        head=head->next;
    }
    ListNode *temp=head;
    while(temp!=NULL&&temp->next!=NULL)
    {
        
        if(store.find(temp->next->val)!=store.end())
        {
            temp->next=temp->next->next;
        }
        else
        {
            temp=temp->next;
        }
    }
    return head;
    }
};