class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int start=0;
        int end=n-1;
        
        int mid;
        int ans=0;
        
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(citations[mid]>=n-mid)
            {
                end=mid-1;
                // ans++;
                ans=n-mid;
                cout<<"Ending Pos Value: "<<end<<"\n";
            }
            else
            {
                start=mid+1;
                // ans++;
                cout<<"Starting Pos Value: "<<start<<"\n";
            }
        }
        return ans;
    }
};