#include<bits/stdc++.h>

using namespace std;

const int LIM = 1e7 + 20;
int primes[LIM];

int main() {
	for(int i=2; i<LIM; i++) {
		if(primes[i] != -1) {
			for(int j=i*i; j<LIM; j+=i) {
				primes[j] = -1;
			}
		}
	}

	return 0;
}