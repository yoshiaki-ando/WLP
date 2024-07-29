/*
 * 高次のWLP算出(時刻tごとにp次までのWLP φ_p(t) (=v[p]) を計算)
 * 
 */

#include <cmath>

#include "wlp.h"

namespace AndoLab{

void weighting(const int p, double *v, double *w, double t){
  for(int n = 0; n <= p; n++){
    v[n] *=  std::exp( -w[n] - 0.5*t ); 
  }
}

void wlp(const int p, const double t, double *v){
  /* Weighted Laguerre Polynomial 𝜑ₙ(z) */
  /* v[n] = 𝜑ₙ(t) */

  double *w = new double [p+1];
  for(int i = 0; i <= p; i++){
    w[i] = 0.0;
  }
  
  v[0] = 1.0;

  if ( p > 0 ){
    v[1] = 1.0 - t;

    for(int n = 2; n <= p; n++){
      w[n] = w[n-1];

      /* exp(10)を超える毎に exp(-10)倍する。何倍したか w に記憶しておく */
      if ( std::log(std::abs(v[n-1])) > 10.0 ){
	v[n-1] *= std::exp(-10.0);
	v[n-2] *= std::exp(-10.0);
	w[n] -= 10.0;
	w[n-1] -= 10.0;
	w[n-2] -= 10.0;
      }

      v[n] = (2.0*n - 1.0 - t)/n * v[n-1] - (n - 1.0)/n * v[n-2];
    }
  }

  /* exp(-10 * N)倍を戻すのと重み exp(-t/2) を同時に戻す */
  weighting(p, v, w, t);
  delete [] w;

}

}
