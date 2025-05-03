class Solution {
public:
    int minDominoRotations(vector<int>& a, vector<int>& b) {
        int n=a.size(),mx1=0,mx2=0,val1,val2;
        map<int,int>fq1,fq2,fq3;
        for(int i=0;i<n;++i)
        {
            if(a[i]==b[i])fq3[a[i]]++;
            else
            {
                fq1[a[i]]++;
                fq2[b[i]]++;
                if(fq1[a[i]]>mx1)mx1=fq1[a[i]],val1=a[i];
                if(fq2[b[i]]>mx2)mx2=fq2[b[i]],val2=b[i];
            }
        }
        if(fq3[a[0]]==n || fq1[a[0]]==n || fq2[b[0]]==n)return 0;
        if(mx1+fq2[val1]+fq3[val1]==n || mx2+fq1[val2]+fq3[val2]==n)
        {
            if(mx1<mx2)return fq1[val2];
            else
            {
                if(mx1+fq2[val1]+fq3[val1]==n)return n-(fq3[val1]+mx1);
                if(mx2+fq1[val2]+fq3[val2]==n)return n-(fq3[val2]+mx2);
            }
        }
        return -1;
    }
};