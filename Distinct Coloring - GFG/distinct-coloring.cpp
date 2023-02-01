//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:

long long int func(int ind,vector<vector<int>>&v,int prev,
vector<vector<long long int>>&dp)
{
    if(ind==0)
    {
        if(prev==0)
        return min(v[1][0],v[2][0]);
        
        if(prev==1)
        return min(v[0][0],v[2][0]);
        
        if(prev==2)
        return min(v[1][0],v[0][0]);
    }
    
    if(dp[prev+1][ind]!=-1) return dp[prev+1][ind];
    
    
    long long int p0=1e16,p2=1e16,p1=1e16;
    
    for(int i=0;i<3;i++)
    {
        if(prev==-1)
        {
            p0=v[0][ind]+func(ind-1,v,0,dp);
            p1=v[1][ind]+func(ind-1,v,1,dp);
            p2=v[2][ind]+func(ind-1,v,2,dp);
            
        }
        
        else if(prev==0)
        {
            p1=v[1][ind]+func(ind-1,v,1,dp);
            p2=v[2][ind]+func(ind-1,v,2,dp);
        }
        
        else if(prev==1)
        {
            p0=v[0][ind]+func(ind-1,v,0,dp);
            p2=v[2][ind]+func(ind-1,v,2,dp);
        }
        
        else if(prev==2)
        {
            p0=v[0][ind]+func(ind-1,v,0,dp);
            p1=v[1][ind]+func(ind-1,v,1,dp);
        }
    }
    
    return  dp[prev+1][ind]=min(p1,min(p2,p0));
}
    long long int distinctColoring(int N, int r[], int g[], int b[])
    {
        // code here 
        vector<vector<int>>v(3,vector<int>(N,0));
       
        for(int i=0;i<3;i++)
    {
        for(int j=0;j<N;j++)
        {
           if(i==0)
            v[i][j]=r[j];
            
            else if(i==1)
            v[i][j]=g[j];
            
            
            else if(i==2)
            v[i][j]=b[j];
            
            
         }
    }
    
    if(N==1)
    return v[0][0]+v[1][0]+v[2][0];
    
    int prev=-1;
    vector<vector<long long int>>dp(4,vector<long long int>(N,-1));
    
    return func(N-1,v,prev,dp);
    
    
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends