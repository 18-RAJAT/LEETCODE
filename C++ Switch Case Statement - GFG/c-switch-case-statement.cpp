// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string isInRange(int N){
        // code here 
        string str = "";
        switch(N)
        {
              case 1:
               str = "one";
               break;
           case 2:
               str = "two";
               break;
           case 3:
               str = "three";
               break;
           case 4:
               str = "four";
               break;
           case 5:
               str = "five";
               break;
           case 6:
               str = "six";
               break;
           case 7:
               str = "seven";
               break;
           case 8:
               str = "eight";
               break;
           case 9:
               str = "nine";
               break;
           case 10:
               str = "ten";
               break;
           default:
               str = "not in range";
       }
       return str;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isInRange(N) << endl;
    }
    return 0; 
}   // } Driver Code Ends