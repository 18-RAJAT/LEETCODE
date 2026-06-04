class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans=0;
        for(int i=num1;i<=num2;++i)
        {
            string temp=to_string(i);
            for(int i=1;i<temp.size()-1;++i)
            {
                char ch=temp[i],pre=temp[i-1],post=temp[i+1];
                int curr=ch-'0',check=pre-'0',pos=post-'0';
                if((curr>check && curr>pos) || (curr<pos && curr<check))ans++;
            }
        }
        return ans;
    }
};