// Union-Find (Disjoint Set)

#include <iostream>
using namespace std;

int parent[100];
int rankArr[100];

void makeSet(int n) {
    for(int i=0;i<n;i++) {
        parent[i] = i;
        rankArr[i] = 0;
    }
}

int findParent(int node) {
    if(parent[node] == node)
        return node;

    return parent[node] = findParent(parent[node]);
}

void unionSet(int u, int v) {
    u = findParent(u);
    v = findParent(v);

    if(u != v) {
        if(rankArr[u] < rankArr[v])
            parent[u] = v;
        else if(rankArr[v] < rankArr[u])
            parent[v] = u;
        else {
            parent[v] = u;
            rankArr[u]++;
        }
    }
}

int main() {

    makeSet(5);

    unionSet(0,1);
    unionSet(1,2);

    if(findParent(0) == findParent(2))
        cout << "Same Set";
    else
        cout << "Different Set";
}

