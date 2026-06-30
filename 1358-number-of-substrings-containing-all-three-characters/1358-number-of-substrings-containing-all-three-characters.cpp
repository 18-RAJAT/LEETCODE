class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int count=0,x=-1,y=-1,z=-1; 
        for(int i=0;i<n;++i)
        {
            if(s[i]=='a')x=i;
            else if(s[i]=='b')y=i;
            else z=i;
            count+=(1+min({x,y,z}));
        }
        return count;
    }
};