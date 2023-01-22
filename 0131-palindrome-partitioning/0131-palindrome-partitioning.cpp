class Solution {
public:
    
    void sol(string s,int i,vector<string>&temp,vector<vector<string>>&ans)
    {
        function<bool(string)>isPal=[&](string s)
        {
            int i=0;
            int j=s.size()-1;
            
            while(i<j)
            {
                if(s[i]==s[j])
                {
                    i++;
                    j--;
                }
                else
                {
                    return false;
                }
            }
            return true;
        };
        
        if(i==s.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<s.size();++j)
        {
            if(isPal(s.substr(i,j-i+1)))
            {
                temp.push_back(s.substr(i,j-i+1));
                sol(s,j+1,temp,ans);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        sol(s,0,temp,ans);
        return ans;
    }
};