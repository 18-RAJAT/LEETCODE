class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int>ar(3,0);
        for(auto& it:stones)ar[it%3]++;
        int mn=min(ar[1],ar[2]),mx=max(ar[1],ar[2]);
        if(mn==0 && mx>2)return ar[0]%2==1;
        else if (mn==0)return false;
        return ar[0]%2==0 || mx>mn+2;
    }
};