class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& w) {
        vector<string> pos{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."} ; 
            set<string>st;
            for(int i=0;i<w.size();++i)
            {
                    int ws=w[i].length();
                    string result;
                    for(int j=0;j<ws;++j)
                    {
                            result=result+pos[w[i][j]-'a'];
                    }
                    st.insert(result);
            }
            return st.size();
    }
};