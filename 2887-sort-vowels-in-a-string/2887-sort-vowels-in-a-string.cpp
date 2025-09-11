class Solution {
public:
    string sortVowels(string s) {
        function<int(char)>recur=[&](char c)->int
        {
            c=tolower(c);
            return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
        };
        string tmp;
        for(auto& it:s)
        {
            if(recur(it))
            {
                tmp.push_back(it);
            }
        }
        sort(tmp.begin(),tmp.end());
        int rep=0;
        for(auto& it:s)
        {
            if(recur(it))
            {
                it=tmp[rep];
                rep++;
            }
        }
        return s;
    }
};