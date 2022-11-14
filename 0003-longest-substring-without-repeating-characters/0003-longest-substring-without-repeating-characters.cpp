class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
            if(n==0){return 0;}
            set<char>st;
            int maxSize=0;
            int i=0,j=0;
            while(j<n)
            {
                    if(st.count(s[j])==0)
                    {
                            st.insert(s[j]);
                            maxSize=max(maxSize,(int)st.size());j++;
                    }
                    else
                    {
                            st.erase(s[i]);i++;
                    }
            }
            return maxSize;
    }
};