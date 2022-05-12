//USACO 2012 December Contest, Gold
//Problem 2. First!
#include <bits/stdc++.h>
using namespace std;
const int inf=3e4+9,alpha=33;

set<int> adj[alpha];
vector<string> ans;
string a[inf];
int n;

struct trie{

    trie *a[alpha];
    bool IsEnd;
    trie(){
        for(int i=0;i<alpha;i++)
            a[i] = NULL;
        IsEnd=0;
    }
    void insert(string &s,int i){

        if(i == s.size())
            return void(IsEnd=1);
        int cur=s[i]-'a';
        if( a[cur] == NULL )
            a[cur] = new trie();
        a[cur] -> insert(s,i+1);
    }
    //for each string we create a directed graph of letters if there is and edge between letters x and y then x should be before y in the alphabet
    //if that graph is cyclic then this string cannot be in the first

    bool dfs(string &s,int i){
        if( i == s.size() )
            return 1;
        if( IsEnd )//there is a string which is prefix of s
            return 0;
        int cur=s[i]-'a';
        for(int i=0;i<alpha;i++)
            if( i!=cur && a[i] != NULL )
                adj[cur].insert(i);// cur should be before i

        return a[cur] -> dfs(s,i+1);
    }
};

bool Clear(){

    for(int i=0;i<alpha;i++)
        adj[i].clear();
    return 1;
}
// we do a topological sort to check if the graph is acyclic
bool check(){
    queue<int> q;
    int indegree[alpha]={0},done=0;

    for(int i=0;i<alpha;i++)
        for(auto o:adj[i])
            indegree[o]++;

    for(int i=0;i<alpha;i++)
        if( indegree[i] == 0 )
            q.push(i);

    while(!q.empty()){
        int cur=q.front();
        q.pop();
        done++;
        for(auto o:adj[cur])
            indegree[o]--;
        for(auto o:adj[cur])
            if( indegree[o] == 0 )
                q.push(o);
    }
    return ( done == alpha );
}

trie *root = new trie();

int main(){

    freopen("first.in","r",stdin);
    freopen("first.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],root -> insert(a[i],0);

    for(int i=1;i<=n;i++)
        if( Clear() &&  root -> dfs(a[i],0)  && check() )
            ans.push_back(a[i]);

    cout<<ans.size()<<endl;
    for(auto o:ans)
        cout<<o<<endl;
}