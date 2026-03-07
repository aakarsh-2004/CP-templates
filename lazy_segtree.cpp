class LazySegTree {
public:
	int n;
	vector<int> tree;

	LazySegTree(int n) {
		this -> n =  n;
		tree.resize(4 * n, 0);
	}

	void build(vector<int>& a, int i, int l, int r) {
		if(l == r) {
			tree[i] = a[l];
			return;
		}
		int m = (l + r) / 2;
		
		build(a, 2 * i + 1, l, m);
		build(a, 2 * i + 2, m + 1, r);

		tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
	}
};