class Solution {
public:
    string minWindow(string s, string t) {
        
        int n=s.size();
        int m=t.size();
        string res="";
        
        if(n<m)
        {
            return res;
        }
        map<char,int>patternHash,stringHash;
        for(auto it:t) patternHash[it]++;
        
        int i=0;
        int j=0;
        int count=0;
        int len=INT_MAX;
        int startIndex=-1;
        
        while(j<n)
        {
            stringHash[s[j]]++;
            
            if(stringHash[s[j]]<=patternHash[s[j]])
            {
                count++;
            }
            if(count==m)
            {                
                while(stringHash[s[i]]>patternHash[s[i]] or patternHash[s[i]]==0)
                {
                    
                    if(stringHash[s[i]]>patternHash[s[i]])
                    stringHash[s[i]]--;
                    i++;
                    
                }
                int found=j-i+1;
                if(len>found)
                {
                    len=found;
                    startIndex=i;
                }
            }
            j++;
        }
        if(startIndex==-1)
        {
            return "";
        }
        return s.substr(startIndex,len);
    }
};