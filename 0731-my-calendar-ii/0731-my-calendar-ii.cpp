class MyCalendarTwo {
public:
    map<int,int>bookings;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        bookings[start]++,bookings[end]--;
 
        int activeBooking=0;
        for(auto& it:bookings)
        {
            activeBooking+=it.second;
            if(activeBooking>=3)
            {
                bookings[start]--,bookings[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */