class Solution {
public:
    string getSmallestString(int n, int k) {
        
        string st(n,'a');
        
        k -= n;
        
        for(int i=n-1;k>0;--i)
        {
                int add = min(k,25);
                st[i] += add;
                k -= add;
        }
        return st;
    }
};