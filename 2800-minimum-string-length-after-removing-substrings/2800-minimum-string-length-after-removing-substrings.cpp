class Solution {
public:
    int minLength(string s) {
        bool ok=1;
        while(ok)
        {
            if(s.find("AB")!=string::npos)
            {
                s.replace(s.find("AB"),2,"");
            }
            else if(s.find("CD")!=string::npos)
            {
                s.replace(s.find("CD"),2,"");
            }
            else
            {
                ok=0;
            }
        }
        return s.size();
    }
};