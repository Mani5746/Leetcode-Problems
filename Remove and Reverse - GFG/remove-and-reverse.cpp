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
        int n=S.size();
        map<char,int> mp;
        for(auto ch:S) mp[ch]++;
        
        int start=0,end=n-1;
        //vector<int> ans(S.size()+1,0);
        
        int dir=0;
        while(start<end)
        {
            
            if(dir==0)
            {
                if(mp[S[start]]==1)
                {
                    start++;
                }
                
                else
                {
                    mp[S[start]]--;
                    S[start]='#' ;
                    start++;
                    dir=1;
                }
            }
            
            else
            {
                if(mp[S[end]]==1)
                {
                    end--;
                }
                
                else
                {
                    mp[S[end]]--;
                    S[end]='#';
                    end--;
                    dir=0;
                }
            }
        }
        
        
        string ans;
        
        
        for(auto it:S)
        {
            if(it!='#') ans.push_back(it);
        }
        
        if(dir) reverse(ans.begin(),ans.end());
        
        
        
        
        
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