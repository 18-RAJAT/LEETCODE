#define ll long long
typedef vector<pair<int,int>> vv;
typedef pair<int, int> PII;
typedef pair<int,int> PAIR;
typedef vector<int> VI;
typedef vector<vector<int>> VII;
typedef vector<string> VS;
typedef vector<PII> VIII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef unordered_map<char,int> MPC;
typedef set<int> SETI;
typedef multiset<int> MSETI;
#define ff(a,b) for(int i=0;i<n;++i)

//using merge sort
class Solution {
public:
    //simple merge function
    void merge(VI&count,vv&v,int left,int mid,int right)
{
        vv temp(right-left+1);
        int i=left,j=mid+1,k=0;
        
        //if left is less then mid and mid+1 is less then right
        while(i<=mid and j<=right)
        {
            if(v[i].first<=v[j].first)
            {
                temp[k++]=v[j++];
            }
            else
            {
                count[v[i].second]+=right-j+1;
                temp[k++]=v[i++];
            }
        }
        //less then mid part condition check and all the pairs of left are check
        while(i<=mid){temp[k++]=v[i++];}
        //same as greater then mid part condition check and all the pairs of left are check
        while(j<=right){temp[k++]=v[j++];}
        
        //traverse all these things and check pairs of i(left) = pair of temp(left-1)
        for(int i=left;i<=right;++i)
        {v[i]=temp[i-left];}
}
    //simple mergeSort function
    void mergeSort(VI&count,vv&v,int left,int right)
{
        if(left<right)
        {
            //finding middle element
            int mid=left+(right-left)/2;
            //merge sort
            mergeSort(count,v,left,mid);
            mergeSort(count,v,mid+1,right);
            //merge function call
            merge(count,v,left,mid,right);
        }
}
    
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        //vector of pair to storing all the elements
        vv a(n);
        ff(a,b)
        {
            //taking a pair and create a pair of elements
            PAIR p;
            p.first=nums[i];
            p.second=i;
            a[i]=p;
        }
        VI count(n,0);
        //recursive call
        mergeSort(count,a,0,n-1);
        return count;
    }
};