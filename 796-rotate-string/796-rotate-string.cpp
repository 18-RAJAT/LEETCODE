class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()){return 0;}
            s+=s;
            if(s.find(goal)!=string::npos){return true;}
            return false;
    }
};