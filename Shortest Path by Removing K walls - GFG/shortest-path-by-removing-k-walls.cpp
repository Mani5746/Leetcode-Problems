//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    int shotestPath(vector<vector<int>> grid, int n, int m, int k)
    {
        // code here
        int row=grid.size(), col=grid[0].size();
        vector<vector<int>> vis(row,vector<int>(col,-1));
        queue<vector<int>> q;
        //x, y, current step, remaining k
        q.push({0,0,0,k});
        
        while(!q.empty()){
            int size = q.size();
            for(int loop=0;loop<size;++loop){
                int x = q.front()[0];
                int y = q.front()[1];
                int step = q.front()[2];
                int newk = q.front()[3];
                q.pop();
                
                //if we are at the bottom right cell then return no. of steps
                if(x==row-1 and y==col-1) return step;
                
                //check if current position is inside matrix or not
                if(x<0 or x>=row or y<0 or y>=col) continue; 
                
                // If this cell is already visited with a K value lesser than this one, we would want to save Ks for future use, so we continue
                if(vis[x][y]!=-1 and vis[x][y]>=newk) continue;
                
                // If we hit an obstacle & we don't have any Ks remaining, continue else If we still have Ks to spend, we will decrease k by 1 i.e newk--.
                if(grid[x][y]==1){
                    if(newk>0) newk--;
                    else continue;
                }
                
                // We store the currentRemaining K after spending K (if required) into the visited matrix.
                vis[x][y]=newk;
                
                //push all adjecent cell to the queue
                for(int i=0; i<4; ++i){
                    int x1 = x+dx[i], y1 = y+dy[i];
                    q.push({x1,y1,step+1,newk});
                }//end of inner for-loop
            }// end of for-loop
        }//end of while-loop
        return -1; //if no path found;
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, x;
        
        cin>>n>>m>>k;
        vector<vector<int>> mat;
    
        for(int i=0; i<n; i++)
        {
            vector<int> row;
            for(int j=0; j<m; j++)
            {
                cin>>x;
                row.push_back(x);
            }
            mat.push_back(row);
        }

        Solution ob;
        cout<<ob.shotestPath(mat,n,m,k);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends