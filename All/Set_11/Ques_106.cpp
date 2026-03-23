// Shortest Path in Grid (BFS)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

    vector<vector<int>> grid = {
        {0,1,0},
        {0,0,0},
        {1,0,0}
    };

    int n = 3, m = 3;

    queue<pair<int,int>> q;
    q.push({0,0});

    vector<vector<int>> dist(n, vector<int>(m, -1));
    dist[0][0] = 0;

    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};

    while(!q.empty()) {
        auto [x,y] = q.front();
        q.pop();

        for(int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx>=0 && ny>=0 && nx<n && ny<m &&
               grid[nx][ny]==0 && dist[nx][ny]==-1) {

                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx,ny});
            }
        }
    }

    cout << dist[n-1][m-1];
}