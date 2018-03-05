// CSE 101 Winter 2018, PA 4
//
// Name: Jorge Avila & Timothy Walker
// PID:  A14226029   & A14191564
// Sources of Help: PA4 Review
// Due: March 10th, 2018 at 11:59 PM

#ifndef __ICE_CPP__
#define __ICE_CPP__

#include "Ice.hpp"
#include <climits>

int ice(TwoD_Array<int> rooms) {
  int M = rooms.getNumRows();
  int N = rooms.getNumCols(); 
  TwoD_Array<int> paths(M, N); 

  for(int i = 0; i < M; i++) {
    for(int j = 0; j < N; j++) {
      int temp = rooms.at(i, j);
      if(i == 0 && j == 0) {
        if(temp <= 0) {
          paths.at(0, 0) = 1;
        } else {
          paths.at(0, 0) = rooms.at(0,0) + 1;
        }
      }
      else if(i == M-1 && j == N-1) {
        paths.at(i,j) = MAX(paths.at(i, j-1) + temp, paths.at(i-1,j) + temp);
      }
      else if(i - 1 < 0) {
        paths.at(i,j) = paths.at(i,j-1) + temp;
      } else if(j - 1 < 0) {
        paths.at(i,j) = paths.at(i-1,j) + temp;
      } else {
        paths.at(i,j) = MIN(paths.at(i, j-1) + temp, paths.at(i-1,j) + temp);
      }
    }
  }
  return MAX(paths.at(0,0), paths.at(M-1, N-1));
}
#endif
