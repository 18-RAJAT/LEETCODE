class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int mn=INT_MAX,res=0;
        for(auto& it:matrix)
        {
            for(auto& it1:it)
            {
                sum+=abs(it1);
                if(it1<0)res++;
                mn=min(mn,abs(it1));
            }
        }
        if(res%2==0)return sum;
        return sum-2*mn;
    }
};