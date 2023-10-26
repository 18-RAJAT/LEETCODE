#define ll long long int
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        ll n=arr.size();
        sort(arr.begin(),arr.end());
        unordered_map<int,int>mp;
        for(int i=0;i<n;++i)
        {
            mp[arr[i]]=i;
        }
        ll dp[n];
        for(int i=0;i<n;++i)
        {
            dp[i]=1;
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<i;++j)
            {
                if(arr[i]%arr[j]==0)//arr[j] is the left child of arr[i]
                {
                    ll right=(arr[i]/arr[j])%1000000007;//right is the right child of arr[j]
                    if(mp.find(right)!=mp.end())//right is present in the array
                    {
                        dp[i]+=dp[j]*dp[mp[right]]%1000000007;//dp[j] is the number of trees in the left subtree and dp[mp[right]] is the number of trees in the right subtree
                        dp[i]%=1000000007;
                    }
                }
            }
        }
        ll ans=0;
        for(int i=0;i<n;++i)
        {
            ans+=dp[i];
            ans%=1000000007;
        }
        return ans%1000000007;      
    }
};