class Solution {
public:
    string makeFancyString(string s) {
        int n=s.size();
        if(n<3)
        {
            return s;
        }
        string ans;
        ans.push_back(s[0]);
        ans.push_back(s[1]);
        int i=2;
        while(i<n)
        {
            if(s[i]==s[i-1] && s[i]==s[i-2])
            {
                char ch=s[i];
                while(i<n && s[i]==ch)
                {
                    i++;
                }
            }
            else
            {
                ans.push_back(s[i]);
                i++;
            }
        }
        return ans;
    }
};