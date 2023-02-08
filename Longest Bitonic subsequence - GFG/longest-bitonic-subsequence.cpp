//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n=nums.size();
	    
	    vector<int> dp1(n,1);
	      vector<int> dp2(n,1);
	    
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int p=0;p<i;p++)
	        {
	            if(nums[p]<nums[i]&&1+dp1[p]>dp1[i])
	            {
	                dp1[i]=1+dp1[p];
	                
	                
	                
	            }
	        }
	    }
	    
	    
	     for(int i=n-1;i>=0;i--)
	    {
	        for(int p=n-1;p>=i;p--)
	        {
	            if(nums[p]<nums[i]&&1+dp2[p]>dp2[i])
	            {
	                dp2[i]=1+dp2[p];
	                
	                
	                
	            }
	        }
	    }
	    
	    int ans=0;
	    
	    for(int i=0;i<n;i++)
	    {
	        ans=max(ans,dp1[i]+dp2[i]-1);
	    }
	    
	    return ans;
	    
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends