// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
   //Your code here
   int size=s.size();
   int arr[size];
   int i=0;
   while(!s.empty())
   {
       arr[i++]=s.top();s.pop();
   }

for(int i=0;i<size-1;++i)
{
   for(int j=i+1;j<size;++j)
   {
       if(arr[i]>arr[j])
       {
           int temp=arr[i];
           arr[i]=arr[j];
           arr[j]=temp;
       }
   }
}

for(int i=0;i<size;++i)
{
    s.push(arr[i]);
}
}