class Solution {
public:
    
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        //Possible combinations....!!!
        vector<int> count_Tops(7),count_Bottoms(7),Same(7);
        int n = tops.size();
        
        for(int i=0;i<n;++i)
        {
            //Increment the values...!!
            count_Tops[tops[i]]++;
            count_Bottoms[bottoms[i]]++;
            
            //This condition represent that if top and botoom value is same then increment top value...!!
            if(tops[i] == bottoms[i])
            {
                Same[tops[i]]++;
            }
        }
        //staring with 1 and end with 6 
        for(int i=1;i<7;++i)
            
            if(count_Tops[i] + count_Bottoms[i] - Same[i] == n)
            {
                return n - max(count_Tops[i],count_Bottoms[i]);
            }
        return -1;
    }
};