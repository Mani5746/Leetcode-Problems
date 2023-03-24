//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string S) 
    {
        // code here
       map<char,int>mp;
        for(int i=0;i<S.size();i++){
            mp[S[i]]++;
        }
        int i=0,j=S.size()-1;
        int flag=1;
        while(i<j){
            if(flag){
                if(mp[S[i]]==1){i++; }
                else{
                   
                    mp[S[i]]--;
                     S[i]='*';
                    flag=0;
                    i++;
                } 
                
            }
            else{
                
                if(mp[S[j]]==1) {j--; }
                else{
                    
                    mp[S[j]]--;
                    S[j]='*';
                    flag=1;
                    j--;
                } 
                
            }
        }
        
        string ans;
        for(auto it: S) if(it!='*') ans.push_back(it);
        
        if(flag==0) reverse(ans.begin(),ans.end());
        
        return ans;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends