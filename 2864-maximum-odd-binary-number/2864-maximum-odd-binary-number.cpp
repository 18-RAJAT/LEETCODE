class Solution { 
public: 
    string maximumOddBinaryNumber(string s) { 
        sort(s.begin(),s.end(),greater<int>());
        for(int i=s.size()-1;~i;--i)
        {
            if(s[i]=='1')
            {
                swap(s[i],s[s.size()-1]);
                break;
            }
        }
        return s;
    } 
};