//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int N, vector<int> Edge)
  {
      // code here
      vector<int>pre(N,0);
      for(int i=0;i<N;i++)
      {
          if(Edge[i]==-1) continue;
          
          pre[Edge[i]]+=i;
      }
      
      int mx=0,ind=0;
      
      for(int i=0;i<N;i++)
      {
         if(pre[i]>=mx) 
         {
             ind=i;
             mx=pre[i];
         }
      }
      
      return ind;
      
      
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends