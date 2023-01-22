class Solution {
public:
    bool isPalindrome(string s)
    {
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void solve(string s,int i,vector<string>&temp,vector<vector<string>>&ans)
    {
        if(i==s.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<s.size();j++)
        {
            string t=s.substr(i,j-i+1);
            if(isPalindrome(t))
            {
                temp.push_back(t);
                solve(s,j+1,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        solve(s,0,temp,ans);
        return ans;      
    }
};