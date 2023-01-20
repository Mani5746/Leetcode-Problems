//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
  int func(int price[],int ind,int n,vector<vector<int>>&dp )
  {
      if(ind==0)
      return n*price[0];
      
      //nonpick
      
      if(dp[ind][n]!=-1) return dp[ind][n];
      
      int nonpick=0+func(price,ind-1,n,dp);
      
      // pick
      int pick=INT_MIN;
      int rodlength=ind+1;
      
      if(n-rodlength>=0)
      {
        pick=price[ind]+func(price,ind,n-rodlength,dp); 
      }
      
      return dp[ind][n]=max(pick,nonpick);
  }
    int cutRod(int price[], int n) 
    {
        //code here
        vector<vector<int>>dp(n,vector<int>(n+1,0));
       // return func(price, n-1,n,dp);
       
       for(int i=0;i<=n;i++)
       {
           dp[0][i]=i*price[0];
       }
       
       for(int ind=1;ind<n;ind++)
       {
           for(int i=0;i<=n;i++)
           {
        int nonpick=dp[ind-1][i];
      
      // pick
      int pick=INT_MIN;
      int rodlength=ind+1;
      
      if(i-rodlength>=0)
      {
        pick=price[ind]+dp[ind][i-rodlength] ; 
      }
      
      dp[ind][i]=max(pick,nonpick);
      
           }
       }
       
       return dp[n-1][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends