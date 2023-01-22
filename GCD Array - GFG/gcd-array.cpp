//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int solve(int n, int k, vector<int> &arr) 
    {
        // code here 
        int pre[n];
        pre[0]=arr[0];
        for(int i=1;i<n;i++)
        pre[i]=arr[i]+pre[i-1];
        
        vector<int>fac;
        
        for(int i=1;i*i<=pre[n-1];i++)
        {
            if(pre[n-1]%i==0)
            {
            fac.push_back(i);
            fac.push_back(pre[n-1]/i);
            }
        }
        
        int mx=1;
        
        for(auto it: fac)
        {
            int k1=0;
            
            for(auto v: pre)
            {
                if(v%it==0) k1++;
            }
            
            if(k1>=k)
            mx=max(mx,it);
        }
        
        return mx;
        
        
        
        
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> arr(N);
        Array::input(arr,N);
        
        Solution obj;
        int res = obj.solve(N, K, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends