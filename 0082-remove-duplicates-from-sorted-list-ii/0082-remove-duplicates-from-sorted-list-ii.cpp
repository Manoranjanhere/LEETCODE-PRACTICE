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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* tail = head;
        unordered_map<int,int> mp;
        while(tail)
        {
            mp[tail->val]++;
            tail=tail->next;
        }
        tail = head;
        ListNode* prev;
        while(tail)
        {
            if(mp[tail->val]>1)
            {
                if(tail==head)
                {
                    head=head->next;
                }
                else
                {
                    prev->next=prev->next->next;
                }
            }
            else
            {
                prev=tail;
            }
            tail=tail->next;
        }
        return head;
    }
};