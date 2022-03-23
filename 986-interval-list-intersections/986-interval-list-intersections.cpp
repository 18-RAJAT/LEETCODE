class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        vector<vector<int>> result;
        
        int i=0;
        int j=0;
        
        while(i<firstList.size() and j<secondList.size())
        {
            
            //This case is work like....!!
            /*
            Example-->
            
            
             A = [[0,2],[5,10],[13,23],[24,25]]
             B = [[1,5],[8,12],[15,24],[25,26]]
             
             
             and then check 1st idx of A and B then find min and max element
             same as another cases we will bw run as it  is....!!!!
            
            */
            
            
            //Starting se we will take max element of the given one
        int A = max(firstList[i][0] , secondList[j][0]);
            
            //Here we will take minnimum element of the given one 
        int B = min(firstList[i][1] , secondList[j][1]);
        
        if(A <= B)
        {
            result.push_back({A,B});
        }
        
        if(firstList[i][1] < secondList[j][1])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
        return result;
    }
};