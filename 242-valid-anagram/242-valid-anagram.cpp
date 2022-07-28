class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        // int ans s==t;
        // return ans;
        return s==t;
    }
};