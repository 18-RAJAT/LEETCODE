class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        function<vector<int>(vector<int>,int)>add=[&](vector<int>num,int k)->vector<int>
        {
            int n=num.size();
            for(int i=n-1;i>=0;--i)//This loop is for adding the k to the last digit of the number
            {
                num[i]+=k;
                k=num[i]/10;
                num[i]%=10;
            }
            while(k>0)
            {
                num.insert(num.begin(),k%10);//If the number is greater than 10 then we will add the carry to the next digit
                k/=10;
            }
            return num;
        };
        return add(num,k);
    }
};