class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        int low=0,high=n-1;
        while(low+1<n && arr[low]<=arr[low+1])low++;
        if(low==n-1)return 0;
        while(high>=low && arr[high-1]<=arr[high])high--;
        int ans=min(n-low-1,high);
        int i=0,j=high;
        while(i<=low && j<n)
        {
            (arr[i]<=arr[j])?ans=min(ans,j-i-1),i++:j++;
        }
        return ans;
    }
};