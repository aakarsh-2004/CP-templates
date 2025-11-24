class DSU {
    vector<int> parent, rank, size;

    public:
    DSU(int n) {
        parent.resize(n + 1, 0);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);

        for(int i = 0; i <= n; i++) parent[i] = i;
    }

    int findUParent(int node) {
        if(node == parent[node]) return node;

        return parent[node] = findUParent(parent[node]);
    }

    bool unionBySize(int u, int v) {
        int upu = findUParent(u), upv = findUParent(v);

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