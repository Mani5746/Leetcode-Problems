//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string num, int k)
{
    //code here.
    stack<char>st;
    int n=num.size();
    for(int i=0;i<n;i++)
    {
        while(!st.empty()&&(st.top()-'0'>num[i]-'0')&&k)
        {
            st.pop();
            k--;
        }
        st.push(num[i]);
    }
    
    while((k>0)&&(!st.empty()))
    {
        st.pop();
        k--;
    }
    
  
    
   
    string ans="";
    
    
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    
    int j=ans.size()-1;
    
    while(j>=0)
    {
        if(ans[j]!='0') break;
        
        ans.pop_back();
        j--;
        
    }
    
    
    
    if(ans.size()==0) return "0";
    
    reverse(ans.begin(),ans.end());
    return ans;
}

