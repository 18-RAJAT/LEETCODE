class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stk;
        auto recur=[&stk](int asteroid)->bool
        {
            if(asteroid>0)
            {
                return true;
            }
            while(!stk.empty() && stk.back()>=0)
            {
                if (stk.back()>=-asteroid)
                {
                    if (stk.back()==-asteroid)
                    {
                        stk.pop_back();
                    }
                    return false;
                }
                else
                {
                    stk.pop_back();
                }
            }
            return true;
        };
        for(auto &it:asteroids)
        if(recur(it))
        {
            stk.push_back(it);
        }
        return stk;
    }
};