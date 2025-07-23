class Solution {
public:
    pair<string,int>recur(bool ok,string s,int x)
    {
        stack<char>st;
        int chA='a',chB='b';
        if(!ok)swap(chA,chB);
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
            pair<string,int>p=recur(true,s,x);
            ans+=p.second+recur(false,p.first,y).second;
        }
        else
        {
            pair<string,int>p=recur(false,s,y);
            ans+=p.second+recur(true,p.first,x).second;
        }
        return ans;
    }
};