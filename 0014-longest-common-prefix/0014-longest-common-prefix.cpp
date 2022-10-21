class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==0)
        {
            return "";
        }
        string answer;
        sort(strs.begin(),strs.end());
        string a=strs[0];
        string b=strs[n-1];
        
        int x=a.size();
        for(int i=0;i<x;++i)
        {
            if(a[i]==b[i])
            {
                answer+=a[i];
            }
            else
            {
                break;
            }
        }
        return answer;
    }
};