class Solution {
public:
    void generate(int n,vector<string>& ans,vector<char>& chk,string& happy)
    {
        if(n<=happy.size())
        {
            ans.push_back(happy);
            return;
        }
        for(auto& it:chk)
        {
            if(happy.empty() || happy.back()!=it)
            {
                happy+=it;
                // cur.push_back(it);
                generate(n,ans,chk,happy);
                // cur.pop_back();
                happy.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
        vector<string>ans;
        string happy="";
        vector<char>chk={'a','b','c'};
        generate(n,ans,chk,happy);
        sort(ans.begin(),ans.end());
        return k<=ans.size()?ans[k-1]:"";
    }
};