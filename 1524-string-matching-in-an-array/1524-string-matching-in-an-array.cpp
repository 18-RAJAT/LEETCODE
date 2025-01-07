class Solution {
public:
    bool Kmp(string& word,string& str)
    {
        int n=word.size();
        vector<int>lps(n,0);
        int i=1,length=0;
        while(i<n)
        {
            if(word[i]==word[length])
            {
                length++,lps[i]=length,i++;
            }
            else    
            {
                (length!=0)?length=lps[length-1]:lps[i]=0,i++;
            }
        }
        int m=str.size();
        int p=0,j=0;
        int count=0;
        while(p<m && j<n)
        {
            if(str[p]==word[j])
            {
                p++,j++;
            }
            else
            {
                (j!=0)?j=lps[j-1]:p++;
            }
            if(j==n)
            {
                count++;
                if(count>=2)return true;
                j=lps[j-1];
            }
        }
        return false;
    }
    vector<string>stringMatching(vector<string>&words){
        string str="";
        int n=words.size(),i=0;
        for(auto& it:words)
        {
            i++,str+=it;
            if(i!=n)str+="#";
        }
        vector<string>ans;
        for(auto& it:words)
        {
            if(Kmp(it,str))
            {
                ans.push_back(it);
            }
        }
        return ans;
    }
};