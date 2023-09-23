//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends


typedef long long ll;
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        ll lft=0,ryt=0;
        for(int i=0;i<n;++i)
        {
            ryt+=a[i];
        }
        for(int i=0;i<n;++i)
        {
            lft+=a[i];
            if(lft==ryt)
            {
                return i+=1;
            }
            ryt-=a[i];
        }
        return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends