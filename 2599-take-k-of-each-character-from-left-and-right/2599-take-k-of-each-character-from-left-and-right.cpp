class Solution {
public:
    int takeCharacters(string s, int k) {
        int n=s.size();
        int ch[3];
        fill(ch,ch+3,0);
        for(char& it:s)ch[it-'a']++;
        if(ch[0]<k || ch[1]<k || ch[2]<k)return -1;
        int ans=0,cnt=0;
        for(int i=0;i<n;++i)
        {
            int c=s[i]-'a';
            ch[c]--;
            while(ch[c]<k)
            {
                ch[s[cnt++]-'a']++;
            }
            ans=max(ans,i-cnt+1);
        }
        return n-ans;
    }
};