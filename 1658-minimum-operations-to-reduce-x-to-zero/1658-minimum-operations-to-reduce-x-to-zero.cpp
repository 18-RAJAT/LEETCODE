class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum=0;
            int sum=0;
            for(int i=0;i<nums.size();++i)
            {
                    totalSum+=nums[i];
            }
            int temp=totalSum-x;
            if(temp<0){return -1;}
            int result=INT_MIN;
            int i=0;int j=0;
            while(j<nums.size())
            {
                    sum+=nums[j];
                    if(sum>temp)
                    {
                            while(sum>temp)
                            {
                                    sum-=nums[i];i++;
                            }
                    }
                    if(sum==temp){result=max(result,j-i+1);}j++;}
                    if(result==INT_MIN){return -1;}
                    else {return nums.size()-result;}
    }
};