class LRUCache {
public:
    class Node
    {
        public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int key,int val)
        {
            this->key=key;
            this->val=val;
        }
    };
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    int cap;
    unordered_map<int,Node*> m;

    LRUCache(int capacity) {
    cap=capacity;
    head->next=tail;
    tail->prev = head;
    }
    void add(Node* newnode)
    {
        Node* temp= head->next;
        head->next=newnode;
        newnode->prev=head;
        newnode->next=temp;
        temp->prev=newnode;
    }
    void del(Node* delnode)
    {
        Node *prevv= delnode->prev;
        Node *nextt= delnode->next;
        prevv->next=nextt;
        nextt->prev=prevv;
    }
    int get(int key) {
        if(m.find(key)!=m.end())
        {
            Node* resnode = m[key];
            int ans = resnode->val;
            m.erase(key);
            del(resnode);
            add(resnode);
            m[key]=head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end())
        {
            Node* curr = m[key];
            m.erase(key);
            del(curr);
        }
        if(m.size()==cap)
        {
            m.erase(tail->prev->key);
            del(tail->prev);
        }
        add(new Node(key,value));
        m[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */