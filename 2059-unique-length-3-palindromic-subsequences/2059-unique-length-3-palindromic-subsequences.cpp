class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        int ans=0;
        for(char ch='a';ch<='z';++ch)
        {
            int i=0,j=n-1;
            while(i<n && s[i]!=ch)
            {
                i++;
            }
            while(j>=0 && s[j]!=ch)
            {
                j--;
            }
            if(i<j)
            {
                set<char>st;
                for(int k=i+1;k<j;++k)
                {
                    st.insert(s[k]);
                }
                ans+=st.size();
            }
        }
        return ans;
    }
};