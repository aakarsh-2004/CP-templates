ll binpow(ll a, ll b) {
    // a ^ b
    ll res = 1;
    while(b) {
        if(b & 1) res = (res * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }

    return res % M;
}