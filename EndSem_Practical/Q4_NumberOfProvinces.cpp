#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]); 
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if(px == py) return;

        
        if(size[px] < size[py]) {
            parent[px] = py;
            size[py] += size[px];
        } else {
            parent[py] = px;
            size[px] += size[py];
        }
    }
};

int main() {
    int n;
    cin >> n;

    vector<vector<int>> isConnected(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> isConnected[i][j];
        }
    }

    DSU dsu(n);

   
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(isConnected[i][j] == 1) {
                dsu.unite(i, j);
            }
        }
    }


    int provinces = 0;
    for(int i = 0; i < n; i++) {
        if(dsu.find(i) == i)
            provinces++;
    }

    cout << provinces << endl;

    return 0;
}
