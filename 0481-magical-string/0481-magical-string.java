class Solution {
    public int magicalString(int n) {
        if(n==0)return 0;
        if(n<=3)return 1;
        int[]magical=new int[n+1];
        magical[0]=1;magical[1]=2;magical[2]=2;
        int cnt=2,ans=1,tmp=1;
        for(int i=3;i<n;++i)
        {
            int count=magical[cnt];
            for(int j=0;j<count && i<n;++j)
            {
                magical[i++]=tmp;
                if(tmp==1)ans++;
            }
            tmp=3-tmp;i--;cnt++;
        }
        return ans;
    }
}