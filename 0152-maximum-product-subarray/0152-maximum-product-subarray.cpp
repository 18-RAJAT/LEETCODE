class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        
        if(n==0)
        {
            return false;
        }
        int maximum=INT_MIN;
        int maximumProduct=1;
        int minimumProduct=1;
        
        for(auto it:nums)
        {
            if(it<0)
            {
                swap(maximumProduct,minimumProduct);
            }
            maximumProduct=max(maximumProduct*it,it);
            minimumProduct=min(minimumProduct*it,it);
            
            maximum=max(maximumProduct,maximum);
            
            // cout<<maximumProduct<<" "<<maximum<<"\n";
            // cout<<maximum<<"\n";
        }
        return maximum;
    }
};