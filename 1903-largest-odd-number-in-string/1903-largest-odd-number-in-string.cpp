class Solution {
public:
    string largestOddNumber(string n) {
        for(int i=n.size();i>=0;--i)
        {
                if((n[i]-'0')%2)return n.substr(0,i+1);
        }
            return string();
    }
};