class Solution {
public:
    bool isPalindrome(string s) {
      
        string str="";
        for(int i=0;i<s.size();i++)
            if(isalpha(s[i]) or isdigit(s[i])){str+=tolower(s[i]);} 
        return str==string(str.rbegin(),str.rend());
    }
};