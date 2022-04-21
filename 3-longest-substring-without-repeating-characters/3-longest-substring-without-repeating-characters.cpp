class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        vector<int> dictinct(256, -1);
       
        int max_length = 0, start = -1;
        
        for (int i = 0; i < s.length(); i++) {
        
            if (dictinct[s[i]] > start)
                
                start = dictinct[s[i]];
                
                dictinct[s[i]] = i;
           
            max_length = max(max_length, i - start);
        }
        
        return max_length;
        
    }
};