class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans=0;
        string s=to_string(n);
        int res=0;
        for(auto& it:s)
        {
            if(it!='0')ans=ans*10+(it-'0');
            res+=(it-'0');
        }
        return ans*res;
    }
};