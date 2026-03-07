class SegmentTree {
public:
    vector<long long> tree;
    int n;

    SegmentTree(vector<int>& a) {
        n = a.size();
        tree.resize(4 * n);
        build(a, 0, 0, n - 1);
    }

    void build(vector<int>& a, int node, int l, int r) {
        if(l == r) {
            tree[node] = a[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(a, 2 * node + 1, l, mid);
        build(a, 2 * node + 2, mid + 1, r);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    void update(int i, int val) {
        update(0, 0, n - 1, i, val);
    }

    void update(int node, int l, int r, int i, int val) {
        if(l == r) {
            tree[node] = val;
            return;
        }
        int mid = l + (r - l) / 2;
        if(i <= mid) update(2 * node + 1, l, mid, i, val);
        else update(2 * node + 2, mid + 1, r, i, val);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    long long query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }

    long long query(int node, int nodeL, int nodeR, int queryL, int queryR) {
        if(nodeR < queryL || nodeL > queryR) return 0;
        if(nodeL >= queryL && nodeR <= queryR) return tree[node];
        
        int mid = nodeL + (nodeR - nodeL) / 2;
        return query(2 * node + 1, nodeL, mid, queryL, queryR) + 
               query(2 * node + 2, mid + 1, nodeR, queryL, queryR);
    }
};