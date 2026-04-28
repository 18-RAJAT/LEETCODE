class Solution{
public:
    int minOperations(vector<vector<int>>&grid,int x){
        vector<int>arr;
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[0].size();++j)
            {
                arr.push_back(grid[i][j]);
            }
        }
        nth_element(arr.begin(),arr.begin()+arr.size()/2,arr.end());
        int median=arr[arr.size()/2],ans=0;
        for(auto& it:arr)
        {
            int diff=abs(median-it);
            if(diff%x!=0)return -1;
            ans+=diff/x;
        }
        return ans;
    }
};