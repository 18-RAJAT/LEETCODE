class Solution {
public:
    int countLargestGroup(int n) {
        vector<int>arr(37);
        for(int i=1;i<=n;++i)arr[recur(i)]++;
        int mx=*max_element(arr.begin(),arr.end());
        return count_if(arr.begin(),arr.end(),[&](int x){return x==mx;});
    }
private:
    int recur(int n)
    {
        int sum=0;
        while(n)
        {
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
};