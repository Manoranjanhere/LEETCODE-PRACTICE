/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        if(head==NULL)
        {
            return NULL;
        }
        while(temp!=NULL)
        {
            Node* temp1= temp->next;
            temp->next=new Node(temp->val);
            temp->next->next=temp1;
            temp=temp1;
        }
        temp=head;
        while(temp!=NULL)
        {
            
            temp->next->random=(temp->random!=NULL)?temp->random->next:NULL;
            
            temp=temp->next->next;
            
        }
        temp=head;
        Node* temp1= head->next;
        Node* store = head->next;
        while(temp!=NULL)
        {
            temp->next=temp->next->next;
            temp1->next=(temp->next!=NULL)?temp1->next->next:NULL;
            temp=temp->next;
            temp1=temp1->next;

        }
        return store;
    }
};