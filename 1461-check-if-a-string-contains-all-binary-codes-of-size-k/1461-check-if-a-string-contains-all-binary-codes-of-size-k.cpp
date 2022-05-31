class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
            if(s.size()<k){return false;}
            set<string>st;
            for(int i=0;i<s.size()-k+1;++i)
                    st.insert(s.substr(i,k));
            
            return st.size()==pow(2,k);
            
    }
};