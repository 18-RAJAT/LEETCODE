class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        // map<string,int>mp;
        // for(auto it:ideas)
        // {
        //     mp[it]++;
        // }
        // int tmp=mp.size();
        
        vector<set<string>>grp(26);
        for(auto &it:ideas)
        {
            grp[it[0]-'a'].insert(it.substr(1));
        }
        long long naming =0;
        //here same itr
        for(long long i=0;i<26;++i)
        {
            //string <- s[0] and next chk s[1] with j
            for(long long j=i+1;j<26;++j)
            {
                long long suff=0;
                for(auto& it:grp[i])
                {
                    suff+=grp[j].count(it);
                }
                /*
                    1st->2nd->......->>mve->>mve->>mve......
                    ----
                    ||||
                    i-suff*j-suff;(flf)and *2 to chk;
                */
                naming +=(grp[i].size()-suff)*(grp[j].size()-suff);
            }
        }
        return 2*naming;
    }
};