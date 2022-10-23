class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<bool> bits(n+1, false);//ignore 0th index.
        
        vector<int> output;
        for(int n: nums)
        {
            if(bits[n]== true)
                output.push_back(n);
            bits[n]=true;
        }
        for(int i=1; i<=n; ++i)
        {
            if(bits[i]== false)
                output.push_back(i);
        }
        return output;
    }
};