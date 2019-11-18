#include "experiment.hpp"
#include <ctime>
#include <algorithm>
#include <random>
#include <iostream>

using std::swap;
using std::clock_t;
using std::vector;
using std::cout;
using std::string;

experiment::experiment(int a) {
  length = a;
  array = new int[a];
}

void experiment::enwarm() {
  for (int i = 0; i < length; i++) 
	  array[i] = rand();
}

vector<int> experiment::prepareForRandom() {
	static std::mt19937 engine(std::random_device{}());
	vector<int> result;
	result.resize(length);
	for(int i=0;i<length;i++)
		result[i]=i;
	std::shuffle(result.begin(), result.end(), engine);
	return result;
}

void experiment::perform(dir d) {
  
  string s= "    Style: ";
  clock_t t1=0, t2=0;
  if(d == straight) s+= "straight";
  else if(d == backwards) s+= "backwards";
  else s+= "random";
  switch (d) {
  case straight: {
	  int temp = 0;
	  t1 = clock();
	  for (int k = 0; k < 1000; k++) {
		  for(int i=0;i<length;i++){
			  temp = array[i];
		  }
	  }
	  t2 = clock();
	  break;
  }
  case backwards: {
	  int temp = 0;
	  t1 = clock();
	  for (int k = 0; k < 1000; k++) {
		  for (int i = length-1; i > -1; i--) {
			  temp = array[i];
		  }
	  }
	  t2 = clock();
	  break;
  }
  case rand0m: {
	  vector<int> indexV = prepareForRandom();
	  int temp = 0;
	  t1 = clock();
	  for (int k = 0; k < 1000; k++) {
		  for (int i = 0; i < length; i++) {
			  temp = array[indexV[i]];
		  }
	  }
	  t2 = clock();
	  break;
  }
  }
  double result = double(t2-t1);
  cout << "  attempts: " << 1000 << "\n";
  cout << s << "\n";
  cout << "    Length: " << length << "\n";
  cout << "    Result (time): " << result << "\n\n";
}