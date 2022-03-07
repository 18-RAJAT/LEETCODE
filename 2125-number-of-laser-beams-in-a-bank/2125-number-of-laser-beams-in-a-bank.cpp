class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
       
        int previous = 0;
        int current = 0;
        int result = 0;
        
        for(int i=0;i<bank.size();++i)
        {
          current = count(bank[i].begin(),bank[i].end(),'1');
            
            if(current > 0)
                
              result += previous * current,previous = current;
        }
        
        return result;
        
        
    }
};