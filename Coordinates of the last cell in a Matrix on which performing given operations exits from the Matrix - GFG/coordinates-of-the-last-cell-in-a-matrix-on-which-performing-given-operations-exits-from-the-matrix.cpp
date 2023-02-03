//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> mat)
    {
        int n=mat.size();
        int m=mat[0].size();
       pair<int,int>ans;
        char dir='r';
        int i=0,j=0;
       
       while(1)
       {
           if(mat[i][j]==0)
           {
               if(dir=='r')
               {
                   j=j+1;
                   if(j>=m)
                   {
                   ans={i,j-1};
                   break;
                   }
               }
               
               else if(dir=='u')
               {
                   i=i-1;
                   if(i<0)
                   {
                       ans={i+1,j};
                       break;
                   }
               }
               
               else if(dir=='d')
               {
                   i=i+1;
                   if(i>=n)
                   {
                       ans={i-1,j};
                       break;
                   }
               }
               
               else if(dir=='l')
               {
                   j=j-1;
                   if(j<0)
                   {
                       ans={i,j+1};
                       break;
                   }
               }
           }
           
           
           else
           {
               mat[i][j]=0;
               
                    if(dir=='r') dir='d';
               else if(dir=='u') dir='r';
               else if(dir=='d') dir='l';
               else if(dir=='l') dir='u';
               
              if(dir=='r')
               {
                   j=j+1;
                   if(j>=m)
                   {
                   ans={i,j-1};
                   break;
                   }
               }
               
               else if(dir=='u')
               {
                   i=i-1;
                   if(i<0)
                   {
                       ans={i+1,j};
                       break;
                   }
               }
               
               else if(dir=='d')
               {
                   i=i+1;
                   if(i>=n)
                   {
                       ans={i-1,j};
                       break;
                   }
               }
               
               else if(dir=='l')
               {
                   j=j-1;
                   if(j<0)
                   {
                       ans={i,j+1};
                       break;
                   }
               }
               
           }
       }
       
       return ans;
        
    }

};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends