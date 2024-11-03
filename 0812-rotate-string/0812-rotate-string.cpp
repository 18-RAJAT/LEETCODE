class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.length(),m=goal.length();
        string temp=goal+goal;
        if(n!=m)return false;
        if(~temp.find(s))return true;
        return false;
    }
};