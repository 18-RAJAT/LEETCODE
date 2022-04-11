class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
       map<char,int>m;
        
        for(int i=0;i<magazine.length();++i)
        {
            m[magazine[i]]++;
        }
        
        for(int i=0;i<ransomNote.length();++i)
        {
            if(m[ransomNote[i]] > 0)
            {
                m[ransomNote[i]]--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};