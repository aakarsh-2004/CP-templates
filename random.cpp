random_device rd;
mt19937 rng(rd());
ll get_random(ll l, ll r) {
    uniform_int_distribution<ll> dist(l, r);
    return dist(rng);
}
