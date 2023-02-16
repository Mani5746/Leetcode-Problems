//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:

   int f(int ind, int n,vector<int> &arr,vector<int> &dp)
   {
       if(ind<0||ind>=n) return 2;
       
       if(dp[ind]!=0) return dp[ind];
       
       dp[ind]=1;
       
       
       return dp[ind]=f(arr[ind]+ind,n,arr,dp);
   }
   
   
    int goodStones(int n,vector<int> &arr)
    {
        // Code here
        
        vector<int>dp(n+1,0);
        
        for(int i=0;i<n;i++)
        {
            f(i,n,arr,dp);
        }
        int ans=0;
        
        
        for(int i=0;i<n;i++)
        {
            if(dp[i]==2) ans++;
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
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends