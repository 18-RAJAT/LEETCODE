class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        vector<int>ans,chk(26,0);
        for(int i=0;i<n;++i)chk[s[i]-'a']=i;
        set<char>st;
        int res=0;
        for(int i=0;i<n;++i)
        {
            st.insert(s[i]);
            if(i==chk[s[i]-'a'])st.erase(s[i]);
            if(st.empty())
            {
                ans.push_back(i-res+1);
                res=i+1;
            }
        }
        return ans;
    }
};