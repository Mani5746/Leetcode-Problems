//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{
public:
  bool is_prime(int n)
  {
      
      if(n==1||n==0) return false;
      
      for(int i=2;i*i<=n;i++)
      {
          if(n%i==0) return false;
      }
      
      return true;
  }
    Node *primeList(Node *head)
    {
        
        
        struct Node* curr=head;
        
        while(curr)
        {
            if(!is_prime(curr->val))
            {
                int a=curr->val;
                int b=curr->val;
                
                while(!is_prime(a))
                a--;
                
                
                while(!is_prime(b)) b++;
                
               if(abs(a-(curr->val))<=abs(b-(curr->val)))
                curr->val=a;
                
                else if(abs(a-curr->val)>=abs(b-curr->val))
                curr->val=b;
            }
            
            curr=curr->next;
            
        }
        
        return head;
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends