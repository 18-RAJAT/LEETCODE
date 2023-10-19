class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n=ransomNote.size();
        int m=magazine.size();
        if(m<n)
        {
            return false;
        }
        int a[26];
        memset(a,0,sizeof(a));
        auto convert=[&](char c)->int
        {
            return c-'a';
        };
        for(int i=0;i<m;++i)
        {
            a[convert(magazine[i])]++;
        }
        for(int i=0;i<n;++i)
        {
            if(a[convert(ransomNote[i])]==0)
            {
                return false;
            }
            a[convert(ransomNote[i])]--;
        }
        return true;      
    }
};