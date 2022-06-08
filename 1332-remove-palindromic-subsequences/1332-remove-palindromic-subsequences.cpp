class Solution {
public:
    int removePalindromeSub(string s) {
        string str=s;
            reverse(str.begin(),str.end());
            if(str==s){return 1;}
            return 2;
    }
};