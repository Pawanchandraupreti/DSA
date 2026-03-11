// Activity Selection (Greedy)

#include <iostream>
using namespace std;

int main() {

    int INF = 1e9;

    int dist[4][4] = {
        {0,3,INF,7},
        {8,0,2,INF},
        {5,INF,0,1},
        {2,INF,INF,0}
    };

    int V=4;

    for(int k=0;k<V;k++)
        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++)
                if(dist[i][k]+dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++)
            cout<<dist[i][j]<<" ";
        cout<<endl;
    }
}

