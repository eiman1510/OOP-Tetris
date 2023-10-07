#include<SFML/Graphics.hpp>
#include<fstream>
#include"Play.h"
#include <vector>
#include <algorithm>
#include<time.h>
#include<iostream>

using namespace sf;

int main()
{
	play g;

	while (g.game())
	{
		g.setup();
		g.disp();
	}

	return 0;
}