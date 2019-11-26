
#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <vector>

using std::vector;
using std::size_t;

enum dir {
	straight,
	backwards,
	rand0m
};

class experiment {
  unsigned int *array = nullptr;
  size_t length = 0;
  vector<size_t> prepareForRandom();
  void perform_straight();
  void perform_backwards();
  void perform_rand0m();
 public:
  experiment(size_t);
  void enwarm();
  void perform(dir);
};

#endif  // INCLUDE_HEADER_HPP_
