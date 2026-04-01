class DSU {
    vector<int> parent, size;

    public:
    DSU(int n) {
        parent.resize(n + 1, 0);
        size.resize(n + 1, 1);

        for(int i = 0; i <= n; i++) parent[i] = i;
    }

    int find(int node) {
        if(node == parent[node]) return node;

        return parent[node] = find(parent[node]);
    }

    bool unite(int u, int v) {
        int upu = find(u), upv = find(v);

        if(upu == upv) return false;

        int size1 = size[upu], size2 = size[upv];

        if(size1 < size2) {
            parent[upu] = upv;
            size[upv] += size[upu];
        }
        else {
            parent[upv] = upu;
            size[upu] += size[upv];
        }

        return true;
    }
};