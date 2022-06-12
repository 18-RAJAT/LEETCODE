class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
        map<int,int>mp;
        int curr=0;//track current score in the window
        int maxpoints=0;//max score
        while(j<n){
            while(mp[nums[j]]){// if we find a element which already exist in map
                curr-=nums[i];
                mp[nums[i]]--;
                i++;// move the start of the window till the window is a subarray containing unique elements
            }
            curr+=nums[j];
            mp[nums[j]]++;
            j++;
            if(curr>maxpoints){// if curr is greater than max-so-far
                maxpoints=curr;
            }  
        }
        return maxpoints;
    }
};