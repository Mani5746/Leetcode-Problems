//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  
  
  Node* markparent(Node* root,unordered_map<Node*,Node*>&parent,int target)
{
    queue<Node*>qu;
    qu.push(root);
    Node* res=NULL;

    while(!qu.empty())
    {
        auto node=qu.front(); qu.pop();
        
        if(node->data==target) 
           res=node;
        
        if(node->left)
        {
            parent[node->left]=node;
            qu.push(node->left);
        }


         if(node->right)
        {
            parent[node->right]=node;
            qu.push(node->right);
        }
    }
    
    
    
    return res;

}

    int minTime(Node* root, int tar) 
    {
        // Your code goes here
        unordered_map<Node*,Node*> parent;
      Node* target= markparent(root,parent,tar);
        
          unordered_map<Node*,bool> vis;
        queue<Node*> qu;
        qu.push(target);

        vis[target]=true;
        int cur_level=0;

        while(!qu.empty())
        {
            int sz=qu.size();
            cur_level++;

            for(int i=0;i<sz;i++)
            {
                auto curr=qu.front(); qu.pop();

                if(curr->left&&!vis[curr->left])
                {
                    vis[curr->left]=true;
                    qu.push(curr->left);
                }

                 if(curr->right&&!vis[curr->right])
                {
                    vis[curr->right]=true;
                    qu.push(curr->right);
                }


                if(parent[curr]&&!vis[parent[curr]])
                {
                    vis[parent[curr]]=true;
                    qu.push(parent[curr]);
                }
            }

        }
        
        return cur_level-1;

        
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends