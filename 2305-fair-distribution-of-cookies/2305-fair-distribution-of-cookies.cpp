class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int ans=INT_MAX;
        function<void(vector<int>&,vector<int>&,int,int)>recur=[&](vector<int>&cookies,vector<int>&take,int ind,int k)->void
        {
            if(cookies.size()<=ind)
            {
                int tmp=0;
                for(int i=0;i<k;++i)
                {
                    tmp=max<int>(tmp,take[i]);
                }
                ans=min<int>(tmp,ans);
                return;
            }
            for(int i=0;i<k;++i)
            {
                take[i]+=cookies[ind];
                recur(cookies,take,ind+1,k);
                take[i]-=cookies[ind];
            }
        };
        vector<int>take(k,0);
        recur(cookies,take,0,k);
        return ans;
    }
};