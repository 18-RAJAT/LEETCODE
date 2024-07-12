class Solution {
public:
    pair<string, int> solve(bool handleAB, string s, int x) {
        stack<char>st;
        int chA='a',chB='b';
        if(!handleAB)swap(chA,chB);
        int ans=0;
        for(auto& it:s)
        {
            if(!st.empty() && st.top()==chA && it==chB)
            {
                ans+=x;
                st.pop();
            }
            else
            {
                st.push(it);
            }
        }
        string rem="";
        while (!st.empty())
        {
            rem+=st.top();
            st.pop();
        }
        reverse(rem.begin(),rem.end());
        return make_pair(rem,ans);
    }
    int maximumGain(string s, int x, int y) {
        int ans=0;
        if(x>y)
        {
            pair<string,int>p=solve(true,s,x);
            ans+=p.second+solve(false,p.first,y).second;
        }
        else
        {
            pair<string,int>p=solve(false,s,y);
            ans+=p.second+solve(true,p.first,x).second;
        }
        return ans;
    }
};