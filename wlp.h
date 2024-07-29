/*
 * 高次のWLP算出(時刻tごとにp次までのWLP φ_p(t) (=v[p]) を計算)
 * 
 */

#ifndef __WLP_H__
#define __WLP_H__

namespace AndoLab{

void wlp
(
 const int order_P,
 const double time_t,
 double *WLP_to_Pth_order
 );

}

#endif
