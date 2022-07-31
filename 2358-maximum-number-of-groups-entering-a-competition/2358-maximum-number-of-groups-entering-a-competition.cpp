class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int temp=1;
        int n=grades.size();
        while(temp<n)
        {
            // --n; 
            n-=temp;
            if(temp<n){temp++;}
        }
        return temp;
    }
};