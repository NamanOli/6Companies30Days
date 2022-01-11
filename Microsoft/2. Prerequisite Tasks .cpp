// https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1/


/*
We can consider this problem as a graph (related to topological sorting) problem.
 All tasks are nodes of the graph and if task u is a prerequisite of task v, 
 we will add a directed edge from node u to node v. Now, this problem is equivalent to
  detecting a cycle in the graph represented by prerequisites.
   If there is a cycle in the graph, then it is not possible to finish all tasks
    (because in that case there is no any topological order of tasks).
     Both BFS and DFS can be used to solve it.

Since pair is inconvenient for the implementation of graph algorithms,
 we first transform it to a graph. If task u is a prerequisite of task v,
  we will add a directed edge from node u to node v.

Prerequisite : Detect Cycle in a Directed Graph
Using DFS For DFS, it will first visit a node, then one neighbor of it, 
then one neighbor of this neighbor... and so on. If it meets a node which was 
visited in the current process of DFS visit, a cycle is detected and we will return false.
 Otherwise it will start from another unvisited node and repeat this process till
  all the nodes have been visited. Note that you should make two records: one is to 
  record all the visited nodes and the other is to record the visited nodes in the 
  current DFS visit.
The code is as follows. We use a vector visited to record all the visited nodes and
 another vector onpath to record the visited nodes of the current DFS visit.
  Once the current visit is finished, we reset the onpath value of the starting node
   to false.
*/


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	vector<int> adj[10000];
    bool dfs(int node,int vis[],int dfsvis[]){
        vis[node]=1;
        dfsvis[node]=1;
        for(int x:adj[node]){
            if(vis[x]==0){
                if(dfs(x,vis,dfsvis)) return 1;
            }
            else if(dfsvis[x]==1)
                return 1;
        }
        dfsvis[node]=0;
        return 0;
    }
    
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    int vis[N];
	    int dfsvis[N];
	    memset(vis,0,sizeof vis);
	    memset(dfsvis,0,sizeof vis);
	    for(auto it:prerequisites){
	        adj[it.second].push_back(it.first);
	    }
        for(int i=0;i<N;i++){
         if(!vis[i]){
             if(dfs(i,vis,dfsvis))
                return 0;
         }
        }
        return 1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends
