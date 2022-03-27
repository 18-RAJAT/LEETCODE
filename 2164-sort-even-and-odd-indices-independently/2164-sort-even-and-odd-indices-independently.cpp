/*
Time complexity->O(logN)
Space complexity->O(N)
*/
class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        
        int n = nums.size();

        //taking 2 vectors even and odd
        vector<int>even;
        vector<int>odd;
        
        for(int i=0;i<n;++i)
        {
            if(i % 2)
            {
                odd.push_back(nums[i]);
            }
            
            else
            {
                even.push_back(nums[i]);
            }
        }
        
        sort(odd.begin(),odd.end(),greater<int>()); //Sort odd elements...!!
        
        sort(even.begin(),even.end()); //Now sort even elements...!!
        
        //Now taking odd and even indices...!!
        int odd_indices = 0;
        int even_indices = 0;
        
        for(int i=0;i<n;++i)
        {
            if(i % 2)
            {
                
                nums[i] = odd[odd_indices]; //Check this case
                odd_indices++;//and increment odd indices
            }
            
            else
            {
                
                nums[i] = even[even_indices];//check this case
                even_indices++;//and increment even indices
            }
        }
        
        return nums;
        
    }
};