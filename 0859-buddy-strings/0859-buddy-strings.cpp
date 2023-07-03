class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()==0 || goal.size()==0)
        {
            return false;
        }
        if(s.size()!=goal.size())
        {
            return false;
        }
        set<char>hash;
        if(s==goal)
        {
            for(int i=0;i<s.size();i+=1)
            {
                if(hash.count(s[i])>0)
                {
                    return true;
                }
                hash.insert(s[i]);
            }
            return false;
        }
        int count=0;
        char c1,c2,c3,c4;
        for(int i=0;i<s.size();i+=1)
        {
            if(s[i]!=goal[i])
            {
                count++;
                if(count==1)
                {
                    c1=s[i];
                    c2=goal[i];
                }
                if(count==2)
                {
                    c3=s[i];
                    c4=goal[i];
                }
            }
            if(count>2)
            {
                return false;
            }
        }
        if(count==2)
        {
            if(c1==c4 && c2==c3)
            {
                return true;
            }
            return false;
        }
        return false;
    }
};