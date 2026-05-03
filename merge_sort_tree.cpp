class MergeSortTree {
public:
    vector<vector<int>> tree;
    int n;

    MergeSortTree(vector<int>& a) {
        n = a.size();
        tree.resize(4 * n);
        build(a, 0, 0, n - 1);
    }

    void build(vector<int>& a, int node, int l, int r) {
        if(l == r) {
            tree[node] = { a[l] };
            return;
        }
        int mid = l + (r - l) / 2;
        build(a, 2 * node + 1, l, mid);
        build(a, 2 * node + 2, mid + 1, r);
        
        tree[node].resize(tree[2 * node + 1].size() + tree[2 * node + 2].size());
        merge(tree[2 * node + 1].begin(), tree[2 * node + 1].end(),
              tree[2 * node + 2].begin(), tree[2 * node + 2].end(),
              tree[node].begin());
    }

    int query(int l, int r, int k) {
        return query(0, 0, n - 1, l, r, k);
    }

    int query(int node, int nodeL, int nodeR, int queryL, int queryR, int k) {
        if(nodeR < queryL || nodeL > queryR) return 0;
        
        if(nodeL >= queryL && nodeR <= queryR) {
            auto it = lower_bound(tree[node].begin(), tree[node].end(), k);
            return distance(tree[node].begin(), it);
        }
        
        int mid = nodeL + (nodeR - nodeL) / 2;
        return query(2 * node + 1, nodeL, mid, queryL, queryR, k) + 
               query(2 * node + 2, mid + 1, nodeR, queryL, queryR, k);
    }
};