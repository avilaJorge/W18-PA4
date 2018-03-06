// CSE 101 Winter 2018, PA 4
//
// Name: Jorge Avila & Timothy Walker
// PID:  A14226029   & A14191564
// Sources of Help: PA4 Review
// Due: March 10th, 2018 at 11:59 PM

#ifndef __TENNIS_CPP__
#define __TENNIS_CPP__

#include "Tennis.hpp"
#include <algorithm>
#include <vector>
#include <iostream>

int tennis(std::vector<Interval> lessons) {

  std::sort(lessons.begin(), lessons.end());
  std::vector<int> courts(1,0);
  bool found = false;
  for(int i = 0; i < lessons.size(); i++) {
    for(int j = 0; j < courts.size(); j++) {
      if(courts[j] <= lessons[i].start) {
        courts[j] = lessons[i].end;
        found = true;
        break;
      }
    }
    if(!found) {
      courts.push_back(lessons[i].end);
    }
    found = false;
  }
  return courts.size();
}
#endif
