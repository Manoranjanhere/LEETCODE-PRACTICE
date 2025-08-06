
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* head= new ListNode(0);
	ListNode* tail =head;
	int rem=0;
        while(l1||l2||rem)
	{
		int sum=rem;
		if(l2)
		{
			sum+=l2->val;
			l2=l2->next;
		}
		if(l1)
		{
			sum+=l1->val;
			l1=l1->next;
		}
		tail->next = new ListNode(sum%10);
		rem=sum/10;
		tail=tail->next;

	}
	return head->next;
    }
};