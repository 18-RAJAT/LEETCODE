class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long tmp=mass;
        for(auto& it:asteroids)
        {
            if(tmp<it)return false;
            tmp+=it;
        }
        return true;
    }
};