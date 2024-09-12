class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bool chars[26]={false};
        int count=0;
        for(auto& c:allowed)chars[c-'a']=true;
        for(auto& word:words)
        {
            bool consistent=true;
            for(auto& c:word)
            {
                if(!chars[c-'a'])
                {
                    consistent=false;
                    break;
                }
            }
            if(consistent) count++;
        }
        return count;
    }
};