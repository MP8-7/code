 #pragma once
#include <iostream>
#include <Windows.h>
#include <algorithm> 
using namespace std;
namespace cs {
	inline string upper(string& input)
	{
		transform(input.begin(), input.end(), input.begin(), toupper);
		return input;
	}
	inline void clear() {
#ifdef _WIN32
		system("cls");
#else
		cout << "\033[2J\033[1;1H";
#endif
	}
	inline void sleep(int ms) {
		Sleep(ms);
	}
}
