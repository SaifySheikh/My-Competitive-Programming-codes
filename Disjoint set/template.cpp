#include <iostream>
#include <vector>
using namespace std;

class DisjointSet{
    vector<int> rank, parent,size;
public:
    DisjointSet(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n+1,1);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }

    int finduparent(int u){
        if(parent[u] != u){
            parent[u] = finduparent(parent[u]); // Path compression
        }
        return parent[u];
    }

    void unionByRank(int u, int v){
        int up_u = finduparent(u);
        int up_v = finduparent(v);
        if(up_u == up_v) return;

        if(rank[up_u] < rank[up_v]){
            parent[up_u] = up_v;
        } else if(rank[up_u] > rank[up_v]){
            parent[up_v] = up_u;
        } else {
            parent[up_v] = up_u;
            rank[up_u]++;
        }
    }

    void unionBySize(int u,int v){
        int up_u=finduparent(u);
        int up_v=finduparent(v);
        if(up_u==up_v) return;
        if(size[up_u] < size[up_v]){
            parent[up_u]=up_v;
            size[up_v]+=size[up_u];
        }else if(size[up_u] > size[up_v]){
            parent[up_v]=up_u;
            size[up_u]+=size[up_v];
        }
    }
};

int main(){
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    if(ds.finduparent(4) == ds.finduparent(5)){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    if(ds.finduparent(3) == ds.finduparent(7)){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
