#define ll long long
#define ld long double
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
#define INF (int)1e9
#define EPS 1e-9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795

//Using BELLMAN FORD algorithm
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f,int src, int dst, int k) {
        //this distance we will store our answer
        vector<int>distance1(n,INF);
        //initital point where we will initialy dist of src is 0
        distance1[src]=0;
        // only k stopes are allowed now we will be relexing all the k+1 rounds
        
        //inc k
        for(int i=1;i<=k+1;++i)
        {
            //now here we will be passing 2 argument like n number of edges + all  edges are assigned initialy as INF(1e9)
            vector<int>distance2(n,INF);
            distance2=distance1;
            for(auto edge:f)
            {
                //assign all the values
                int u=edge[0];
                int v=edge[1];
                int w=edge[2];
                //and relexing here
                
                //base case
                if(distance1[u]+w<distance2[v])
                {distance2[v]=distance1[u]+w;}
            }
            //similarly in this time value of distance2 is assigning with distnace1 like
            distance1=distance2;
        }
        //dist will be stored at distance1
        int result=distance1[dst];
        //if distance of dist max value like out of bound(1e9)INF then we can't reach our destination
        if(result==INF)
            //if this case is true then we will assign the result is -1
        {result=-1;}
        return result;
    }
};