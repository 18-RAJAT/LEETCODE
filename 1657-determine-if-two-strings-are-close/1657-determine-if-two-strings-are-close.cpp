class Solution {
public:
    bool closeStrings(string word1, string word2) {
       int n=word1.size();
       int m=word2.size();
        if(n!=m)     
        {
            return false;
        }
        // int ct=0;
        // for(int i=0;i<26;++i)
        // {
        //     word1[i-'a'];
        //     word2[i-'b'];
        // }
        int a[26];
        int b[26];
        // for(char &c:word1){
        //     a[c-'a']++;
        // }
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i=0;i<n;++i)
        {
            a[word1[i]-'a']++;
        }
        for(int i=0;i<m;++i)
        {
            b[word2[i]-'a']++;
        }


        
        // for(int i=0;i<26;++i)
        // {
        //     if(word1[0]!=word2[0] and word1[n-1]!=word2[m-1])
        //     {
        //         return false;
        //     }
        // }
        for(int i=0;i<26;i++)
        {
            // if((a[i]==0 and b[i]!=0) or (a[i]!=0 and b[i]==0) and a[i]!=b[i])
            if((a[i]==0 and b[i]) or (a[i] and b[i]==0))
            {
                return false;
                // ct++;
            }
            // if(a[i]!=b[i])
            // {
            //     return false;
            // }
        }
        sort(a,a+26);
        sort(b,b+26);
        // for(int i=0;i<n;++i)
        // {
        //     for(int j=0;j<m;++j)
        //     {
        //         cout<<a[i]<<" "<<b[j]<<"\n";
        //     }
        // }
        for(int i=0;i<26;++i)
        {
            if(a[i]!=b[i])
            {
                return false;
            }
        }
        return true;
    }
};