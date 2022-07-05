#include <bits/stdc++.h>
using namespace std;
const int base = 65,inf = base*base+111;
int n,indegree[inf],outdegree[inf],vis[inf];

vector<int> adj[inf],path,undirected[inf];
set<int> Nodes;

int encodeval(char x){
    if(isupper(x))
        return x-'A'+36;
    else if(islower(x))
        return x-'a'+10;
    else
        return x-'0';
}

char decodeval(int x){
    if(x<10)
        return x+'0';
    else if(x<36)
        return x+'a'-10;
    else
        return x+'A' - 36;
}

int encode(char a,char b){
    return encodeval(a)*base+ encodeval(b);
}
pair<char,char> decode(int x){
    return make_pair(decodeval(x/base),decodeval(x%base));
}

void find_path(vector<int> adj[], int u) {
  vector<int> stack, curr_edge(inf);
  stack.push_back(u);
  while (!stack.empty()) {
    u = stack.back();
    stack.pop_back();
    while (curr_edge[u] < (int)adj[u].size()) {
      stack.push_back(u);
      u = adj[u][curr_edge[u]++];
    }
    path.push_back(u);
  }
  reverse(path.begin(), path.end());
}


bool CheckEulerPath(pair<int,int> &endpoints){

    for(auto o:Nodes){
        //cout<<decode(o).first<<" "<<decode(o).second<<endl;
        if(indegree[o] == outdegree[o])continue;
        if(indegree[o] == outdegree[o]-1){
            if(endpoints.first !=-1)return 0;
            endpoints.first = o;
        }
        else if(indegree[o] == outdegree[o]+1){
            if(endpoints.second!= -1)return 0;
            endpoints.second = o;
        }
        else
            return 0;
    }
    if(endpoints == make_pair(-1,-1))
        return endpoints.first = (*Nodes.begin()),1;
    return (endpoints.first != -1 && endpoints.second != -1);
}

void dfs(int u){
     vis[u] = 1;
     for(auto v:undirected[u])
        if(!vis[v])
            dfs(v);
}

bool isconnected(){
    dfs(*Nodes.begin());
    for(auto o:Nodes)
        if(!vis[o])return 0;
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    n -= 2;
    for(int i=1;i<=n;i++){
        string tmp;
        cin>>tmp;
        int a = encode(tmp[0],tmp[1]),b = encode(tmp[1],tmp[2]);
        adj[a].push_back(b);
        undirected[a].push_back(b),undirected[b].push_back(a);
//        if(b<0)
//            cout<<" "<<tmp<<endl;

        indegree[b]++,outdegree[a]++;
        Nodes.insert(a),Nodes.insert(b);
    }
    pair<int,int> endpoints = {-1,-1};
    if(!CheckEulerPath(endpoints) || !isconnected())
        puts("NO"),exit(0);

    find_path(adj,endpoints.first);
    cout<<"YES"<<endl;
    pair<char,char> tmp = decode(path[0]);
    cout<<tmp.first<<tmp.second;

    for(int i=1;i<path.size();i++)
        cout<<decode(path[i]).second;
    cout<<endl;
}
