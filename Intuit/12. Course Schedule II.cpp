//https://leetcode.com/problems/course-schedule-ii/

 class Solution {
public:
    void dfs(int src,vector<bool>&vis,vector<bool>&dfsvis,stack<int>&st,vector<int>adj[],int &flag)
    {
      vis[src]=true;
      dfsvis[src]=true;
     
        for(auto &x:adj[src]){

        if(!vis[x]){
         dfs(x,vis,dfsvis,st,adj,flag);
        }
        else if(dfsvis[x]==true){
         flag=0;
         return;
        }
        }
        dfsvis[src]=false;
        st.push(src);
    
    }
    vector<int> findOrder(int n, vector<vector<int>>& pre) 
    {       //First form a graph considering prerequisites as directed edges
        //Here we need to check if there is a cycle in the graph
        //Also we need to find topological ordering which says that if u->v there is an edge then u comes before v  thus we make edge such that u course is to be done before v
            vector<int>ans;
        vector<int>adj[n];
        //no of vertices will be equal to no of courses
    for(int i=0;i<pre.size();i++){

    adj[pre[i][1]].push_back(pre[i][0]);
    
    }
        
        stack<int>st;  //for topo order
        vector<bool>vis(n,false);
        vector<bool>dfsvis(n,false);   //for checking if forming a cycle
       int flag;
        for(int i=0;i<n;i++){
            flag=1;
        if(!vis[i]){
            dfs(i,vis,dfsvis,st,adj,flag);
        }
        if(flag==0){
        return ans;
}
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
      }
        return ans;
    }
};