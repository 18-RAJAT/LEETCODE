class Solution {
public:
    
    int numRescueBoats(vector<int>& people, int limit) {    
        //Sort all of people 
        sort(people.begin(),people.end());
        
        int i = 0;
        int j = people.size() -1;
        
        //Initially count value is 0
        int count = 0;
        
        while(i <= j)
        {
            //This will represent that add light weight people with heavy weight people
            if(people[i] + people[j] <= limit)
                
                i++;
                j--;
                count++;
        }
        
        return count;
        
    }
};