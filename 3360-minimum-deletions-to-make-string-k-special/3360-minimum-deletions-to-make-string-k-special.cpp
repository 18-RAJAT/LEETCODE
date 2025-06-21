class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char,int>mp;
        for(auto& it:word)mp[it]++;
        vector<int>arr;
        for(auto& it:mp)
        {
            arr.push_back(it.second);
        }
        sort(arr.begin(),arr.end());
        int ans=INT_MAX;
        for(int i=0;i<arr.size();++i)
        {
            int tmp=0,x=arr[i];
            for(auto& it:arr)
            {
                if(it<x)tmp+=it;
                else if(x+k<it)tmp+=it-(x+k);
            }
            ans=min(ans,tmp);
        }
        return ans;
    }
};