//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    string rearrange (string S, int N)
    {
        // your code here
        string vow,cons;
        vector<int> v(26,0);
        vector<int> c(26,0);
        
        //sort(S.begin(),S.end());
        
        for(int i=0;i<N;i++)
        {
            if(S[i]=='a'||S[i]=='e'||S[i]=='i'||S[i]=='o'||S[i]=='u')
            {
              //vow.push_back(S[i]);
              v[S[i]-'a']++;
            }
            
            else c[S[i]-'a']++;
        }
        
        for(int i=0;i<26;i++)
        {
            vow+=string(v[i],('a'+i));
        }
        
        for(int i=0;i<26;i++)
        {
            cons+=string(c[i],('a'+i));
        }
        
        
        
        string ans;
        
        if(N%2==0)
        {
            if(cons.size()!=vow.size()) return "-1";
           
            if((cons[0]-'a')<(vow[0]-'a'))
            {
                int j1=0,j2=0;
            
            for(int i=0;i<N;i++)
            {
                
                if(i%2==0){ ans.push_back(cons[j1]); j1++;}
                
                else {ans.push_back(vow[j2]); j2++;}
            }
            
            }
            
            else
            {
                 int j1=0,j2=0;
            
            for(int i=0;i<N;i++)
            {
                
                if(i%2==0){ ans.push_back(vow[j1]); j1++;}
                
                else {ans.push_back(cons[j2]); j2++;}
            }
            
            }
            
        }
        
        
        else
        {
            int v=vow.size();
            int c=cons.size();
            
            if(abs(v-c)!=1) return "-1";
            
            if(cons.size()>vow.size())
        {
                int j1=0,j2=0;
            
            for(int i=0;i<N;i++)
            {
                
                if(i%2==0){ ans.push_back(cons[j1]); j1++;}
                
                else {ans.push_back(vow[j2]); j2++;}
            }
            
        }
        
        
        else
        
        {
            int j1=0,j2=0;
            
            for(int i=0;i<N;i++)
            {
                
                if(i%2==0){ ans.push_back(vow[j1]); j1++;}
                
                else {ans.push_back(cons[j2]); j2++;}
            }
        }
        
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		Solution ob;
		cout << ob.rearrange (s, n) << endl;
	}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends