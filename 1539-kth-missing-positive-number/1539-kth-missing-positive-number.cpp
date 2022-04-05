class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int left = 0;
        int right = arr.size();
        int middle;
        
        while(left < right)
        {
            middle = (left + right + 1)/2;
            
            //Not Understable lol
            if(middle == 0 or arr[middle - 1] - middle < k)
            {
                left = middle;
            }
            
            else
            {
                right = middle - 1;
            }
        }
        
        return left + k;
        
    }
};