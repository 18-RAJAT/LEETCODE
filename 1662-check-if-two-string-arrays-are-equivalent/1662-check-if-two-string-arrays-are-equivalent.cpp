class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a,b;
        for(auto it:word1)
        {
            a+=it;
        }
        
        for(auto it:word2)
        {
            b+=it;
        }
        if(a.compare(b)==false)
        {
            return true;
        }
        return false;
    }
};