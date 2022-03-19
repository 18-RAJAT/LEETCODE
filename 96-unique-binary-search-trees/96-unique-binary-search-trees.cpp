// class Solution {
// public:
//     int numTrees(int n) {
        
//         //This solution gives us TLE\U0001f47e
        
//         if(n <= 1)
//         {
//             return 1;
//         }
        
//         int answer = 0;
//         for(int i=1;i<=n;++i)
//         {
//             answer += numTrees(i-1) * numTrees(n-i);
//         }
        
//         return answer;
        
//     }
// };


//2nd Approach...!!

//->>>>Using recurence relation...!!  FORMULA-->>C0 = 1 and cn+1 = 4n+2 / n+2 * Cn 

class Solution {
public:
    int numTrees(int n) {
        
        long answer = 1;
        
        for(int i = 0; i < n; i++) 
            
            answer *= (4*i+2) / (i+2.);
        
        return answer;
    }
};
