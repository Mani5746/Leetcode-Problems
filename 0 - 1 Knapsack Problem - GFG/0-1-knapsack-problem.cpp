//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int f(int W, int wt[], int val[], int ind, vector<vector<int>> &dp)
    {
        if(ind==0)
        {
            if(W<wt[ind])
            return 0;
            
            return val[ind];
        }
        
        if(dp[ind][W]!=-1) return dp[ind][W];
        
        int nonpick=0+f(W,wt,val,ind-1,dp);
        
        int pick=INT_MIN;
        if(W>=wt[ind])
        {
            pick=val[ind]+f(W-wt[ind],wt,val,ind-1,dp);
        }
        
        return dp[ind][W]=max(pick,nonpick);
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       
       vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
       return f(W,wt,val,n-1,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends