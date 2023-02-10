//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s)
    {
        vector<int> hash(26,0);
        int ans=1e9+7;
        for(int i=0;i<s.size();i++)
        {
            hash[int(s[i]-'a')]++;
        }
        
        for(int i=0;i<26;i++)
        {
            if('a'+i=='b'||'a'+i=='a'||'a'+i=='n')
            {
                ans=min(ans,hash[i]);
            }
            
            else if('a'+i=='l'||'a'+i=='o')
            {
                
              ans=min(ans,hash[i]/2);

            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends