#define ll long long
#define sza(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define revall(x) x.rbegin(), x.rend()
#define sortall(x) sort(all(x))

class Solution {
public:
    string reverseWords(string s) {
        int l=0,r=0;
        int n=s.size();
        while(l<n)
        {
            while(r<n and s[r]!=' ')r++;
            // reverse(all(s));
            reverse(s.begin()+l,s.begin()+r);
            l=r+1;r=l;
        }
        return s;
    }
};