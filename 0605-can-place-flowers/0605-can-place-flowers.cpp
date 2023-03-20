class Solution {
public:
    // flowerbed=F
    bool canPlaceFlowers(vector<int>& F, int n) {
        F.insert(F.begin(),0);
        F.push_back(0);
        
        for(int i=1;i<F.size()-1;++i)
        {
            if(F[i]==0 and F[i+1]==0 and F[i-1]==0)
            {
                n--;i++;
            }
        }
        return n>=1?false:true;
    }
};