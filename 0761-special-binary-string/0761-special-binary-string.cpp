class Solution {
public:
    string makeLargestSpecial(string s) {
        int n=s.size();
        if(s.empty())return "";
        vector<string>ar;
        int cnt=0,init=0;
        for(int i=0;i<n;++i)
        {
            cnt+=(s[i]=='1')?1:-1;
            if(cnt==0)
            {
                string st=s.substr(init+1,i-init-1);
                ar.push_back("1"+makeLargestSpecial(st)+"0");
                init=i+1;
            }
        }
        sort(ar.begin(),ar.end(),greater<string>());
        string ans;
        for(auto& it:ar)ans+=it;
        return ans;
    }
};