#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define x first
#define y second
#define ld long double
#define ll long long
#define ull unsigned long long
#define us unsigned short
#define lsb(x) ((x) & (-(x)))
 
using namespace std;
 
const int X = 5; // number of "buckets" ?!
const int N = (int)1e7; // precalculated values
 
ll n;
 
bitset <N + 5> viz;
vector <int> prime;
unordered_map <ll, ll> calc_phi, calc_pi, p[5];
int pi[N + 5];
int memo[(1 << 10)];
 
ll get_pi(ll n);
//ll P(int niv, ll n, int a);
 
void sieve() {
  prime.push_back(0);
  for(int i = 4; i <= N; i += 2)
    viz[i] = 1;
  for(int i = 3; i * i <= N; i++) {
    if(!viz[i]) {
      for(int j = i * i; j <= N; j += 2 * i)
        viz[j] = 1;
    }
  }
  for(int i = 2; i <= N; i++) {
    pi[i] = pi[i - 1];
    if(!viz[i])
      prime.push_back(i), pi[i]++;
  }
}
 
void precalc() {
  for(int i = 0; i < (1 << 5); i++) {
      int prod = 1;
      for(int j = 0; j < 5; j++) {
        if((i >> j) & 1)
          prod *= prime[j + 1];
      }
      memo[i] = (__builtin_popcount(i) % 2 == 0 ? 1 : -1) * prod;
  }
}
 
ll cod(ll n, int m) {
  return n * 10000 + m;
}
 
ll f(ll n, int m) {
  if(!n)
    return 0;
  if(m == 0) {
    //calc[cod(n, m)] = ans;
    return n;
  }
  /*if(calc_phi.find(cod(n, m)) != calc_phi.end())
    return calc_phi[cod(n, m)];
  calc_phi[cod(n, m)] = f(n, m - 1) - f(n / prime[m], m - 1);
  return calc_phi[cod(n, m)];*/
  return f(n, m - 1) - f(n / prime[m], m - 1);
}
 
ll P(int niv, ll n, int a) {
  int b = get_pi((ll)(pow(n, 1.0 / niv) + 1e-9));
  ll ans = 0;
  if(niv == 2) {
    for(int i = a + 1; i <= b; i++)
      ans += get_pi(n / prime[i]);
    ans -= 1LL * (b - a) * (b + a - 1) / 2;
  } else {
    for(int i = a + 1; i <= b; i++)
      ans += P(niv - 1, n / prime[i], i - 1);
  }
  return ans;
}
 
void reset() {
  calc_phi.clear();
  calc_pi.clear();
  for(int i = 2; i < X; i++)
    p[i].clear();
}
 
ll get_pi(ll n) { // number of primes <= n
  if(n <= N)
    return pi[n];
  int a = get_pi((int)(pow(n, 1.0 / X) + 1e-9));
  ll ans = f(n, a) + a - 1;
  for(int i = 2; i <= X; i++)
    ans -= P(i, n, a);
  return ans;
}
 
ll get_prime(ll n) { // n-th prime number
  if(n <= 1000)
    return prime[n];
  ll st = n * log(n) + n * log(log(n)) - n, dr = n * log(n) + n * log(log(n)), mid;
  while(st <= dr) {
    mid = (st + dr) >> 1;
    //reset();
    if(get_pi(mid) < n)
      st = mid + 1;
    else
      dr = mid - 1;
  }
  return st;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();
    int t; cin>>t;
    for(int c=0; c<t; c++){
        long int x; cin >> x;
        long int y; cin >> y;
        if(pi[x]>y){
            cout << "Divyam\n";
        }else{
            cout << "Chef\n";
        }
    }
    return 0;
}