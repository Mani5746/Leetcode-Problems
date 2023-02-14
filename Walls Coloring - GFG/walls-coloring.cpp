//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:

   int f(int ind,int prev,vector<vector<int>> &colors,int n,vector<vector<int>>&dp)
   {
       if(ind==n) return 0;
       
       if(dp[ind][prev]!=-1) return dp[ind][prev];
       
       int mn=INT_MAX;
       for(int k=0;k<3;k++)
       {
           if(k!=prev)
           {
              // mn=min(mn,(colors[ind][k]+f(ind+1,k,colors,n,dp)));
              int pick=colors[ind][k]+f(ind+1,k,colors,n,dp);
              
              mn=min(mn,pick);
           }
       }
       
       return dp[ind][prev]= mn;
   }
    int minCost(vector<vector<int>> &colors, int N)
    {
        // Write your code here.
        
        vector<vector<int>> dp(N+1,vector<int>(3,-1));
        
        int mn=INT_MAX;
        
        for(int i=0;i<3;i++)
        {
            mn=min(mn,colors[0][i]+f(1,i,colors,N,dp));
        }
        
        return mn;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends