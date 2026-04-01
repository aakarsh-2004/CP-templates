// Kosaraju's algorithm

const int N = 1e5 + 1;
vector<int> adj[N], radj[N];
vector<int> vis, component, order;

void kosaraju() {
	int n, m;
	cin >> n >> m;

	for(int i = 1; i <= n; i++) {
		adj[i].clear();
		radj[i].clear();
	}
	order.clear();

	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		radj[v].push_back(u);
	}

	vis.assign(n + 1, 0);
	component.resize(n + 1);

	auto dfs1 = [&](auto&& self, int u) {
		vis[u] = 1;

		for(auto v: adj[u]) {
			if(!vis[v]) self(self, v);
		}

		order.push_back(u);
	};

	auto dfs2 = [&](auto&& self, int u, int comp) {
		vis[u] = 1;
		component[u] = comp;

		for(auto v: radj[u]) {
			if(!vis[v]) self(self, v, comp);
		}
	};

	for(int i = 1; i <= n; i++) {
		if(!vis[i]) dfs1(dfs1, i);
	}

	reverse(order.begin(), order.end()); 
	
	vis.assign(n + 1, 0); 
	int comp = 0;

	for(auto u: order) {
		if(!vis[u]) {
			comp++;
			dfs2(dfs2, u, comp);
		}
	}

	cout << comp << "\n";
	for(int i = 1; i <= n; i++) {
		cout << component[i] << " ";
	}
	cout << "\n";
}