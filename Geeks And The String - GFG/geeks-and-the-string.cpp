//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) 
    {
        // code here
        stack<char>st;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(st.empty())
            st.push(s[i]);
            
            else if(st.top()==s[i]) st.pop();
            
            else st.push(s[i]);
            
        }
        
        if(st.empty()) return "-1";
        
        string ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
        
       // reverse(ans.)
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends