class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        int l=0,r=0;
        for(int i=0;i<n;++i)
        {
            if(s[i]=='(')
            {
                l++;
                r++;
            }
            else if(s[i]==')')
            {
                l--;
                r--;
            }
            else
            {
                l--;
                r++;
            }
            if(r<0)return false;
            l=max(l,0);
        }
        return l==0?true:false;
    }
};