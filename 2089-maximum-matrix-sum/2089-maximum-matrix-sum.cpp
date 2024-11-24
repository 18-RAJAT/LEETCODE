class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int mn=INT_MAX,res=0;
        for(auto& i:matrix)
        {
            for(auto& j:i)
            {
                sum+=abs(j);
                if(j<0)res++;
                mn=min(mn,abs(j));
            }
        }
        if(res%2==0)return sum;
        return sum-2*mn;
    }
};