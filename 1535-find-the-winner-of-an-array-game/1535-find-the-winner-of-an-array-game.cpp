class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n=arr.size();
        int cnt=0;
        int mx=arr[0];
        for(int i=1;i<n;++i)
        {
            if(arr[i]>mx)
            {
                mx=arr[i];
                cnt=0;
            }
            cnt++;
            if(cnt==k)
            {
                return mx;
            }
        }
        return mx;      
    }
};