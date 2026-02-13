class Solution {
public:
    int recur(string& s,char ch1,char ch2)
    {
        int res=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        int count=0;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]==ch1)count++;
            else if(s[i]==ch2)count--;
            else
            {
                mp.clear();
                mp[0]=i;
                count=0;
                continue;
            }
            if(mp.find(count)==mp.end())mp[count]=i;
            else res=max(res,i-mp[count]);
        }
        return res;
    }
    int single(string& s)
    {
        int ans=0,left=0;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]!=s[left])
            {
                ans=max(ans,i-left);
                left=i;
            }
        }
        ans=max<int>(ans,s.size()-left);
        return ans;
    }
    int longestBalanced(string& s)
    {
        unordered_map<string,int>mp;
        mp["0-0"]=-1;
        int ans=0;
        int ar[3]={0,0,0};
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='a')ar[0]++;
            else if(s[i]=='b')ar[1]++;
            else ar[2]++;
            string st=to_string(ar[1]-ar[0])+"-"+to_string(ar[2]-ar[0]);
            if(mp.find(st)==mp.end())mp[st]=i;
            else ans=max(ans,i-mp[st]);
        }
        ans=max(ans,recur(s,'a','b'));
        ans=max(ans,recur(s,'b','c'));
        ans=max(ans,recur(s,'c','a'));
        ans=max(ans,single(s));
        return ans;
    }
};