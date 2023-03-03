class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int n=haystack.size();
        int m=needle.size();
        if(n==0)return -1;
        if(m==0)return 0;
        int i=0;
        while(i<n)
        {
            if(haystack[i]==needle[0])
            {
                int j=0;
                int k=i;
                while(j<m or k<n)
                {
                    if(haystack[k]!=needle[j])
                    {
                        break;
                    }
                    j++;
                    k++;
                }
                if(j==m)return i;
            }
            ++i;
        }
        return -1;
    }
};