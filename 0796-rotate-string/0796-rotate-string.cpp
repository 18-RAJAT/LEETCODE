class Solution {
public:
    bool rotateString(string s, string g) {
        int n=s.length();
        int m=g.length();
        auto temp=g+g;
        
        if(n!=m)
        {
            return false;
        }
        if(temp.find(s)!=-1)
        {
            return true;
        }
        return false;
    }
};