class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //calculate euclidean distance 
        function<int(vector<int>&)>euclideanDistance=[&](vector<int>& point)->int
        {
            return (point[0]*point[0])+(point[1]*point[1]);
        };
        //quick sort function
        function<int(vector<vector<int>>&,int,int)>partition=[&](vector<vector<int>>& points,int start,int end)->int
        {
            int pivot=euclideanDistance(points[end]);//last element as pivot
            int i=start-1;
            for(int j=start;j<end;++j)//placing all elements less than pivot to left of pivot
            {
                if(euclideanDistance(points[j])<=pivot)//comparing euclidean distance
                {
                    i++;
                    swap(points[i],points[j]);
                }
            }
            swap(points[i+1],points[end]);//placing pivot at it's correct position
            return i+1;
        };
        int start=0,end=points.size()-1;
        while(start<=end)
        {
            //randomized quick sort
            int pivot=partition(points,start,end);
            if(pivot==k-1)
            {
                break;
            }
            else if(pivot>k-1)
            {
                end=pivot-1;//pivot is greater than k-1
            }
            else
            {
                start=pivot+1;//pivot is less than k-1
            }
        }
        vector<vector<int>>ans;
        for(int i=0;i<k;++i)
        {
            ans.push_back(points[i]);
        }
        return ans;
    }
};