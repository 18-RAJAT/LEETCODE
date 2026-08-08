class Solution{
public:
    vector<int> validSequence(string word1,string word2){
        int m=word1.size(),n=word2.size();
        vector<int>suf(m,-1);
        for(int i=m-1,j=n-1;~i;--i)
        {
            suf[i]=n-j-1;
            if(j>=0 && word1[i]==word2[j])--j;
        }
        vector<int>ans;
        bool ok=false;
        int j=0;
        for(int i=0;i<m && j<n;++i)
        {
            if(word1[i]==word2[j])
            {
                ans.push_back(i);
                j++;
            }
            else if(!ok && suf[i]>=n-j-1)
            {
                ok=true;
                ans.push_back(i);
                j++;
            }
        }
        if(j<n)return {};
        return ans;
    }
};