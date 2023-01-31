//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string A, string B) 
    {
        // code here
        int n=A.size();
        int m=B.size();
        int i=0,j=0;
        int flag=0;
        
        for(;i<n;i++)
        {
            if(A[i]==B[0])
            {
                flag=1;
                 break;
            }
        }
        
        if(!flag) return -1;
        int ans=0;
        
        while(j<m)
        {
            while(i<n&&j<m&&A[i]==B[j])
            {
                i++; j++;
            }
            
            if(i==n||j==m)
            {
                ans++;i=0;
            }
            
            else return -1;
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends