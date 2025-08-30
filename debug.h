#define ll long long
#define nl endl
#define all(arr) arr.begin(), arr.end()
#define sz(v) (int)v.size()


// debugging
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << "[ " << #x << " ] = "; _print(x); cerr << endl;
#else
    #define debug(x)
#endif

// debug printers
void _print(int x){cerr<<x;}
void _print(ll x){cerr<<x;}
void _print(string x){cerr<<x;}
void _print(char x){cerr<<x;}
void _print(bool x){cerr<<(x?"true":"false");}

template <class T> void _print(vector<T> v1) { cerr << "[ "; for(T i: v1) { _print(i); cerr << ", "; } cerr << " ]\n"; }
template <class T, class V> void _print(map<T, V> mp1) { cerr << "[ \n"; for(auto i: mp1) cerr << i.ff << " : " << i.ss << endl; cerr << "]\n";}
template <class T> void _print(set<T> s1) { cerr << "[ "; for(auto i: s1) cerr << i << ", "; cerr << "]" << endl;}
template <class T> void _print(multiset<T> s1) { cerr << "[ "; for(auto i: s1) cerr << i << ", "; cerr << "]" << endl;}
template <class T, class V> void _print(pair<T, V> p) { cerr << "[ " << p.ff << " : " << p.ss << " ] " << endl; };
template <class T> void _print(priority_queue<T> pq) { cerr << "[ "; while(!pq.empty()) { cerr << pq.top() << " "; pq.pop(); }; cerr << " ]\n"; }
template <class T, class V> void _print(priority_queue<pair<T, V>> pq) { cerr << "[\n"; while(!pq.empty()) { cerr << pq.top().ff << ", " << pq.top().ss << "\n"; pq.pop(); }; cerr << "]\n"; }
