class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        vector<int>ans;
        for(int i=0;i<n;++i)
        {
            int cnt=0;
            for(int j=0;j<bank[i].size();++j)
            {
                if(bank[i][j]=='1')
                {
                    cnt++;
                }
            }
            if(cnt!=0)
            {
                ans.push_back(cnt);
            }
        }
        if(ans.size()==0)
        {
            return 0;
        }
        int res=0;
        for(int i=0;i<ans.size()-1;++i)
        {
            res+=ans[i]*ans[i+1];
        }
        return res;
    }
};