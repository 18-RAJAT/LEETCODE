class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());
        long long int H=hFences.size();
        long long int V=vFences.size();
        set<long long int>square_area;
        for(long long int i=H-1;~i;--i)
        {
            for(long long int j=0;j<i;++j)
            {
                long long int diff=hFences[i]-hFences[j];
                square_area.insert(diff);
            }
        }
        vector<long long int>differences;
        for(long long int i=V-1;~i;--i)
        {
            for(long long int j=0;j<i;++j)
            {
                long long int diff=vFences[i]-vFences[j];
                differences.push_back(diff);
            }
        }
        sort(differences.begin(),differences.end());
        long long ans=-1;
        for(long long int i=differences.size()-1;~i;--i)
        {
            if(square_area.count(differences[i]))
            {
                ans=differences[i];
                break;
            }
        }
        if(~ans)
        {
            ans=(1LL*ans*ans)%1000000007;
        }
        return ans%1000000007;
    }
};