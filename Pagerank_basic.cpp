#include <array>
#include <algorithm>
#include <numeric>
#include <iostream>

// vec<T,N> : T�^��N�s�x�N�g��
template<typename T,size_t N>
using vec = std::array<T,N>;

// mat<T,M,N> : T�^��M�sN��s��
template<typename T, size_t M, size_t N>
using mat = std::array<vec<T,N>,M>;

// �x�N�g����stream�ւ̏o��
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

// �s���stream�ւ̏o��
template<typename T, size_t M, size_t N>
std::ostream& operator<<(std::ostream& stream, const mat<T, M, N>& m) {
  for ( int r = 0; r < M; ++r ) {
    stream << m[r];
    if ( r != M-1 ) stream << std::endl;
  }
  return stream;
}

// �m���x�N�g�������: v(N�s�x�N�g��)�̔�0�v�f�� 1/(��0�v�f��) �ɂ���
// (�v�f�̑��a��1�ƂȂ�)
template<typename T, size_t N>
void stochastic(vec<T, N>& v) {
  // ��0�v�f����n�ɋ���
  int n = std::count_if(v.begin(), v.end(), [](T x) { return x != T(0);});
  // ��0�v�f�� 1/n �ɂ���
  for ( T& x : v ) { if ( x != T(0) ) x = T(1)/n; }
}

// �]�u�s��(�s�Ɨ�����ւ���)
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

// �s��ƃx�N�g���̐�
template<typename T, size_t M, size_t N>
vec<T, M> operator*(const mat<T, M, N>& m, const vec<T, N>& v) {
  vec<T,M> result;
  for (int r = 0; r < M; ++r) {
    // m��r�s �� v �̓���
    result[r] = std::inner_product(v.begin(), v.end(), m[r].begin(), T(0));
  }
  return result;
}

int main() {
  using namespace std;
  typedef mat<float,8,8> Mat;
  typedef vec<float,8>   Vec;

  //              0 1 2 3 4 5 6 7
  Mat H = { Vec { 0,1,1,0,0,0,0,0 }, // �y�[�W0 ���� 1, 2 �ւ̃����N
            Vec { 0,0,0,1,0,0,0,0 }, // �y�[�W1 ���� 3    �ւ̃����N
            Vec { 0,1,0,0,1,0,0,0 }, // ...�ȉ�����
            Vec { 0,1,0,0,1,1,0,0 },
            Vec { 0,0,0,0,0,1,1,1 },
            Vec { 0,0,0,0,0,0,0,1 },
            Vec { 1,0,0,0,1,0,0,1 },
            Vec { 0,0,0,0,0,1,1,0 } };

  for ( auto& v : H ) { stochastic(v); } // �e�s���m���x�N�g���ɕϊ���
  H = transpose(H);                      // �]�u����
  cerr << H << endl << endl;

  // �m�����zI �̏�����Ԃ��� I = H*I �����x���J��Ԃ�
  Vec I = { 1, 0, 0, 0, 0, 0, 0, 0 };
  for ( int i = 0; i < 30; ++i ) {
    cout << I << endl;
    I = H * I;
  }
  cout << I << endl;
}
