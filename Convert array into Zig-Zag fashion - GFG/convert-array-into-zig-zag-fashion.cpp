// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Program for zig-zag conversion of array
	void zigZag(int arr[], int n) {
	    // code here
	    
	    //Using 2 pointer approach
	    int i=0;
	    int j=1;
	    
	    //base case 1st
	    while(j < n)
	    {
	        //Base case 2nd
	        
	        if(arr[i] > arr[j])
	        {
	            //Zig - Zag fashion coversion
	            swap(arr[i],arr[j]);
	        }
	        
	        i++;
	        j++;
	        
	        //Base case 3rd
	        if(j < n and arr[i] < arr[j])
	        {
	            //Swap again
	            swap(arr[i],arr[j]);
	        }
	        i++;
	        j++;
	    }
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.zigZag(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends