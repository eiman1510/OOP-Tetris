#include<SFML/Graphics.hpp>
//#include"Play.h"
#include"Tetriminos.h"
#include<iostream>

using namespace sf;

void swap(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

class well
{
	int NoOfLines = 0;
	int score = 0;
public:
	Tet* tet;
	int w[20][10];
	well()
	{
		tet = nullptr;
	}
	void filling()
	{
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				w[i][j] = 0;
			}
		}
	}
	void t()
	{
		int n = rand() % 7 + 1;
		//int n = 1;
		switch (n)
		{
		case 3:
			tet = new  Tet_O;
			break;
		case 2:
			tet = new  Tet_L;
			break;

		case 1:
			tet = new  Tet_I;
			break;
		case 4:
			tet = new  Tet_S;
			break;
		case 5:
			tet = new  Tet_J;
			break;
		case 6:
			tet = new  Tet_Z;
			break;
		case 7:
			tet = new  Tet_T;
			break;
		}
		start();
	}
	void start()
	{
		tet->drawtet(w);
		return;
	}
	bool linefilled(int j)
	{
		for (int i = 0; i < 10; i++)
		{
			if (w[j][i] == 0) {
				return false;
			}
		}
		return true;
	}
	void theswap(int n)
	{
		for (int i = n; i >= 0; i--)
		{
			for (int j = 0; j < 10; j++)
			{
				swap(w[i][j], w[i - 1][j]);
			}
		}
		int m = 20 - n;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				w[i][j] = 0;
			}
		}

	}

	int lineclearing(int& k)
	{
		int l = 0;
		int s = 0;
		for (int i = 19; i >= 0; i--)
		{
			while (linefilled(i) == true)
			{
				l++;
				s++;
				theswap(i);
			}
		}
		k = s * 100;
		std::cout << l << std::endl;
		return l;
	}

	void left()
	{
		tet->moveleft(w);
		return;
	}
	void right()
	{
		tet->moveright(w);
	}
	void move()
	{

		tet->continuousemove(w);
	}
	void rotate()
	{
		tet->rotate(w);
	}
	bool next()
	{
		if (tet->checkspacedown(w) == true)
			return false;
		return true;
	}
	bool chckend()
	{
		if (tet->checkspacedown(w) == false)
			return false;
		return true;
	}
	~well()
	{
		delete[]tet;
	}

};