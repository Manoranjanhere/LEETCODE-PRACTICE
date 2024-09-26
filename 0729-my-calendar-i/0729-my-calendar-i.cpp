class MyCalendar {
public:
    vector<pair<int,int>>booki;
    MyCalendar() {
        
    }
    bool book(int start, int end) {
        for(auto i:booki)
        {
            if(max(i.first,start)<min(i.second,end))
            {
                return false;
            }
        }
        booki.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */