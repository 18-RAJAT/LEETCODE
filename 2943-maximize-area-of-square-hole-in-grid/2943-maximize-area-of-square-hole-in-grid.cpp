class Solution {
public:
    int LCS(vector<int>& arr)
    {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int i=0,ans=0;
        while(i<arr.size())
        {
            int prev=arr[i],j=i+1;
            while(j<n && arr[j]==prev+1)
            {
                j++;
                prev++;
            }
            ans=max<int>(ans,j-i);
            i=j;
        }
        return ans;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int L=LCS(vBars)+1;
        int B=LCS(hBars)+1;
        return min<int>(L*L,B*B);
    }
};