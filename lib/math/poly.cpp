struct Poly : V<int> {
  using V<int>::V;
};
const auto w = []() {
  constexpr int g = 3, n = 1 << 18;
  A<int, n> w;
  w[0] = 1;
  for (int i = 1; i < n; i *= 2) {
    ll mul = mi::qpow(g, (mod - 1) / (i * 4));
    FOR (j, 0, i - 1) w[i + j] = w[j] * mul % mod;
  }
  return w;
}();
void dif(Poly& f) {
  int n = sz(f);
  for (int i = n; i >>= 1;)
    for (int j = 0, p = 0; j < n; j += 2 * i, ++p)
      FOR (k, j, i + j - 1) {
        int &x = f[k], y = (ll)w[p] * f[i + k] % mod;
        f[i + k] = mi::fix(x - y), mi::add(x, y);
      }
}
void dit(Poly& f) {
  int n = sz(f);
  for (int i = 1; i < n; i *= 2)
    for (int j = 0, p = 0; j < n; j += 2 * i, ++p)
      FOR (k, j, i + j - 1) {
        int &x = f[k], y = f[i + k];
        f[i + k] = (ll)w[p] * mi::fix(x - y) % mod, mi::add(x, y);
      }
  ll mul = mi::inv(n);
  each (i, f) i = i * mul % mod;
  reverse(1 + all(f));
}
Poly& operator*=(Poly& f, Poly g) {
  int n = sz(f) + sz(g) - 1, N = bceil(n);
  f.rsz(N), g.rsz(N);
  dif(f), dif(g);
  FOR (i, 0, N - 1) f[i] = (ll)f[i] * g[i] % mod;
  dit(f), f.rsz(n);
  return f;
}
il Poly operator*(Poly f, const Poly& g) { return f *= g; }
