class Solution {
public:
    int maxProduct(int n) {
        string s=to_string(n);
        vector<int>ar;
        for(auto& it:s)ar.push_back(it-'0');
        sort(rbegin(ar),rend(ar));
        return ar[0]*ar[1];
    }
};