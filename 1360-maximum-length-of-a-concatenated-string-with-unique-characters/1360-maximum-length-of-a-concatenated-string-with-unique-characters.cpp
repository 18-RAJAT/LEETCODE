class Solution {
public:
    map<string,int>dp;
    bool possible(string s)
    {
        sort(s.begin(),s.end());
        int n=s.size();
        for(int i=0;i<s.size();++i)
        {
            if(s[i]==s[i+1])return false;
        }
        return true;
    }
    int helper(vector<string>&arr,int idx,string s)
    {
        if(idx<0)return 0;
        string key=s+" "+to_string(idx);
        if(dp.count(key))return dp[key];
        string tp=s+arr[idx];
        if(possible(tp))
        {
            int sz=arr[idx].size();
            int res=max(sz+helper(arr,idx-1,tp),helper(arr,idx-1,s));
            dp.insert(make_pair(key,res));
            return res;
        }
        int r=helper(arr,idx-1,s);
        dp.insert(make_pair(key,r));
        return r;
    }
    int maxLength(vector<string>& arr) {
        string s="";
        return helper(arr,arr.size()-1,s);
    }
};