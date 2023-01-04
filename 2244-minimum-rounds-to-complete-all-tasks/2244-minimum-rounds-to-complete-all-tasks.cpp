class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int count=1;
        int res=0;
        sort(tasks.begin(),tasks.end());
        for(int i=1;i<=tasks.size();i++,count++)
        {
            if(i==tasks.size() or tasks[i-1]!=tasks[i])
            {
                if(count==1)
                {
                    return -1;
                }
                res+=(count+2)/3;
                count=0;
            }
        }
        return res;    
    }
};