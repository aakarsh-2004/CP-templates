long long computeHash(string const& s) {
	const int p = 31;
	const int m = 1e9 + 7;
	long long hash = 0;
	long long power = 1;

	for(auto ch: s) {
		hash = (hash + (ch - 'a' + 1) * power) % M;
		power = power * p % M;
	}
	return hash;
}