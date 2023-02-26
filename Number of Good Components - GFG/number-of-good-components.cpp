//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  void dfs(int node,vector<vector<int>>& adj,vector<int>&vis,vector<int>&temp)
  {
        vis[node]=1;
      
       temp.push_back(node);
      
      
      for(auto it: adj[node])
      {
          if(!vis[it])
          {
              dfs(it,adj,vis,temp);
          }
      }
      
     
      
      
  }
  
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) 
    {
        // code here
        int ans=0;
        vector<int> vis(10001,0);
        
         for(int i=1;i<=V;i++)
         {
             if(!vis[i])
             {
                 
               vector<int> temp;
               
               dfs(i,adj,vis,temp);
               
               bool flag=true;
               
               for(int i=0;i<temp.size();i++)
               {
                   if(adj[temp[i]].size()!=(temp.size()-1))
                   {
                       flag=false; break;
                   }
               }
               
               if(flag) ans++;
                 
             }
         }
         
         return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends