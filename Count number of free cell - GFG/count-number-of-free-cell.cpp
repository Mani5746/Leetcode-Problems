//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

#define ll long long int
class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr)
  { unordered_set<ll> row;
   unordered_set<ll> col;
    vector<ll> ans;
   for(int i=0;i<k;i++)
   {
       row.insert(arr[i][0]);
       col.insert(arr[i][1]);
       ll r=row.size();
       ll c=col.size();
       
       ans.push_back(n*n-(n*(r+c)-r*c));
       
   }
   
   return ans;
  
      //Code Here
  }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends