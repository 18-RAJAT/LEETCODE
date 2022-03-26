class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        //Using binary search
        
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n-1][n-1] + 1;
        int mid , count , temp;
        
        while(low < high)
        {
            mid = low + (high - low)/2 , temp = n-1 , count = 0;
            
            //For each row, we count the element that are simmiler then mid
            
            for(int i=0;i<n;++i)
            {
                while(temp >= 0 and matrix[i][temp] > mid)
                {
                    temp --;
                }
                
                count += temp + 1;
            }
            
            if(count < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
            
        }
        return low;
    }
};