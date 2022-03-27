class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        vector<int>v;
        
        for(int i=0;i<arr2.size();++i)
        {
            for(int j=0;j<arr1.size();++j)
            {
                if(arr2[i] == arr1[j])
                {
                    v.push_back(arr1[j]);
                    arr1[j] = -1;
                }
            }
        }
        
        sort(arr1.begin(),arr1.end());
        
        for(int j=0;j<arr1.size();++j)
        {
            if(arr1[j] != -1)
            {
                v.push_back(arr1[j]);
            }
        }
        
        return v;
        
    }
};