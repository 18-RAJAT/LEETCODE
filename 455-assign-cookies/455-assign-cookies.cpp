// bool comapre(vector<int>&a,vector<int>&b)
// {
//         return a[1]<b[1];
// }

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
            
            int i=0;
            for(int j=0;j<s.size() and i<g.size();++j)
            {
                    if(g[i]<=s[j]){i++;}
            }
            return i;
    }
};