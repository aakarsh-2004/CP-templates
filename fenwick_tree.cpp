class FenwickTree {
    public:
    vector<int> a, tree;
    int n;

    FenwickTree(const vector<int>& b) {
        n = b.size() + 1;
        a.resize(n);

        for(int i = 0; i < sz(b); i++) {
            a[i + 1] = b[i];
        }

        tree.assign(n, 0);
        build();
    }
    
    void build() {
        for(int i = 1; i < n; i++) {
            update(i, a[i]);
        }
    }

    int query(int k) {
        int res = 0;
        while(k >= 1) {
            res += tree[k];
            k -= (k & (-k));
        }
        return res;
    }
    void update(int k, int x) {
        while(k < n) {
            tree[k] += x;
            k += (k & (-k));
        }
    }
};