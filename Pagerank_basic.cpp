#include <array>
#include <algorithm>
#include <numeric>
#include <iostream>

// vec<T,N> : T型のN行ベクトル
template<typename T,size_t N>
using vec = std::array<T,N>;

// mat<T,M,N> : T型のM行N列行列
template<typename T, size_t M, size_t N>
using mat = std::array<vec<T,N>,M>;

// ベクトルのstreamへの出力
template<typename T, size_t N>
std::ostream& operator<<(std::ostream& stream, const vec<T, N>& v) {
  bool first = true;
  for ( const T x : v) {
    if (!first) { stream << ", "; }
    stream << x;
    first = false;
  }
  return stream;
}

// 行列のstreamへの出力
template<typename T, size_t M, size_t N>
std::ostream& operator<<(std::ostream& stream, const mat<T, M, N>& m) {
  for ( int r = 0; r < M; ++r ) {
    stream << m[r];
    if ( r != M-1 ) stream << std::endl;
  }
  return stream;
}

// 確率ベクトルを作る: v(N行ベクトル)の非0要素を 1/(非0要素数) にする
// (要素の総和は1となる)
template<typename T, size_t N>
void stochastic(vec<T, N>& v) {
  // 非0要素数をnに求め
  int n = std::count_if(v.begin(), v.end(), [](T x) { return x != T(0);});
  // 非0要素を 1/n にする
  for ( T& x : v ) { if ( x != T(0) ) x = T(1)/n; }
}

// 転置行列(行と列を入れ替える)
template<typename T, size_t M, size_t N>
mat<T, N, M> transpose(const mat<T, M, N>& m) {
  mat<T,N,M> result;
  for (int r = 0; r < M; ++r) {
    for (int c = 0; c < N; ++c) {
      result[c][r] = m[r][c];
    }
  }
  return result;
}

// 行列とベクトルの積
template<typename T, size_t M, size_t N>
vec<T, M> operator*(const mat<T, M, N>& m, const vec<T, N>& v) {
  vec<T,M> result;
  for (int r = 0; r < M; ++r) {
    // mのr行 と v の内積
    result[r] = std::inner_product(v.begin(), v.end(), m[r].begin(), T(0));
  }
  return result;
}

int main() {
  using namespace std;
  typedef mat<float,8,8> Mat;
  typedef vec<float,8>   Vec;

  //              0 1 2 3 4 5 6 7
  Mat H = { Vec { 0,1,1,0,0,0,0,0 }, // ページ0 から 1, 2 へのリンク
            Vec { 0,0,0,1,0,0,0,0 }, // ページ1 から 3    へのリンク
            Vec { 0,1,0,0,1,0,0,0 }, // ...以下同文
            Vec { 0,1,0,0,1,1,0,0 },
            Vec { 0,0,0,0,0,1,1,1 },
            Vec { 0,0,0,0,0,0,0,1 },
            Vec { 1,0,0,0,1,0,0,1 },
            Vec { 0,0,0,0,0,1,1,0 } };

  for ( auto& v : H ) { stochastic(v); } // 各行を確率ベクトルに変換し
  H = transpose(H);                      // 転置する
  cerr << H << endl << endl;

  // 確率分布I の初期状態から I = H*I を何度か繰り返す
  Vec I = { 1, 0, 0, 0, 0, 0, 0, 0 };
  for ( int i = 0; i < 30; ++i ) {
    cout << I << endl;
    I = H * I;
  }
  cout << I << endl;
}
