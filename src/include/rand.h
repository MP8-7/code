#pragma once
#include <cstdlib>
#include <random>
using namespace std;
static inline int randint(int min, int max)
{ 
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<> dist(min, max);
	int a = dist(gen);
	int b = dist(gen);
	int c = dist(gen);
	int d = dist(gen);
	int e = dist(gen);
	int f = dist(gen);
	return (a + b + c + d + e + f) / 6;
}
