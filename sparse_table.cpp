class SparseTable {
    public:
    vector<vector<int>> mn, mx;
    int n, K;
    vector<int> log;
    
    SparseTable(const vector<int>& a) {
        n = (int)a.size();
        K = log2(n) + 1;
        
        mn.assign(n, vector<int>(K));
        mx.assign(n, vector<int>(K));

        for(int i = 0; i < n; i++) {
            mn[i][0] = a[i];
            mx[i][0] = a[i];
        }

        log.assign(n + 1, 0);
        for(int i = 2; i <= n; i++) {
            log[i] = log[i / 2] + 1;
        }

        for(int j = 1; j < K; j++) {
            for(int i = 0; i + (1LL << j) - 1 < n; i++) {
                mn[i][j] = min(mn[i][j - 1], mn[i + (1LL << (j - 1))][j - 1]);
            }
        }
        for(int j = 1; j < K; j++) {
            for(int i = 0; i + (1LL << j) - 1 < n; i++) {
                mx[i][j] = max(mx[i][j - 1], mx[i + (1LL << (j - 1))][j - 1]);
            }
        }
    }

    int queryMin(int L, int R) {
        int j = log[R - L + 1];

        return min(mn[L][j], mn[R - (1LL << j) + 1][j]);
    }

    int queryMax(int L, int R) {
        int j = log[R - L + 1];

        return max(mx[L][j], mx[R - (1LL << j) + 1][j]);
    }
};