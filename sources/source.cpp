#include "experiment.hpp"
#include <iostream>
#include <unordered_map>

using std::cout;
using std::unordered_map;
using std::string;

void interpret(int i) {
	cout << "Size: ";
	static unordered_map<int, string> interprets{
		{0,"1/8"},
		{1,"1/4"},
		{2,"1/2"},
		{3,"1"},
		{4,"2"},
		{5,"4"},
		{6,"6"}
	};
	cout << (*interprets.find(i)).second;
	cout << " mb.\n";
}
	
int main() {
  int amounts[7];
  amounts[0] = 1024 * 32;
  for (int i = 1; i < 6; i++) {
    amounts[i] = amounts[i - 1] * 2;
  }
  amounts[6] = amounts[4] * 3;
  for (dir d : {straight, backwards, rand0m}) {
	  string s = "travel_variant: ";
	  if (d == straight) s += "straight";
	  else if (d == backwards) s += "backwards";
	  else s += "random";
	  cout << s << "\n";
	  for (int i = 0; i < 7; i++) {
		  interpret(i);
		  experiment ex(amounts[i]);
		  ex.enwarm();
		  ex.perform(d);
	  }
	  cout << "\n";
  }
}