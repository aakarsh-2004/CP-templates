class DisjointSet {
    vector<int> parent, rank;

    public:
    DisjointSet(int n) {
        parent.resize(n + 1, 0);
        rank.resize(n + 1, 0);

        for(int i = 0; i <= n; i++) parent[i] = i;
    }

    int findUParent(int node) {
        if(node == parent[node]) return node;

        return parent[node] = findUParent(parent[node]);
    }

    bool unionByRank(int u, int v) {
        int upu = findUParent(u), upv = findUParent(v);

        if(upu == upv) return false;

        int rank1 = rank[upu], rank2 = rank[upv];

        if(rank1 < rank2) {
            parent[upu] = parent[upv];
        } 
        else if(rank2 < rank1) {
            parent[upv] = parent[upu];
        }
        else {
            parent[upv] = parent[upu];
            rank[upu]++;
        }

        return true;
    }
}