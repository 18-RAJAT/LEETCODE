class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<long long>a;
        for(int i=0;i<weights.size()-1;++i)
        {
            a.push_back(weights[i]+weights[i+1]);
        }
        sort(a.begin(),a.end());
        long long mini(0),maxi(0);
        for(int i=0;i<k-1;++i)
        {
            mini+=a[i];
            maxi+=a[a.size()-1-i];
        }
        return abs(mini-maxi);
    }
};