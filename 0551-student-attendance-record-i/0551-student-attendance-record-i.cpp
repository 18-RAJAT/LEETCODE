class Solution {
public:
    bool checkRecord(string s) {
        int n=s.size();
        int Absent=0,Late=0;
        for(int i=0;i<n;++i)
        {
            if(s[i]=='A')
            {
                Absent++;
                Late=0;
            }
            else if(s[i]=='L')
            {
                Late++;
            }
            else if(s[i]=='P')
            {
                Late=0;
            }
            if(Absent>=2 || Late>=3)
            {
                return false;
            }
        }
        return true;
    }
};