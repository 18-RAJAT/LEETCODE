class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<int>ans;
        if(n<m)return ans;
        vector<int>freq(26,0);
        vector<int>freq1(26,0);
        for(int i=0;i<m;i++)
        {
            freq[s[i]-'a']++;
            freq1[p[i]-'a']++;
        }
        if(freq==freq1)ans.push_back(0);
        for(int i=m;i<n;i++)
        {
            freq[s[i]-'a']++;
            freq[s[i-m]-'a']--;
            if(freq==freq1)ans.push_back(i-m+1);
        }
        return ans;      
    }
};