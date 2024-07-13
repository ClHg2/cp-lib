#include <x86intrin.h>

#include <ext/random>

__gnu_cxx::sfmt19937 rng{unsigned(__rdtsc())};
ttt > il T rand(T l, T r) {
  assert(l <= r);
  return uniform_int_distribution<T>{l, r}(rng);
}
