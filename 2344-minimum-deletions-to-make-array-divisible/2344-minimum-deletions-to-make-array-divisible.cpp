class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
         sort(nums.begin(),nums.end());int gcd=0;
        for(auto i:numsDivide)
        {gcd=__gcd(gcd,i);}
           int ct=0;
        int n=nums.size();
            for(int i=0;i<nums.size();i++)
            {
                // cout<<"1";
                if(nums[i]==gcd or gcd%nums[i]==0){break;}
                else{ct++;n--;}
            }
            if(n==0)return -1;//cout<<"Check";
            return ct;
        return -1;
    }
};