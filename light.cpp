#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n;
    cin >> n;

    vector<long long> a(n), b(n);

    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];

    for(int i=n-1; i>0; i--) {
        if(a[i-1] % a[i] != 0) {
            cout << "No\n";
            return;
        }
    }

    for(int i=0; i<n-1; i++) {
        if(b[i+1] % b[i] != 0) {
            cout << "No\n";
            return;
        }
    }

    for(int i=0; i<n; i++) {
        if(gcd(a[i], b[i]) != a[n - 1]) {
            cout << "No\n";
        }
    }

    cout << "Yes\n";
}

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 

	#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif

	int t;
	cin >> t;

	while(t--) {
		solve();
	}
}