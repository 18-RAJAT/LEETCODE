class Solution {
public:
    string answerString(string word, int nf) {
        int n=word.size();
        if(nf==1)return word;
        char c=*max_element(word.begin(),word.end());
        string ans="";
        for(int i=0;i<n;++i)
        {
            if(word[i]==c)
            {
                int mn=min((int)(n-i),n-nf+1);
                if(mn<=0)continue;
                string s=word.substr(i,mn);
                if(s>ans)ans=s;
            }
        }
        return ans;
    }
};