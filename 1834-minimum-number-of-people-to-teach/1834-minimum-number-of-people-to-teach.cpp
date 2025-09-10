class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m=languages.size();
        vector<unordered_set<int>>res(m);
        for(int i=0;i<m;++i)
        {
            for(auto& it:languages[i])
            {
                res[i].insert(it);
            }
        }
        unordered_set<int>st;
        for(auto& it:friendships)
        {
            int a=it[0]-1,b=it[1]-1;
            bool ok=false;
            for(auto& it1:res[a])
            {
                if(res[b].count(it1))
                {
                    ok=true;
                    break;
                }
            }
            if(!ok)
            {
                st.insert(a);
                st.insert(b);
            }
        }
        if(st.empty())return 0;
        vector<int>cnt(n+1,0);
        for(auto& it:st)
        {
            for(auto& it1:res[it])
            {
                cnt[it1]++;
            }
        }
        int mx=0;
        for(auto& it:cnt)
        {
            mx=max(mx,it);
        }
        return st.size()-mx;
    }
};