class Solution {
public:  
    /*
    
    1.Initialize answer with 0
    
    2.Work in a reverse manner,convert target to startValue
    
    3.whenever target is odd, we increment target by 1 which cost is defined as 1 operation
    
    4.Whenever target is even,then the best possible way is reach is target = target/2 which cost also 1       operation
    
    5.Perform the two operation then operation is working till target > startValue
    
    6.If target <= startValue, only possible way to the left is the increment operation 
    
    7.All the operations peroformed then we will get the path startValue to target....!!
    
    */
    
    int brokenCalc(int startValue, int target) {
        int answer = 0;
        
       while(target > startValue)
        {
            answer++;
           
            if(target % 2)
            {
                target++;
            }
            else 
            {
                target/=2;
            }
        }
 
        return answer + startValue-target;
    }
};