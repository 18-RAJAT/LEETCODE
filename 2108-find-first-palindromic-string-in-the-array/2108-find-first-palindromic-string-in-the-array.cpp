class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        int n=words.size();
        function<bool(string)>is_palindrome=[&](string s)
        {
            int i=0,j=s.size()-1;
            while(i<=j)
            {
                if(s[i]!=s[j])
                    return false;
                i++;
                j--;
            }
            return true;
        };
        for(int i=0;i<n;++i)
        {
            if(is_palindrome(words[i]))
            {
                return words[i];
            }
        }
        return "";
    }
};