//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    long long solve(int X,int Y,string S){
      //code here
      long long ans=0;
      string s1="pr",s2="rp";
      
      if(X<Y)
      {
         int temp=X;X=Y;Y=temp;
         string temps=s1;s1=s2;s2=temps;
         
      }
      
      stack<char> st;
      
      char first=s1[0],second=s1[1];
      int n=S.size();
      
      for(int i=n-1;i>=0;i--)
      {
          char ch=S[i];
          if(st.size()&&ch==first&&st.top()==second)
          {
              st.pop();
              ans+=X;
          }
          
          else
          st.push(S[i]);
      }
      
      S.clear();
      
      while(!st.empty())
      {
          S.push_back(st.top());
          st.pop();
      }
      
      
      
      first=s2[0],second=s2[1];
      n=S.size();
      
      for(int i=n-1;i>=0;i--)
      {
          char ch=S[i];
          if(st.size()&&ch==first&&st.top()==second)
          {
              st.pop();
              ans+=Y;
          }
          
          else
          st.push(S[i]);
      }
      
      return ans;
      
      }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends