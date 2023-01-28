class SummaryRanges {
public:
    set<int>st;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        st.insert(value);
        return;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>ans;
        auto it=st.begin();
        vector<int>a={*it,*it};it++;
        while(it!=st.end())
        {
            if(*it==1+a[1])
            {
                a[1]=1+a[1];
            }
            else
            {
                ans.push_back(a);
                a={*it,*it};
            }
            it++;
        }
        ans.push_back(a);
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */