class Solution {
public:
    
    bool isValid(vector<int>&nums,int m, int maximum)
    {
        //Starting with 1st index
        int index = 1;
        //Initially sum is 0
        int sum = 0; 
        
        //Traverse the array
        for(int i=0;i<nums.size();++i)
        {
            //Initially sum = 0 then we will add nums value repeatedly when the range is not end
            sum += nums[i];
            
            //Base case
            if(sum > maximum)
            {
                //Index value increase to the next index 
                index++;
                
                //Sum stores the  nums value idx
                sum = nums[i];
            }
            
            //Edge case(index value is split array to greater then false the statement)
            if(index > m)
            {
               return false;
            }
        }
        
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        
        int max = -1;//Maximum at first initilize -1
        int sum =  0;//Sum value is 0
        
        for(int i : nums)
        {
            //nums value(i value) is i value is greater then maximum then store into i value in maximum 
            if(i > max)
            {
                max = i;
            }
            
            //else we will be adding i value in sum
            sum += i;
        }
        
        /*
        Initialization:
        start = max
        end = sum
        answer = -1 (index to index very...!!)
        */
        int start = max;
        int end = sum;
        int answer = 0;
        
        //Using binary search
        while(start <= end)
        {
            //Finding middle element
            int mid = start + (end - start)/2;
            
            if(isValid(nums,m,mid))
            {
                //Previous condition is stisfied then
                answer = mid;
                //End will store middle element - 1
                end = mid -1;
            }
            
            else
            {
                //previous condition not stisfied then we will be store middle element + 1
                start = mid + 1;
            }
        }
        //At last we will store the maximum answer then return the answer
        return answer;
    }
};