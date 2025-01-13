class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        for(int i=0;i<n;++i)mp[s[i]]++;
        int count=0;
        for(auto& it:mp)
        {
            if(it.second%2==0)count+=2;
            else count+=1;
        }
        return count;
    }
};