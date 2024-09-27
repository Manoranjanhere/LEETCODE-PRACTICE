class MyCalendarTwo {
public:
    unordered_map<int,int> st;
    unordered_map<int,int> db;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(auto i:db)
        {
            if(max(start,i.first)<min(i.second,end))
            {
                return false;
            }
        }
        for(auto i:st)
        {
            if(max(start,i.first)<min(i.second,end))
            {
                db.insert({max(start,i.first),min(i.second,end)});
            }
        }
        st.insert({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */