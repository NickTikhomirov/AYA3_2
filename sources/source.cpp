#include "experiment.hpp"
#include <iostream>

using std::cout;

int main() {
  int amounts[7];
  amounts[0] = 1024 * 32;
  for (int i = 1; i < 6; i++) {
    amounts[i] = amounts[i - 1] * 2;
  }
  amounts[6] = amounts[4] * 3;
  for (int i : amounts) {
    experiment ex(i);
    ex.enwarm();
    for (dir d : {straight, backwards, rand0m})
		ex.perform(d);
    cout << "\n";
  }
}