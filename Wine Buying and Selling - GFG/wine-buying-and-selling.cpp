//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  long long int wineSelling(vector<int>& a, int n)
  {
      //Code here.
      int buy=0,sell=0;
      int flag1=1,flag2=1;
      
     for(int i=0;i<n;i++)
     {
         if(a[i]>0&&flag1)
         {
             buy=i;
             flag1=0;
         }
         
         if(a[i]<0&&flag2)
         {
             sell=i; flag2=0;
         }
     }
      long long ans=0;
      while(buy<n&&sell<n)
      {
          if(a[buy]>=abs(a[sell]))
          {
              ans+=abs(a[sell])*abs(sell-buy);
             
              a[buy]=a[buy]+a[sell];
              
               a[sell]=0;sell++;
              while(sell<n)
              {
                  if(a[sell]<0) break;
                  sell++;
              }
              
              if(a[buy]==0)
              {
                  while(buy<n)
                  {
                      if(a[buy]>0) break;
                      buy++;
                  }
              }
          }
          
          else
          {
              ans+=abs(a[buy])*abs(sell-buy);
             
              a[sell]=a[buy]+a[sell];
              
               a[buy]=0; buy++;
              while(buy<n)
              {
                  if(a[buy]>0) break;
                  buy++;
              }
              
              if(a[sell]==0)
              {
                  while(sell<n)
                  {
                      if(a[sell]<0) break;
                      sell++;
                  }
              }
          }
      }
      
      return ans;
  }
};



//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends