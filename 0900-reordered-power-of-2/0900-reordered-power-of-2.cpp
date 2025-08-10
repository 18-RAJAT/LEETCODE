class Solution {
public:
    bool reorderedPowerOf2(int n) {
        unordered_set<string>st;
        for(int i=0;i<30;++i)
        {
            int num=pow(2,i);
            string s=to_string(num);
            sort(s.begin(),s.end());
            st.insert(s);
        }
        string s=to_string(n);
        sort(s.begin(),s.end());
        
        return st.find(s)==st.end()?false:true;
    }
};