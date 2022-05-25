class Solution {
public:
    int maxProduct(vector<int>& nums) {
     if(nums.empty())return 0;
            int tp=INT_MIN;
            int maxProd=1;
            int minProd=1;
            
            for(int n : nums)
            {
                    if(n<0){swap(maxProd,minProd);}
                    maxProd=max(maxProd*n,n);
                    minProd=min(minProd*n,n);
                    
                    tp=max(maxProd,tp);
            }
            return tp;
    }
};