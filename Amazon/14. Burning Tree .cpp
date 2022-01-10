// https://practice.geeksforgeeks.org/problems/burning-tree/1/
// https://www.youtube.com/watch?v=dtBj2A_7JOk

// { Driver Code Starts
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

class Solution {
  public:
    unordered_map<Node *, Node *> parent;
    Node * tN= NULL;
    void dfs(Node * root,  int target, Node * par = NULL){
        if(!root){
            return;
        }
        if(root->data == target){
            tN = root;
        }
        if(par) parent[root] = par;
        dfs(root->left, target, root);
        dfs(root->right, target, root);
    }
  
    int minTime(Node* root, int target) 
    {
        dfs(root, target);
        unordered_map<Node *, bool> vis;
        queue<pair<Node *, int>> q;
        q.push({tN, 0});
        vis[tN] = true;
        int m = 0;
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            Node * temp = t.first;
            int ti = t.second;
            m = max(m, ti);
            vis[temp] = true;
            if(temp->left && vis.count(temp->left) == 0)
            {
                q.push({temp->left, ti + 1});
                vis[temp->left] = true;
            }
            if(temp->right && vis.count(temp->right) == 0)
            {
                q.push({temp->right, ti + 1});
                vis[temp->right ] =true;
            }
            if(parent[temp] && vis.count(parent[temp]) == 0)
            {
                q.push({parent[temp], ti + 1});
                vis[parent[temp]] = true;
            }
        }
        return m;
    }
};

// { Driver Code Starts.

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