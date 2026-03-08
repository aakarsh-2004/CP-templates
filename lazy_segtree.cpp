class LazySegmentTree {
public:
    vector<long long> tree;
    vector<long long> lazy;
    int n;

    LazySegmentTree(vector<int>& a) {
        n = a.size();
        tree.resize(4 * n);
        lazy.assign(4 * n, 0);
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

    void push(int node, int l, int r) {
    	if(lazy[node] != 0) {
    		tree[node] += (r - l + 1) * lazy[node];

    		if(l != r) {
    			lazy[2 * node + 1] += lazy[node];
    			lazy[2 * node + 2] += lazy[node];
    		}
    		lazy[node] = 0;
    	}
    }

    void updateRange(int l, int r, int val) {
        updateRange(0, 0, n - 1, l, r, val);
    }

    void updateRange(int node, int nodeL, int nodeR, int queryL, int queryR, int val) {
    	push(node, nodeL, nodeR);

    	if(queryL > nodeR || queryR < nodeL) return;

        if(nodeL >= queryL && nodeR <= queryR) {
        	lazy[node] += val;
        	push(node, nodeL, nodeR);
        	return;
        }

        int mid = (nodeL + nodeR) >> 1;

        updateRange(2 * node + 1, nodeL, mid, queryL, queryR, val);
        updateRange(2 * node + 2, mid + 1, nodeR, queryL, queryR, val);

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    long long query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }

    long long query(int node, int nodeL, int nodeR, int queryL, int queryR) {
    	push(node, nodeL, nodeR);

        if(nodeR < queryL || nodeL > queryR) return 0;
        if(nodeL >= queryL && nodeR <= queryR) return tree[node];
        
        int mid = nodeL + (nodeR - nodeL) / 2;
        return query(2 * node + 1, nodeL, mid, queryL, queryR) + 
               query(2 * node + 2, mid + 1, nodeR, queryL, queryR);
    }
};