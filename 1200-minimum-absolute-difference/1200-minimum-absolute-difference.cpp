class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>>result;
        sort(arr.begin(),arr.end());
        int minGap=INT_MAX;
        for(int i=1;i<arr.size();++i)
            minGap=min(minGap,arr[i]-arr[i-1]);
        for(int i=1;i<arr.size();++i)
            if(arr[i]-arr[i-1]==minGap)
                result.push_back({arr[i-1],arr[i]});
        return result;
    }
};
