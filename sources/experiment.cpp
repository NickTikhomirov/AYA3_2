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
using std::size_t;

experiment::experiment(size_t a) {
  length = a;
  array = new unsigned int[a];
}

void experiment::enwarm() {
  for (size_t i = 0; i < length; ++i) 
	  array[i] = rand();
}

vector<size_t> experiment::prepareForRandom() {
	static std::mt19937 engine(std::random_device{}());
	vector<size_t> result;
	result.resize(length);
	for(size_t i=0;i<length;++i)
		result[i]=i;
	std::shuffle(result.begin(), result.end(), engine);
	return result;
}


void experiment::perform_straight() {
	unsigned int temp = 0;
	for (size_t k = 0; k < 1000; ++k) {
		for (size_t i = 0; i < length; ++i) {
			temp = array[i];
		}
	}
}


void experiment::perform_backwards() {
	unsigned int temp = 0;
	for (size_t k = 0; k < 1000; ++k) {
		for (size_t i = length - 1; i > -1; --i) {
			temp = array[i];
		}
	}
}

void experiment::perform_rand0m() {
	vector<size_t> indexV = prepareForRandom();
	unsigned int temp = 0;
	for (size_t k = 0; k < 1000; ++k) {
		for (size_t i = 0; i < length; ++i) {
			temp = array[indexV[i]];
		}
	}
}

void experiment::perform(dir d) {
  clock_t t1 = 0, t2 = 0;
  t1 = clock();
  if (d == straight)
	  perform_straight();
  else if (d == backwards)
	  perform_backwards();
  else
	  perform_rand0m();
  t2 = clock();
  cout << "  Experiments: " << 1000 << "\n";
  cout << "  Length: " << length << "\n";
  cout << "  Duration: " << double(t2 - t1) << "\n";
}