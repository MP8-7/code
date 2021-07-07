#include <iostream>
#include <Windows.h>
#include <fstream>
#include <vector>
#include <rand.h>
#include <Armor.h>
#include <Enchants.h>
#include <Entity.h>
#include <Magic.h>
#include <console.h>

using namespace std;
using namespace game;
using namespace cs;
int main() {

	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	//MoveWindow(window_handle, x, y, width, height, redraw_window);
	MoveWindow(console, r.left, r.top, 1000, 600, TRUE);

	cout << "Welcome." << endl;

	game::createPlayer();

}

