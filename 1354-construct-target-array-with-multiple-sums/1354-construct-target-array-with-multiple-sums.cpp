class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long long int sum = 0;
        for (auto i:target){sum+=i,pq.push(i);}
        while (pq.top()!=1) 
        {
            int i=pq.top();
            pq.pop();
            sum-=i;
            if (i<= sum or sum<1) return false;
            i%=sum;
            sum+=i;
            pq.push(i?i: sum);
        }
        return true;
    }
};