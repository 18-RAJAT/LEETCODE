class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n=reward1.size();
        vector<vector<int>>arr(n,vector<int>(3,0));//0->ans,1->reward1,2->reward2
        for(int i=0;i<n;++i)
        {
            int& ans=arr[i][0];//ans
            int& R1=arr[i][1];//reward1
            int& R2=arr[i][2];//reward2
            
            R1=reward1[i];
            R2=reward2[i];
            ans=R1-R2;
        }
        sort(arr.rbegin(),arr.rend());
        int res=0;
        for(int i=0;i<n;++i)
        {
            if(k>=1)
            {
                res+=arr[i][1];//reward1
                k--;//mice eaten by cat 1
            }
            else
            {
                res+=arr[i][2];//reward2
            }
        }
        return res;
    }
};