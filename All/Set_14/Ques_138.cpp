// Disjoint Set Union (Union-Find)
// Time Complexity: nearly O(1) amortized per operation

#include <iostream>
#include <vector>
using namespace std;

class DSU {
    vector<int> parent, rankv;

public:
    DSU(int n) {
        parent.resize(n);
        rankv.assign(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b) return;

        if(rankv[a] < rankv[b]) swap(a, b);
        parent[b] = a;
        if(rankv[a] == rankv[b]) rankv[a]++;
    }

    bool same(int a, int b) {
        return find(a) == find(b);
    }
};

int main() {
    int n = 7;
    DSU dsu(n);

    dsu.unite(0, 1);
    dsu.unite(1, 2);
    dsu.unite(3, 4);

    cout << dsu.same(0, 2) << "\n";
    cout << dsu.same(2, 4) << "\n";

    dsu.unite(2, 4);
    cout << dsu.same(2, 4);
}


