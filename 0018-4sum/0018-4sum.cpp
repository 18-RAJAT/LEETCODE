class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<long long int>>unique_element;
        vector<long long int>four_element(4,0);
        
        for(int i=0;i<n-3;++i)//for 1st element of 4 element
        {
            for(int j=i+1;j<n-2;++j)//for 2nd element of 4 element
            {
                int left=j+1,right=n-1;//for 3rd and 4th element of 4 element
                while(left<right)
                {
                    long long int sum=(long long int)nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum==target)
                    {
                        four_element[0]=nums[i];
                        four_element[1]=nums[j];
                        four_element[2]=nums[left];
                        four_element[3]=nums[right];
                        unique_element.insert(four_element);
                        left++,right--;
                    }
                    else if(sum<target)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
                }
            }
        }
        // vector<vector<int>>ans(unique_element.begin(),unique_element.end());
        vector<vector<int>>ans;
        for (auto& it:unique_element)
        {
            ans.push_back(vector<int>(it.begin(),it.end()));//convert long long int to int
        }
        return ans;
    }
};