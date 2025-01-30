#include<bits/stdc++.h>
using namespace std;
void makeset(vector<int>parent,vector<int>rank_,int n){


for(int i=0;i<n;i++){
    parent[i]=i;
    rank_[i]=0;
}
}
bool cmp(vector<int>&a,vector<int>&b){

   return a[2]<b[2];
}
int findparent(vector<int>parent,int node){

  if(parent[node]==node){
    return node;
  }
  return findparent(parent,parent[node]);

}
void union_set(int u,int v,vector<int>parent,vector<int>rank_){

    u=findparent(parent,u);
    v=findparent(parent,v);
    if(rank_[u]<rank_[v]){
        parent[u]=v;

    }
    else if(rank_[u]>rank_[v]){
        parent[v]=u;

    }
    else{
        parent[v]=u;
        rank_[u]++;

    }

}


int minimumspan(vector<vector<int>>&edges,int n){

    sort(edges.begin(),edges.end(),cmp);
    vector<int>parent(n);
    vector<int>rank_(n);
    makeset(parent,rank_,n);
    int minimumsum=0;
    for(int i=0;i<edges.size();i++){
        int u=findparent(parent,edges[i][0]);
        int v=findparent(parent,edges[i][1]);
        if(u!=v){
            union_set(edges[i][0],edges[i][1],parent,rank_);
            minimumsum+=edges[i][2];
        }

    }
    return minimumsum;

}

int main(){

    int n;

    cout<<"Enter the number of edges: ";
    cin>>n;
    vector<vector<int>>edges;
    vector<int>node;
   
    for(int i=0;i<n;i++){
         int u,v,wt;
         cin>>u>>v>>wt;
         node.push_back(u);
         node.push_back(v);
         node.push_back(wt);
         edges.push_back(node);
         node.clear();
    }
    cout<<"Minimumspaning tree: "<<minimumspan(edges,n)<<endl;


}