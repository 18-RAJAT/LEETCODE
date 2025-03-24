class Solution {
public:
    int countDays(int days, vector<vector<int>>& m) {
        sort(m.begin(),m.end());
        vector<vector<int>>arr;
        arr.push_back(m[0]);
        for(int i=1;i<m.size();++i)
        {
            int n=arr.size()-1;
            if(arr[n][1]>=m[i][0])
            {
                if(arr[n][1]<m[i][1])arr[n][1]=m[i][1];
            }
            else arr.push_back(m[i]);
        }
        int res=0;
        for(auto& x:arr)res+=x[1]-x[0]+1;
        return days-res;
    }
};