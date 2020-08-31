#include <bits/stdc++.h>
using namespace std;
#define ll long int

vector<int > adj[100005];
int vis[100005]={0};
ll in[100005], low[100005];
set<ll > ans;
//finding bridges in a graph
ll timer=0;
void dfs(ll u, ll par){
    vis[u]=1;
    in[u]=low[u]=timer;
    timer++;
    ll count=0;
    for(auto child: adj[u]){
        if(child==par)continue;
        else if(vis[child]==1){
            //back edge
            low[u]=min(low[u],in[child]);
        }
        else{
            dfs(child,u);
            
            if(low[child]>=in[u] && par!=-1){//means child can only be visited through long 
            //path that is from u and no other node
                //cout<<"Bridge found :-  "<<u<<" -- "<<child<<endl;
                ans.insert(u);
            }
            low[u]=min(low[u],low[child]);
            count++;
        }
    }
   if(par==-1 && count>1){
        ans.insert(u);
    }
}
int main()
{
    ll m,n,x,y;
    while(1){
        cin>>m>>n;
        if(m==0 && n==0)break;
        for(int i=0;i<n;i++){
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs(1,-1);
       cout<<ans.size()<<endl;
       ans.clear();
        for(int i=0;i<=m;i++){
                adj[i].clear();vis[i]=0;
        }
    }
    return 0;
}
