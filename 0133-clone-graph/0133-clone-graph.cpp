/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp;
        if(node==NULL)return NULL;
        Node* head = new Node(node->val);
        mp[node]=head;
        stack<Node*> st;
        st.push(node);
        while(!st.empty())
        {
            Node* curr = st.top();
            st.pop();
            for(Node* i:curr->neighbors)
            {
                if(mp.find(i)==mp.end())
                {
                    st.push(i);
                    mp[i]=new Node(i->val);
                }
                mp[curr]->neighbors.push_back(mp[i]);
            }
        }
        return head;
    }
};