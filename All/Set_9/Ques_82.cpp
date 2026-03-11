// 

#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u,v,w;
};

int main() {

    int V = 5;
    
    vector<Edge> edges = {
        {0,1,5},
        {1,2,-2},
        {2,3,3},
        {3,4,1}
    };

    vector<int> dist(V,1e9);
    dist[0]=0;

    for(int i=0;i<V-1;i++){
        for(auto e:edges){
            if(dist[e.u]+e.w < dist[e.v])
                dist[e.v]=dist[e.u]+e.w;
        }
    }

    for(int i=0;i<V;i++)
        cout<<dist[i]<<" ";
}

