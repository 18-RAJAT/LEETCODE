class Solution {
public:
    int romanToInt(string s) {
        map<tuple<char,char>,int>mp;
        mp[{'I','V'}]=4;
        mp[{'I','X'}]=9;
        mp[{'X','L'}]=40;
        mp[{'X','C'}]=90;
        mp[{'C','D'}]=400;
        mp[{'C','M'}]=900;
        map<char,int>mp1;
        mp1['I']=1;
        mp1['V']=5;
        mp1['X']=10;
        mp1['L']=50;
        mp1['C']=100;
        mp1['D']=500;
        mp1['M']=1000;
        int ans=0;
        for(int i=0;i<s.size();++i)
        {
            (i+1<s.size() && mp.count({s[i],s[i+1]})?ans+=mp[{s[i],s[i+1]}],i++:ans+=mp1[s[i]]);
        }
        return ans;
    }
};