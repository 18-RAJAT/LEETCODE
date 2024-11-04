class Solution {
public:
    string compressedString(string word) {
        int n=word.size(),ans=1;
        string s;
        char ch=word[0];
        for(int i=1;i<n;++i)
        {
            if(word[i]==ch && ans<9)ans++;
            else
            {
                s+=to_string(ans)+ch;
                ans=1;
                ch=word[i];
            }
        }
        s+=to_string(ans)+ch;
        return s;
    }
};