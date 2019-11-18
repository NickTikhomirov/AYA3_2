
#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <vector>

using std::vector;

enum dir {
	straight,
	backwards,
	rand0m
};

class experiment {
  int *array = nullptr;
  int length = 0;
  vector<int> prepareForRandom();
 public:
  experiment(int);
  void enwarm();
  void perform(dir);
};

#endif  // INCLUDE_HEADER_HPP_
