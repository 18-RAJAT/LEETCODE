#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
const double pi=acos(-1.0);
#define ll long long
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<vector<int>> VII;
typedef vector<string> VS;
typedef vector<vector<string>> VVS;
typedef vector<PII> VIII;
typedef vector<VI> VVI;
typedef map<char,int> MPCI;
typedef priority_queue<pair<int,pair<int,int>>> PQVI;
typedef unordered_map<string,vector<string>> MPSVS;
typedef set<int> SETI;
typedef pair<char,int>PCI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
#define all(x) sort(x.begin(), x.end())
#define ff(a,b) for(int i=a;i<b;i++)
#define f1(i,s,e) for(long long int i=s;i<e;i++)
#define ff1(pass) for(long long int i=n-2;i>=0;--i)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define FOREACH(n) for(auto it:n)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back



class Solution {
public:
    int romanToInt(string s) {

//         MPCI roman;
//         roman.insert(PCI('I', 1));
//         roman.insert(PCI('V', 5));
//         roman.insert(PCI('X', 10));
//         roman.insert(PCI('L', 50));
//         roman.insert(PCI('C', 100));
//         roman.insert(PCI('D', 500));
//         roman.insert(PCI('M', 1000));
        
//         int len=s.length(),num,sum=0;

//         for(int i=0;i<len;){
//             if(i==(len-1)){
//                 num=roman[s[i]];
//                 ++i;
//             }
//             else if(roman[s[i]]<roman[s[i+1]])
//             {
//                 num=roman[s[i+1]]-roman[s[i]];
//                 i=i+2;
//             }
//             else
//             {
//                 num=roman[s[i]];
//                 ++i;
//             }
//             sum+=num;
//         }

//         return sum;
        
        int a[1000];
        a['I']=1; 
        a['V']=5;
        a['X']=10;
        a['L']=50;
        a['C']=100;
        a['D']=500;
        a['M']=1000;
        int sum=0;
        f1(i,0,s.size()-1)
        {
            if(a[s[i]]<a[s[i+1]]){sum=sum-a[s[i]];}
            else{sum=sum+a[s[i]];}
        }
        sum=sum+a[s[s.size()-1]];return sum;
    }
};