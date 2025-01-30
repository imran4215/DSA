//kruskal's

#include<bits/stdc++.h>
using namespace std;

const int N=1e5+6;
int parent[N];
int size[N];

void make_set(int v){
    parent[v]=v;
    size[v]=1;
}

int find_set(int v){
    if(v==parent[v]){
        return v;
    }
    return parent[v]=find_set(parent[v]);
}

void union_sets(int a,int b){
    a=find_set(a);
    b=find_set(b);
    if(a!=b){
        if(size[a]<size[b]){
            swap(a,b);
        }
        parent[b]=a;
        size[a]+=size[b];
    }
}

int main(){
    for(int i=0;i<N;i++){
        make_set(i);
    }
    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>>edges;

    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        edges.push_back({w,{x,y}});
    }

    sort(edges.begin(),edges.end());

    int cost=0;

    for(auto i:edges){
        int w=i.first;
        int x=i.second.first;
        int y=i.second.second;

        int a=find_set(x);
        int b=find_set(y);

        if(a==b){
            continue;
        }
        else{
            cout<<x<<" "<<y<<endl;
            cost+=w;
            union_sets(x,y);
        }
    }

    cout<<cost<<endl;
    
    return 0;
}
