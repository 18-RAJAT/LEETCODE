class Solution {
public:
    int longestDecomposition(string text) {
        
        map<string,int>mp;
        int n = text.size();
        
        int i=0,j=n-1;
        int l=0,r=n-1;
        
        string LS,RS;
        
        int answer=0;
        
        while(i<j)
        {
            LS = text.substr(l,i-l+1);
            RS = text.substr(j,r-j+1);
            
            if(LS == RS)
            {
                mp[LS]++;
                l = i+1;
                r = j-1;
                
                answer += 2;
            }
            //Using 2 pointers 
            i++;
            j--;
        }
        
        if(mp.size() == 0)
        {
            return 1;
        }
        
        if(l>r)
        {
            return answer;
        }
        return answer+1;
    }
};