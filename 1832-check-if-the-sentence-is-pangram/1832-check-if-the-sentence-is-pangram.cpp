class Solution {
public:
    bool checkIfPangram(string sentence) {
        // sort(sentence.begin(),sentence.end());
        set<char>st(sentence.begin(),sentence.end());   
        if(st.size()==26)
        {
            return true;
        }
        return false;
    }
};