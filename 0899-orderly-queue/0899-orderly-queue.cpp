class Solution {
public:
    string orderlyQueue(string s, int k) {
        int n=s.size();
        if(k>1)
        {
            // string temp=s+s;
            // string ans=s;
            // for(int i=1;i<n;++i)
            sort(s.begin(),s.end());
            return s;
        }
        string temp=s;
        for(int i=1;i<=n;++i)
        {
            temp=min(temp,s.substr(i)+s.substr(0,i));
        }
        return temp;
    }
};