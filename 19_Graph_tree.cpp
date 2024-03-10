#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>&graphs, int src,vector<int>&visited){
    cout<<src<<" ";
    visited[src]=1;
    for(auto i:graphs[src]){
        if(visited[i])continue;
        dfs(graphs, i,visited);
    }
}
void bfs(vector<vector<int>>&graphs, int src,vector<int>&visited){
    queue<int>q;
    q.push(src);
    visited[src]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        for(auto i:graphs[node]){
            if(visited[i])continue;
            q.push(i);
            visited[i]=1;
        }
    }
}
int main(){
vector<vector<int>>graphs({{1,2,3},{0,4,5},{0},{0,6},{1},{1,7},{3},{5}});
int n=graphs.size();
vector<int>vis(n, 0),vis2(n,0);
cout<<"dfs print"<<endl;
dfs(graphs,0,vis);
cout<<endl<<"bfs print"<<endl;
bfs(graphs,0,vis2);
return 0;
}