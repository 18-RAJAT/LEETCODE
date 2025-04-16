class Solution {
public:
    long long countGood(vector<int>& a,int k){
        long long ans=0;
        unordered_map<int,int>mp;
        int p=0,l=0,r=0,n=a.size();
        while(r<n)
        {
            p+=mp[a[r]];
            mp[a[r]]++;
            if(p>=k)
            {
                while(p>=k && l<r)
                {
                    ans+=n-r;
                    mp[a[l]]--;
                    p-=mp[a[l]];
                    if(mp[a[l]]==0)mp.erase(a[l]);
                    l++;
                }
            }
            r++;
        }
        return ans;
    }
};