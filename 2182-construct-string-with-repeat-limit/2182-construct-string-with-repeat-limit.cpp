class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int n=s.size();
        int count=0,idx=0;
        sort(s.begin(),s.end(),greater<int>());
        for(int i=0;i<n;++i)
        {
            (i==0 || s[i]==s[i-1])?count+=1:count=1;
            while(idx<n && s[i]==s[idx])idx++;
            if(count==repeatLimit+1)
            {
                if(idx<n)swap(s[i],s[idx]);
                else return s.substr(0,i);
            }
        }
	    return s;
    }
};