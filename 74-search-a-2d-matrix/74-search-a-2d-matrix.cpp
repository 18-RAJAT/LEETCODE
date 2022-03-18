    //1st APPROACH O(m*n)

/*class Solution {
public:

   bool searchMatrix(vector<vector<int>>& matrix,int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(matrix[i][j] == target)
                    return true;
            }
        }
        
        return false;
    }
};

*/
    
    //2nd APPROACH O(m+n)
/*class Solution {
public: 
    
    bool searchMatrix(vector<vector<int>>& matrix,int target){
        int m = 0;
        int n = matrix[0].size()-1;
        
        while(m<matrix.size() and n>=0)
        {
            if(matrix[m][n] == target)
                return true;
            
            if(matrix[m][n] > target)
                n = n-1;
            
            else
                m = m+1;
        }
        
        return false;
    }
};
*/
    

//3rd APPROACH O(m log n)
  
class Solution {
public: 
    
    bool find(vector<int>& nums,int target){
        int i=0,j=nums.size()-1;
        
        while(i <= j)
        {
            int mid = i + (j-i)/2;
            if(nums[mid] == target)
                return true;
            
            if(nums[mid] > target)
                j = mid-1;
            else
                i = mid+1;
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix,int target){
        
        for(int i=0;i<matrix.size();++i)
        {
            if(find(matrix[i],target))
            {
                return true;
            }
        }
         return false;
    }
};
    
    
        //BINARY SEARCH
        
//         int row = matrix.size();
        
//         if(row == 0)
//         {
//             return false;
//         }
        
//         int column = matrix[0].size();
        
//         int row_first = 0,row_last = row-1,mid;
        
//         while(row_first < row_last)
//         {
//             mid = row_first + (row_last - row_first)/2;
            
//             if(matrix[mid] [column -1] < target)
//             {
//                 row_first = mid+1;
//             }
            
//             else if(matrix[mid][0] > target)
//             {
//                 row_last = mid - 1;
//             }
            
//             else
//             {
//                 row_first = mid;
//                 break;
//             }
//         }
        
//         //Another Binary Search
        
//         int column_first = 0,column_last = column-1;
        
//         while(column_first <= column_last)
//         {
//             mid = column_first+(column_last - column_first)/2;
            
//             if(matrix[row_first][mid] < target)
//             {
//                 column_first = mid+1;
//             }
            
//             else if(matrix[row_first][mid] > target)
//             {
//                 column_last = mid - 1;
//             }
//             else
//             {
//                 return true;
//             }
//         }
        
//         return false;
//     }
// };