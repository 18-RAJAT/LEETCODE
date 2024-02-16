class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(auto& i:arr)
        {
            mp[i]++;
        }
        vector<int>freq;
        for(auto& i:mp)
        {
            freq.push_back(i.second);
        }
        sort(freq.begin(),freq.end());
        int n=freq.size();
        for(int i=0;i<n;++i)
        {
            if(k>=freq[i])
            {
                k-=freq[i];
                freq[i]=0;
            }
            else
            {
                freq[i]-=k;
                k=0;
                break;
            }
        }
        int ans=0;
        for(int i=0;i<n;++i)
        {
            if(freq[i]!=0)
            {
                ans++;
            }
        }
        return ans;
    }
};