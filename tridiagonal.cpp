#include <armadillo>
#include "tridiagonal.hpp"

using namespace arma;

mat create_tridiagonal(int n, const vec &a, const vec &d, const vec &e)
{
  // Start from identity matrix
  mat A = mat(n, n, fill::eye);

  for (int i = 0; i < n - 1; i++)
  {
    A(i, i) = d(i);
    A(i, i + 1) = e(i);
    A(i + 1, i) = a(i);
  }
  A(n - 1, n - 1) = d(n - 1);
  return A;
}


mat create_tridiagonal(int n, double a, double d, double e)
{
  vec a_vec = vec(n - 1, fill::ones) * a;
  vec d_vec = vec(n, fill::ones) * d;
  vec e_vec = vec(n - 1, fill::ones) * e;
  return create_tridiagonal(n, a_vec, d_vec, e_vec);
}
mat A = create_tridiagonal(n, a, d, e)
{

  int n = 6;
  double h = 1 / double(n);
  double h_2 = h * h;

  vec a = vec(n - 1).fill(-1.) * (1 / h_2);
  vec d = vec(n).fill(2.) * (1 / h_2);
  vec e = vec(n - 1).fill(-1.) * (1 / h_2);


  mat A = create_tridiagonal(n, a, d, e);
  A.print("A = ");
  
  return  create_tridiagonal(n, a, d, e);
}