class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        int n = s.length();
        vector<int>FrequencyCount(n, 1);
        stack<int> stk;
        string answer;
        
            //Starting
        stk.push(0);
        for(int i = 1; i < n ; i++){
            
                //Base case1
            if(!stk.empty())
            {
                    //Base case2 
                if(s[stk.top()]==s[i]) FrequencyCount[i] = FrequencyCount[stk.top()] + 1;
            }
            //when we will traverse the loop then we will we push the ith value of the stack
            stk.push(i);
            
                //Base case (when stk top == k)
            if(FrequencyCount[stk.top()] == k)
            {
                for(int i = 0 ; i < k ; i++)
                {
                    stk.pop();
                }
            }
            
        }
        
        while(!stk.empty())
        {
            
            answer += s[stk.top()];
            stk.pop();
            
        }
        
        reverse(answer.begin(), answer.end());
        
        return answer;
        
    }
};