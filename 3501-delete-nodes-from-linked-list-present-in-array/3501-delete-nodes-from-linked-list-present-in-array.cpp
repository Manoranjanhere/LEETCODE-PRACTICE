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
        ListNode* head2= new ListNode();
        ListNode* tail = head2;
        unordered_set<int> st;
        for(int i:nums)
        {
            st.insert(i);
        }
        while(head)
        {
            if(st.find(head->val)==st.end())
            {
                tail->next= new ListNode(head->val);
                tail= tail->next;
            }
            head=head->next;
        }
        return head2->next;
    }
};