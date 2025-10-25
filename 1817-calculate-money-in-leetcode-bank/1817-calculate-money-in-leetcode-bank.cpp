class Solution {
public:
    int totalMoney(int n) {
        int sum=0,week=0,day=0;
        for(int i=0;i<n;++i)
        {
            if(i%7==0)
            {
                week++;
                day=0;
            }
            day++;
            sum+=week+day-1;
        }
        return sum;
    }
};