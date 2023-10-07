#include<SFML/Graphics.hpp>
#include<iostream>

using namespace sf;

class Tet
{
public:
	int st_x;
	int st_y;
	int h;
	int w;
	int rotationstate;                       // 0=0 ,, 1=90 ,,2=180 ,,3=270 ,,4=360=0

	Tet() {
		h = 0;
		w = 0;
		st_x = 0;
		st_y = 0;
		rotationstate = 0;
	}
	Tet(int a, int b, int c)
	{
		st_x = a;
		st_y = b;
		rotationstate = c;

	}
	virtual void drawtet(int grid[][10])
	{

	}
	virtual void movetet(int grid[][10])
	{

	}
	virtual void emptytet(int grid[][10])
	{

	}
	virtual void continuousemove(int grid[][10])
	{

	}
	virtual void updaterotation(int& a)
	{
		if (a == 4)
			a = 0;
		rotationstate = a;
	}
	virtual void moveleft(int grid[][10]) = 0;
	virtual void moveright(int grid[][10]) = 0;
	virtual void rotate(int grid[][10]) {

	}
	virtual bool checkspacedown(int grid[][10])
	{
		return 0;
	}
	~Tet() { };

};
class Tet_I :public Tet
{
public:
	Tet_I() :Tet(4, 0, 0)
	{
		if (rotationstate == 0 || rotationstate == 2)
		{
			h = 4;
			w = 1;
		}
		if (rotationstate == 1 || rotationstate == 3)
		{
			h = 1;
			w = 0;
		}
	}
	void drawtet(int grid[][10])
	{
		updaterotation(rotationstate);
		if (rotationstate == 0) {
			for (int i = 0; i < 4; i++)
				grid[st_y + i][st_x] = 1;
		}
		else if (rotationstate == 1)
		{
			for (int i = 0; i < 4; i++)
				grid[st_y][st_x + i] = 1;
		}
		else if (rotationstate == 2)
		{
			for (int i = 0; i < 4; i++)
				grid[st_y + i][st_x] = 1;
		}
		else if (rotationstate == 3)
		{
			for (int i = 0; i < 4; i++)
				grid[st_y][st_x + i] = 1;
		}

	}
	void emptytet(int grid[][10])
	{
		updaterotation(rotationstate);
		if (rotationstate == 0) {
			for (int i = 0; i < 4; i++)
				grid[st_y + i][st_x] = 0;
		}
		else if (rotationstate == 1)
		{
			for (int i = 0; i < 4; i++)
				grid[st_y][st_x + i] = 0;
		}
		else if (rotationstate == 2)
		{
			for (int i = 0; i < 4; i++)
				grid[st_y + i][st_x] = 0;
		}
		else if (rotationstate == 3)
		{
			for (int i = 0; i < 4; i++)
				grid[st_y][st_x + i] = 0;
		}
	}
	bool checkspaceright(int grid[][10])
	{
		bool space = true;
		if (rotationstate == 0 || rotationstate == 2)
		{
			if (st_x + 1 >= 10)
			{
				space = false;
				return space;
			}
		}
		if (rotationstate == 1 || rotationstate == 3)
		{
			if (st_x + 4 >= 10)
			{
				space = false;
				return space;
			}
		}
		if (rotationstate == 0 || rotationstate == 2) {
			for (int i = 0; i < 4; i++)
			{
				if (grid[st_y + i][st_x + 1] != 0)
				{
					space = false;
					return space;
				}
			}
		}
		if (rotationstate == 1 || rotationstate == 3) {
			if (grid[st_y][st_x + 4] != 0)
			{
				space = false;
				return space;
			}

		}
		return space;
	}
	bool checkspaceleft(int grid[][10])
	{
		bool space = true;

		if (rotationstate == 0 || rotationstate == 2)
		{
			if (st_x <= 0)
			{
				space = false;
				return space;
			}
		}
		if (rotationstate == 1 || rotationstate == 3)
		{
			if (st_x <= 0)
			{
				space = false;
				return space;
			}
		}
		if (rotationstate == 0 || rotationstate == 2) {
			for (int i = 0; i < 4; i++)
			{
				if (grid[st_y + i][st_x - 1] != 0)
				{
					space = false;
					return space;
				}
			}
		}
		if (rotationstate == 1 || rotationstate == 3) {
			if (grid[st_y][st_x - 1] != 0)
			{
				space = false;
				return space;
			}

		}
		return space;
	}
	bool checkspacedown(int grid[][10])
	{
		bool space = true;
		if (rotationstate == 0 || rotationstate == 2)
		{
			if (st_y + 4 > 20)
			{
				space = false;
				return space;
			}
		}
		if (rotationstate == 1 || rotationstate == 3)
		{
			if (st_y + 1 > 20)
			{
				space = false;
				return space;
			}
		}
		if (rotationstate == 0 || rotationstate == 2)
		{
			if (grid[st_y + h][st_x] != 0)
			{
				space = false;
				return space;
			}
		}
		if (rotationstate == 1 || rotationstate == 3)
		{
			if (grid[st_y + 1][st_x] != 0 || grid[st_y + 1][st_x + 1] != 0 || grid[st_y + 1][st_x + 2] != 0 || grid[st_y + 1][st_x + 3] != 0)
			{

				space = false;
				return space;
			}
		}
		return space;
	}

	bool rotationvalidity(int grid[][10])
	{
		bool valid = false;
		if (rotationstate == 0 || rotationstate == 2)
		{
			if (st_x + 4 <= 10 && st_x >= 0)
			{
				if (grid[st_y][st_x + 1] == 0 && grid[st_y][st_x + 2] == 0 && grid[st_y][st_x + 3] == 0) {
					valid = true;
					return valid;
				}
				else if (grid[st_y][st_x + 1] != 0)
				{
					if (st_x - 3 < 0 || grid[st_y][st_x - 1] != 0 || grid[st_y][st_x - 2] != 0 || grid[st_y][st_x - 3] != 0)
					{
						valid = false;
						return valid;
					}
					emptytet(grid);
					st_x = st_x - 3;
					valid = true;
					return valid;
				}
				else if (grid[st_y][st_x + 2] != 0)
				{
					if (st_x - 2 < 0 || grid[st_y][st_x - 1] != 0 || grid[st_y][st_x - 2] != 0)
					{
						valid = false;
						return valid;
					}
					emptytet(grid);
					st_x = st_x - 2;
					valid = true;
					return valid;
				}
				else if (grid[st_y][st_x + 3] != 0)
				{
					if (st_x - 1 < 0 || grid[st_y][st_x - 1] != 0)
					{
						valid = false;
						return valid;
					}

					emptytet(grid);
					st_x = st_x - 1;
					valid = true;
					return valid;
				}
			}
			if (st_x + 4 > 10)
			{
				int m = (st_x + 4) - 10;
				for (int i = 0; i < m; i++)
				{
					if (grid[st_y][st_x - m - i] != 0)
					{
						valid = false;
						return valid;
					}
				}
				emptytet(grid);
				st_x = st_x - m;
				if (grid[st_y][st_x + 1] == 0 && grid[st_y][st_x + 2] == 0 && grid[st_y][st_x + 3] == 0) {
					valid = true;
					return valid;
				}
				else if (grid[st_y][st_x + 1] != 0)
				{
					if (st_x - 3 < 0 || grid[st_y][st_x - 1] != 0 || grid[st_y][st_x - 2] != 0 || grid[st_y][st_x - 3] != 0)
					{
						valid = false;
						return valid;
					}
					emptytet(grid);
					st_x = st_x - 3;
					valid = true;
					return valid;
				}
				else if (grid[st_y][st_x + 2] != 0)
				{
					if (st_x - 2 < 0 || grid[st_y][st_x - 1] != 0 || grid[st_y][st_x - 2] != 0)
					{
						valid = false;
						return valid;
					}
					emptytet(grid);
					st_x = st_x - 2;
					valid = true;
					return valid;
				}
				else if (grid[st_y][st_x + 3] != 0)
				{
					if (st_x - 1 < 0 || grid[st_y][st_x - 1] != 0)
					{
						valid = false;
						return valid;
					}

					emptytet(grid);
					st_x = st_x - 1;
					valid = true;
					return valid;
				}


			}
		}
		if (rotationstate == 1 || rotationstate == 3)
		{
			if (st_y + 4 <= 20)
			{
				if (grid[st_y + 1][st_x] == 0 && grid[st_y + 2][st_x] == 0 && grid[st_y + 3][st_x] == 0) {
					valid = true;
					return valid;
				}
				else if (grid[st_y + 1][st_x] != 0)
				{
					if (st_y - 3 < 0 || grid[st_y - 1][st_x] != 0 || grid[st_y - 2][st_x] != 0 || grid[st_y - 3][st_x] != 0)
					{
						valid = false;
						return valid;
					}
					st_y = st_y - 3;
					emptytet(grid);
					valid = true;
					return valid;
				}
				else if (grid[st_y + 2][st_x] != 0)
				{
					if (st_y - 2 < 0 || grid[st_y - 1][st_x] != 0 || grid[st_y - 2][st_x] != 0)
					{
						valid = false;
						return valid;
					}
					st_y = st_y - 2;
					emptytet(grid);
					valid = true;
					return valid;
				}
				else if (grid[st_y + 3][st_x] != 0)
				{
					if (st_y - 1 < 0 || grid[st_y - 1][st_x] != 0)
					{
						valid = false;
						return valid;
					}
					st_y = st_y - 1;
					emptytet(grid);
					valid = true;
					return valid;
				}
			}
			if (st_y + 4 > 20)
			{
				int m = (st_y + 4) - 20;
				emptytet(grid);
				st_y = st_y - m;
				if (grid[st_y + 1][st_x] == 0 && grid[st_y + 2][st_x] == 0 && grid[st_y + 3][st_x] == 0) {
					valid = true;
					return valid;
				}
				else if (grid[st_y + 1][st_x] != 0)
				{
					if (st_y - 3 < 0 || grid[st_y - 1][st_x] != 0 || grid[st_y - 2][st_x] != 0 || grid[st_y - 3][st_x] != 0)
					{
						valid = false;
						return valid;
					}
					st_y = st_y - 3;
					emptytet(grid);
					valid = true;
					return valid;
				}
				else if (grid[st_y + 2][st_x] != 0)
				{
					if (st_y - 2 < 0 || grid[st_y - 1][st_x] != 0 || grid[st_y - 2][st_x] != 0)
					{
						valid = false;
						return valid;
					}
					st_y = st_y - 2;
					emptytet(grid);
					valid = true;
					return valid;
				}
				else if (grid[st_y + 3][st_x] != 0)
				{
					if (st_y - 1 < 0 || grid[st_y - 1][st_x] != 0)
					{
						valid = false;
						return valid;
					}
					st_y = st_y - 1;
					emptytet(grid);
					valid = true;
					return valid;
				}
			}
		}
		return valid;
	}
	void moveleft(int grid[][10])
	{
		if (checkspaceleft(grid))
		{
			emptytet(grid);
			st_x--;
			drawtet(grid);
			return;
		}
	}
	void moveright(int grid[][10])
	{
		if (checkspaceright(grid))
		{
			emptytet(grid);
			st_x++;
			drawtet(grid);
			return;
		}
	}
	void rotate(int grid[][10])
	{
		if (rotationvalidity(grid)) {
			emptytet(grid);
			rotationstate = rotationstate + 1;
			if (rotationstate > 3) {
				updaterotation(rotationstate);
			}
			drawtet(grid);
		}
	}
	void continuousemove(int grid[][10])
	{
		if (checkspacedown(grid)) {
			emptytet(grid);
			st_y++;
			drawtet(grid);
		}

	}
	~Tet_I() { };
};

//___________________________________*************************__________________________________

class Tet_L :public Tet
{
public:
	Tet_L() :Tet(4, 0, 0)
	{
		if (rotationstate == 0 || rotationstate == 2)
		{
			h = 3;
			w = 2;
		}
		if (rotationstate == 1 || rotationstate == 3)
		{
			h = 2;
			w = 3;
		}
	}
	void drawtet(int grid[][10])
	{
		updaterotation(rotationstate);
		if (rotationstate == 0)
		{
			grid[st_y][st_x] = 2;
			grid[st_y + 1][st_x] = 2;
			grid[st_y + 2][st_x] = 2;
			grid[st_y + 2][st_x + 1] = 2;
		}
		if (rotationstate == 1)
		{
			grid[st_y][st_x] = 2;
			grid[st_y + 1][st_x] = 2;
			grid[st_y][st_x + 1] = 2;
			grid[st_y][st_x + 2] = 2;
		}
		if (rotationstate == 2)
		{
			grid[st_y][st_x] = 2;
			grid[st_y][st_x + 1] = 2;
			grid[st_y + 1][st_x + 1] = 2;
			grid[st_y + 2][st_x + 1] = 2;
		}
		if (rotationstate == 3)
		{
			grid[st_y][st_x + 2] = 2;
			grid[st_y + 1][st_x] = 2;
			grid[st_y + 1][st_x + 1] = 2;
			grid[st_y + 1][st_x + 2] = 2;
		}
	}
	void emptytet(int grid[][10])
	{
		updaterotation(rotationstate);
		if (rotationstate == 0)
		{
			grid[st_y][st_x] = 0;
			grid[st_y + 1][st_x] = 0;
			grid[st_y + 2][st_x] = 0;
			grid[st_y + 2][st_x + 1] = 0;
		}
		if (rotationstate == 1)
		{
			grid[st_y][st_x] = 0;
			grid[st_y + 1][st_x] = 0;
			grid[st_y][st_x + 1] = 0;
			grid[st_y][st_x + 2] = 0;
		}
		if (rotationstate == 2)
		{
			grid[st_y][st_x] = 0;
			grid[st_y][st_x + 1] = 0;
			grid[st_y + 1][st_x + 1] = 0;
			grid[st_y + 2][st_x + 1] = 0;
		}
		if (rotationstate == 3)
		{
			grid[st_y][st_x + 2] = 0;
			grid[st_y + 1][st_x] = 0;
			grid[st_y + 1][st_x + 1] = 0;
			grid[st_y + 1][st_x + 2] = 0;
		}
	}
	bool checkspaceright(int grid[][10])
	{
		bool space = true;

		if (rotationstate == 0)
		{
			if (st_x + 2 >= 10)
			{
				space = false;
				return space;
			}
			if (grid[st_y][st_x + 1] != 0 || grid[st_y + 1][st_x + 1] != 0 || grid[st_y + 2][st_x + 2] != 0)
			{
				space = false;
				return space;
			}
		}
		if (rotationstate == 1)
		{
			if (st_x + 3 >= 10)
			{
				space = false;
				return space;
			}
			if (grid[st_y + 1][st_x + 1] != 0 || grid[st_y][st_x + 3] != 0)
			{
				space = false;
				return space;
			}
		}
		if (rotationstate == 2)
		{
			if (st_x + 2 >= 10)
			{
				space = false;
				return space;
			}
			if (grid[st_y][st_x + 2] != 0 || grid[st_y + 1][st_x + 2] != 0 || grid[st_y + 2][st_x + 2] != 0)
			{
				space = false;
				return space;
			}
		}
		if (rotationstate == 3)
		{
			if (st_x + 3 >= 10)
			{
				space = false;
				return space;
			}
			if (grid[st_y][st_x + 3] != 0 || grid[st_y + 1][st_x + 3] != 0)
			{
				space = false;
				return space;
			}
		}
		return space;
	}
	bool checkspaceleft(int grid[][10])
	{
		bool space = true;
		if (st_x <= 0)
		{
			space = false;
			return space;
		}
		if (rotationstate == 0)
		{
			for (int i = 0; i < 3; i++)
			{
				if (grid[st_y + i][st_x - 1] != 0)
				{
					space = false;
					return space;
				}
			}
		}
		if (rotationstate == 1)
		{
			for (int i = 0; i < 2; i++)
			{
				if (grid[st_y + i][st_x - 1] != 0)
				{
					space = false;
					return space;
				}
			}
		}
		if (rotationstate == 2)
		{
			if (grid[st_y][st_x - 1] != 0 || grid[st_y + 1][st_x] != 0 || grid[st_y + 2][st_x] != 0)
			{
				space = false;
				return space;
			}
		}
		if (rotationstate == 3)
		{
			if (grid[st_y][st_x + 1] != 0 || grid[st_y + 1][st_x - 1] != 0)
			{
				space = false;
				return space;
			}
		}
		return space;
	}
	bool checkspacedown(int grid[][10])
	{
		bool space = true;

		if (rotationstate == 0)
		{
			if (st_y + 3 > 20)
			{
				space = false;
				return space;
			}
			if (grid[st_y + 3][st_x] != 0 || grid[st_y + 3][st_x + 1] != 0)
			{
				space = false;
				return space;
			}
		}
		if (rotationstate == 1)
		{
			if (st_y + 2 > 20)
			{
				space = false;
				return space;
			}
			if (grid[st_y + 2][st_x] != 0 || grid[st_y + 1][st_x + 1] != 0 || grid[st_y + 1][st_x + 2] != 0)
			{
				space = false;
				return space;
			}
		}
		if (rotationstate == 2)
		{
			if (st_y + 3 > 20)
			{
				space = false;
				return space;
			}
			if (grid[st_y + 1][st_x] != 0 || grid[st_y + 3][st_x + 1] != 0)
			{
				space = false;
				return space;
			}
		}
		if (rotationstate == 3)
		{
			if (st_y + 2 > 20)
			{
				space = false;
				return space;
			}
			if (grid[st_y + 2][st_x] != 0 || grid[st_y + 2][st_x + 1] != 0 || grid[st_y + 2][st_x] != 0)
			{
				space = false;
				return space;
			}
		}
		return space;
	}
	bool rotationvalidity(int grid[][10])
	{
		bool valid = false;
		if (rotationstate == 0)
		{
			if (st_x + 2 <= 9)
			{
				if (grid[st_y][st_x + 1] == 0 && grid[st_y][st_x + 2] == 0)
				{
					valid = true;
					return valid;
				}
				else if (grid[st_y][st_x + 1] != 0)
				{
					if (st_x - 2 < 0 || grid[st_y][st_x - 2] != 0 || grid[st_y][st_x - 1] != 0 || grid[st_y + 1][st_x - 2] != 0)
					{
						valid = false;
						return valid;
					}
					emptytet(grid);
					st_x = st_x - 2;
					valid = true;
					return valid;
				}
				else if (grid[st_y][st_x + 2] != 0)
				{
					if (st_x - 2 < 0 || grid[st_y][st_x - 1] != 0 || grid[st_y + 1][st_x - 1] != 0)
					{
						valid = false;
						return valid;
					}
					emptytet(grid);
					st_x = st_x - 1;
					valid = true;
					return valid;
				}
			}
			if (st_x + 2 > 9)
			{
				int m = (st_x + 2) - 9;
				for (int i = 0; i < m; i++)
				{
					if (grid[st_y][st_x - m - i] != 0)
					{
						valid = false;
						return valid;
					}
				}
				if (grid[st_y + 1][(st_x)-m] != 0)
				{
					valid = false;
					return valid;
				}
				emptytet(grid);
				st_x = st_x - m;
				if (grid[st_y][st_x + 1] == 0 && grid[st_y][st_x + 2] == 0)
				{
					valid = true;
					return valid;
				}
				else if (grid[st_y][st_x + 1] != 0)
				{
					if (st_x - 2 < 0 || grid[st_y][st_x - 2] != 0 || grid[st_y][st_x - 1] != 0 || grid[st_y + 1][st_x - 2] != 0)
					{
						valid = false;
						return valid;
					}
					emptytet(grid);
					st_x = st_x - 2;
					valid = true;
					return valid;
				}
				else if (grid[st_y][st_x + 2] != 0)
				{
					if (st_x - 2 < 0 || grid[st_y][st_x - 1] != 0 || grid[st_y + 1][st_x - 1] != 0)
					{
						valid = false;
						return valid;
					}
					emptytet(grid);
					st_x = st_x - 1;
					valid = true;
					return valid;
				}
			}
		}
		if (rotationstate == 1)
		{
			bool valid = false;
			if (st_y + 3 <= 20)
			{
				if (grid[st_y + 1][st_x + 1] == 0 && grid[st_y + 2][st_x + 1] == 0)
				{
					valid = true;
					return valid;
				}
				else if (grid[st_y + 1][st_x + 1] != 0)
				{
					if (st_y - 2 < 0 || grid[st_y - 2][st_x] != 0 || grid[st_y - 2][st_x + 1] != 0 || grid[st_y - 1][st_x + 1] != 0)
					{
						valid = false;
						return valid;
					}
					emptytet(grid);
					st_y = st_y - 2;
					valid = true;
					return valid;
				}
				else if (grid[st_y + 1][st_x + 2] != 0)
				{
					if (st_y - 1 < 0 || grid[st_y - 1][st_x] != 0 || grid[st_y - 1][st_x + 1] != 0)
					{
						valid = false;
						return valid;
					}
					emptytet(grid);
					st_y = st_y - 1;
					valid = true;
					return valid;
				}

			}
			if (st_y + 3 > 20)
			{
				int m = (st_y + 3 - 20);
				if (grid[st_y - m][st_x] != 0)
				{
					valid = false;
					return valid;
				}
				for (int i = 0; i < m; i++)
				{
					if (grid[st_y - m - i][st_x + 1] != 0)
					{
						valid = false;
						return valid;
					}
				}
				emptytet(grid);
				st_y = st_y - m;
				if (grid[st_y + 1][st_x + 1] == 0 && grid[st_y + 2][st_x + 1] == 0)
				{
					valid = true;
					return valid;
				}
				else if (grid[st_y + 1][st_x + 1] != 0)
				{
					if (st_y - 2 < 0 || grid[st_y - 2][st_x] != 0 || grid[st_y - 2][st_x + 1] != 0 || grid[st_y - 1][st_x + 1] != 0)
					{
						valid = false;
						return valid;
					}
					emptytet(grid);
					st_y = st_y - 2;
					valid = true;
					return valid;
				}
				else if (grid[st_y + 1][st_x + 2] != 0)
				{
					if (st_y - 1 < 0 || grid[st_y - 1][st_x] != 0 || grid[st_y - 1][st_x + 1] != 0)
					{
						valid = false;
						return valid;
					}
					emptytet(grid);
					st_y = st_y - 1;
					valid = true;
					return valid;
				}

			}

		}
		if (rotationstate == 2)
		{
			if (st_x + 2 <= 9)
			{
				if (grid[st_y + 1][st_x] == 0 && grid[st_y][st_x + 2] == 0 && grid[st_y + 1][st_x + 2] == 0)
				{
					valid = true;
					return valid;
				}
				if (grid[st_y + 1][st_x] != 0 || grid[st_y + 1][st_x + 2] != 0)
				{
					if (st_y - 1 < 0 || grid[st_y][st_x + 2] != 0 || grid[st_y - 1][st_x + 2] != 0)
					{
						valid = false;
						return valid;
					}
					emptytet(grid);
					st_y = st_y - 1;
					valid = true;
					return valid;
				}
				if (grid[st_y][st_x + 2] != 0)
				{
					if (st_x - 1 < 0 || grid[st_y + 1][st_x] != 0 || grid[st_y + 1][st_x - 1] != 0)
					{
						valid = false;
						return valid;
					}
					emptytet(grid);
					st_x = st_x - 1;
					valid = true;
					return valid;
				}
			}
			if (st_x + 2 > 9)
			{
				if (grid[st_y][st_x - 1] != 0 || grid[st_y + 1][st_x] != 0)
				{
					valid = false;
					return valid;
				}
				emptytet(grid);
				st_x = st_x - 1;
				if (grid[st_y + 1][st_x] == 0 && grid[st_y][st_x + 2] == 0 && grid[st_y + 1][st_x + 2] == 0)
				{
					valid = true;
					return valid;
				}
				if (grid[st_y + 1][st_x] != 0 || grid[st_y + 1][st_x + 2] != 0)
				{
					if (st_y - 1 < 0 || grid[st_y][st_x + 2] != 0 || grid[st_y - 1][st_x + 2] != 0)
					{
						valid = false;
						return valid;
					}
					emptytet(grid);
					st_y = st_y - 1;
					valid = true;
					return valid;
				}
				if (grid[st_y][st_x + 2] != 0)
				{
					if (st_x - 1 < 0 || grid[st_y + 1][st_x] != 0 || grid[st_y + 1][st_x - 1] != 0)
					{
						valid = false;
						return valid;
					}
					emptytet(grid);
					st_x = st_x - 1;
					valid = true;
					return valid;
				}
			}
		}
		if (rotationstate == 3)
		{
			if (st_y - 2 >= 0)
			{
				if (grid[st_y][st_x] == 0 && grid[st_y - 1][st_x] == 0)
				{
					emptytet(grid);
					st_y = st_y - 1;
					valid = true;
					return valid;
				}
				if (grid[st_y][st_x] != 0 || grid[st_y - 1][st_x] != 0)
				{
					if (grid[st_y][st_x + 1] != 0 || grid[st_y - 1][st_x + 1] != 0)
					{
						valid = false;
						return false;
					}
					emptytet(grid);
					st_x = st_x + 1;
					st_y = st_y - 1;
					valid = true;
					return valid;
				}
			}
			if (st_y - 2 < 0)
			{
				valid = false;
				return valid;
			}
		}
		return valid;
	}
	void moveleft(int grid[][10])
	{
		if (checkspaceleft(grid))
		{
			emptytet(grid);
			st_x--;
			drawtet(grid);
			return;
		}
	}
	void moveright(int grid[][10])
	{
		if (checkspaceright(grid))
		{
			emptytet(grid);
			st_x++;
			drawtet(grid);
			return;
		}
	}
	void rotate(int grid[][10])
	{
		if (rotationvalidity(grid)) {
			emptytet(grid);
			rotationstate = rotationstate + 1;
			if (rotationstate > 3) {
				updaterotation(rotationstate);
			}
			drawtet(grid);
		}
	}
	void continuousemove(int grid[][10])
	{
		if (checkspacedown(grid)) {
			emptytet(grid);
			st_y++;
			drawtet(grid);
		}

	}
	~Tet_L() { };

};

//_________________________************************************_________________________________-

class Tet_S :public Tet
{
public:
	Tet_S() :Tet(4, 0, 0)
	{
		if (rotationstate == 0 || rotationstate == 2)
		{
			h = 2;
			w = 3;
		}
		if (rotationstate == 1 || rotationstate == 3)
		{
			h = 3;
			w = 2;
		}
	}
	void drawtet(int grid[][10])
	{
		updaterotation(rotationstate);
		if (rotationstate == 0 || rotationstate == 2)
		{
			grid[st_y][st_x] = 3;
			grid[st_y][st_x + 1] = 3;
			grid[st_y + 1][st_x] = 3;
			grid[st_y + 1][st_x - 1] = 3;
		}
		if (rotationstate == 1 || rotationstate == 3)
		{
			grid[st_y][st_x] = 3;
			grid[st_y + 1][st_x] = 3;
			grid[st_y + 1][st_x + 1] = 3;
			grid[st_y + 2][st_x + 1] = 3;
		}
	}
	void emptytet(int grid[][10])
	{
		updaterotation(rotationstate);
		if (rotationstate == 0 || rotationstate == 2)
		{
			grid[st_y][st_x] = 0;
			grid[st_y][st_x + 1] = 0;
			grid[st_y + 1][st_x] = 0;
			grid[st_y + 1][st_x - 1] = 0;
		}
		if (rotationstate == 1 || rotationstate == 3)
		{
			grid[st_y][st_x] = 0;
			grid[st_y + 1][st_x] = 0;
			grid[st_y + 1][st_x + 1] = 0;
			grid[st_y + 2][st_x + 1] = 0;
		}
	}
	bool checkspaceright(int grid[][10])
	{
		updaterotation(rotationstate);
		bool space = true;
		if (rotationstate == 0 || rotationstate == 2 || rotationstate == 1 || rotationstate == 3)
		{
			if (st_x + 2 > 9)
			{
				space = false;
				return space;
			}
		}

		if (rotationstate == 0 || rotationstate == 2)
		{
			if (grid[st_y][st_x + 2] != 0 || grid[st_y + 1][st_x + 1] != 0)
			{
				space = false;
				return space;
			}
		}
		if (rotationstate == 1 || rotationstate == 3)
		{
			if (grid[st_y][st_x + 1] != 0 || grid[st_y + 1][st_x + 2] != 0 || grid[st_y + 2][st_x + 2])
			{
				space = false;
				return space;
			}
		}
		return space;
	}
	bool checkspaceleft(int grid[][10])
	{
		bool space = true;
		updaterotation(rotationstate);
		if (rotationstate == 0 || rotationstate == 2)
		{
			if (st_x - 2 < 0)
			{
				space = false;
				return space;
			}
		}
		if (rotationstate == 1 || rotationstate == 3)
		{
			if (st_x - 1 < 0)
			{
				space = false;
				return space;
			}
		}
		if (rotationstate == 0 || rotationstate == 2)
		{
			if (grid[st_y][st_x - 1] != 0 || grid[st_y + 1][st_x - 2] != 0)
			{
				space = false;
				return space;
			}
		}
		if (rotationstate == 1 || rotationstate == 3)
		{
			if (grid[st_y][st_x - 1] != 0 || grid[st_y + 1][st_x - 1] != 0 || grid[st_y + 2][st_x])
			{
				space = false;
				return space;
			}
		}
		return space;
	}
	bool checkspacedown(int grid[][10])
	{
		bool space = true;
		if (rotationstate == 0 || rotationstate == 2)
		{
			if (st_y + 2 > 19)
			{
				space = false;
				return space;
			}
			if (grid[st_y + 1][st_x + 1] != 0 || grid[st_y + 2][st_x] != 0 || grid[st_y + 2][st_x - 1] != 0)
			{
				space = false;
				return space;
			}
		}
		if (rotationstate == 1 || rotationstate == 3)
		{
			if (st_y + 3 > 19)
			{
				space = false;
				return space;
			}
			if (grid[st_y + 2][st_x] != 0 || grid[st_y + 3][st_x + 1] != 0)
			{
				space = false;
				return space;
			}
		}
		return space;
	}
	bool rotationvalidity(int grid[][10])
	{
		bool valid = false;
		if (rotationstate == 0 || rotationstate == 2)
		{
			if (st_y + 1 <= 19)
			{
				if (grid[st_y + 1][st_x + 1] == 0 && grid[st_y + 2][st_x + 1] == 0)
				{
					valid = true;
					return valid;
				}
				if (grid[st_y + 2][st_x + 1] != 0)
				{
					if (st_y - 1 < 0 || grid[st_y - 1][st_x] != 0 || grid[st_y + 1][st_x + 1] != 0)
					{
						valid = false;
						return valid;
					}
					emptytet(grid);
					st_y = st_y - 1;
					valid = true;
					return valid;
				}
				if (grid[st_y + 1][st_x + 1] != 0)
				{
					if (st_y + 1 > 19 || grid[st_y][st_x - 1] != 0 || grid[st_y + 2][st_x] != 0)
					{
						valid = false;
						return valid;
					}
					emptytet(grid);
					st_x = st_x - 1;
					valid = true;
					return valid;
				}
			}
			if (st_y + 1 > 19)
			{
				if (grid[st_y - 1][st_x] != 0 || grid[st_y - 1][st_x + 1] != 0)
				{
					valid = false;
					return valid;
				}
				emptytet(grid);
				st_y = st_y - 1;
				if (grid[st_y + 1][st_x + 1] == 0 && grid[st_y + 2][st_x + 1] == 0)
				{
					valid = true;
					return valid;
				}
				if (grid[st_y + 2][st_x + 1] != 0)
				{
					if (st_y - 1 < 0 || grid[st_y - 1][st_x] != 0 || grid[st_y + 1][st_x + 1] != 0)
					{
						valid = false;
						return valid;
					}
					emptytet(grid);
					st_y = st_y - 1;
					valid = true;
					return valid;
				}
				if (grid[st_y + 1][st_x + 1] != 0)
				{
					if (st_y + 1 > 19 || grid[st_y][st_x - 1] != 0 || grid[st_y + 2][st_x] != 0)
					{
						valid = false;
						return valid;
					}
					emptytet(grid);
					st_x = st_x - 1;
					valid = true;
					return valid;
				}
			}
		}
		if (rotationstate == 1 || rotationstate == 3)
		{
			if (st_x - 1 >= 0)
			{
				if (grid[st_y][st_x + 1] == 0 && grid[st_y + 1][st_x - 1] == 0)
				{
					valid = true;
					return valid;
				}
				if (grid[st_y][st_x + 1] != 0 || grid[st_y + 1][st_x - 1] != 0)
				{
					if (grid[st_y + 2][st_x] != 0 || grid[st_y - 2][st_x - 1] != 0)
					{
						valid = false;
						return valid;
					}
					emptytet(grid);
					st_y = st_y - 1;
					valid = true;
					return valid;
				}
			}
			if (st_x - 1 < 0)
			{
				if (grid[st_y][st_x + 1] != 0 || grid[st_y + 1][st_x + 2] != 0 || grid[st_y + 2][st_x + 2] != 0)
				{
					valid = false;
					return valid;
				}
				emptytet(grid);
				st_x = st_x + 1;
				if (grid[st_y][st_x + 1] == 0 && grid[st_y + 1][st_x - 1] == 0)
				{
					valid = true;
					return valid;
				}
				if (grid[st_y][st_x + 1] != 0 || grid[st_y + 1][st_x - 1] != 0)
				{
					if (grid[st_y + 2][st_x] != 0 || grid[st_y - 2][st_x - 1] != 0)
					{
						valid = false;
						return valid;
					}
					emptytet(grid);
					st_y = st_y - 1;
					valid = true;
					return valid;
				}
			}
		}
		return valid;
	}
	void moveleft(int grid[][10])
	{
		if (checkspaceleft(grid))
		{
			emptytet(grid);
			st_x--;
			drawtet(grid);
			return;
		}
	}
	void moveright(int grid[][10])
	{
		if (checkspaceright(grid))
		{

			emptytet(grid);
			st_x++;
			drawtet(grid);
			return;
		}
	}
	void rotate(int grid[][10])
	{
		if (rotationvalidity(grid)) {
			emptytet(grid);
			rotationstate = rotationstate + 1;
			if (rotationstate > 3) {
				updaterotation(rotationstate);
			}
			drawtet(grid);
		}
	}
	void continuousemove(int grid[][10])
	{
		if (checkspacedown(grid)) {
			emptytet(grid);
			st_y++;
			drawtet(grid);
		}

	}
	~Tet_S() { };
};

//_________________________************************************_________________________________-

class Tet_O :public Tet
{
public:

	Tet_O() :Tet(4, 0, 3)
	{
		if (rotationstate == 0 || rotationstate == 2 || rotationstate == 1 || rotationstate == 3)
		{
			h = 2;
			w = 2;
		}

	}
	void drawtet(int grid[][10])
	{
		updaterotation(rotationstate);
		if (rotationstate == 0 || rotationstate == 1 || rotationstate == 2 || rotationstate == 3)
		{
			grid[st_y][st_x] = 4;
			grid[st_y][st_x + 1] = 4;
			grid[st_y + 1][st_x] = 4;
			grid[st_y + 1][st_x + 1] = 4;
		}
	}
	void emptytet(int grid[][10])
	{
		updaterotation(rotationstate);
		if (rotationstate == 0 || rotationstate == 1 || rotationstate == 2 || rotationstate == 3)
		{
			grid[st_y][st_x] = 0;
			grid[st_y][st_x + 1] = 0;
			grid[st_y + 1][st_x] = 0;
			grid[st_y + 1][st_x + 1] = 0;
		}
	}
	bool checkspacedown(int grid[][10])
	{
		bool space = true;
		if (rotationstate == 0 || rotationstate == 1 || rotationstate == 2 || rotationstate == 3)
		{
			if (st_y + 2 > 20 || grid[st_y + 2][st_x] != 0 || grid[st_y + 2][st_x + 1] != 0)
			{
				space = false;
				return space;
			}

			return space;
		}
		return space;
	}
	bool checkspaceright(int grid[][10])
	{
		bool space = true;
		updaterotation(rotationstate);
		if (rotationstate == 0 || rotationstate == 1 || rotationstate == 2 || rotationstate == 3)
		{
			if (st_x + 2 >= 10 || grid[st_y][st_x + 2] != 0 || grid[st_y + 1][st_x + 2] != 0)
			{
				space = false;
				return space;
			}
		}
		return space;
	}
	bool checkspaceleft(int grid[][10])
	{
		bool space = true;
		updaterotation(rotationstate);
		if (rotationstate == 0 || rotationstate == 1 || rotationstate == 2 || rotationstate == 3)
		{
			if (st_x - 1 < 0 || grid[st_y][st_x - 1] != 0 || grid[st_y + 1][st_x - 1] != 0)
			{
				space = false;
				return space;
			}
		}
		return space;
	}
	bool rotationvalidity(int grid[][10])
	{
		return true;
	}
	void moveleft(int grid[][10])
	{
		if (checkspaceleft(grid))
		{
			emptytet(grid);
			st_x--;
			drawtet(grid);
			return;
		}
	}
	void moveright(int grid[][10])
	{
		if (checkspaceright(grid))
		{
			emptytet(grid);
			st_x++;
			drawtet(grid);
			return;
		}
	}
	void rotate(int grid[][10])
	{
		if (rotationvalidity(grid)) {
			emptytet(grid);
			rotationstate = rotationstate + 1;
			if (rotationstate > 3) {
				updaterotation(rotationstate);
			}
			drawtet(grid);
		}
	}
	void continuousemove(int grid[][10])
	{
		if (checkspacedown(grid)) {
			emptytet(grid);
			st_y++;
			drawtet(grid);
		}

	}
	~Tet_O() { };
};

//_________________________************************************_________________________________-

class Tet_J :public Tet
{
public:
	Tet_J() :Tet(5, 0, 0)
	{
		if (rotationstate == 0 || rotationstate == 2)
		{
			h = 3;
			w = 2;
		}
		if (rotationstate == 1 || rotationstate == 3)
		{
			h = 2;
			w = 3;
		}

	}

	void drawtet(int grid[][10])
	{
		updaterotation(rotationstate);
		if (rotationstate == 0)
		{
			grid[st_y][st_x] = 5;
			grid[st_y + 1][st_x] = 5;
			grid[st_y + 2][st_x] = 5;
			grid[st_y + 2][st_x - 1] = 5;
		}
		if (rotationstate == 1)
		{
			grid[st_y][st_x] = 5;
			grid[st_y + 1][st_x] = 5;
			grid[st_y + 1][st_x + 1] = 5;
			grid[st_y + 1][st_x + 2] = 5;
		}
		if (rotationstate == 2)
		{
			grid[st_y][st_x] = 5;
			grid[st_y + 1][st_x] = 5;
			grid[st_y + 2][st_x] = 5;
			grid[st_y][st_x + 1] = 5;
		}
		if (rotationstate == 3)
		{
			grid[st_y][st_x] = 5;
			grid[st_y][st_x + 1] = 5;
			grid[st_y][st_x + 2] = 5;
			grid[st_y + 1][st_x + 2] = 5;
		}
	}
	void emptytet(int grid[][10])
	{
		updaterotation(rotationstate);
		if (rotationstate == 0)
		{
			grid[st_y][st_x] = 0;
			grid[st_y + 1][st_x] = 0;
			grid[st_y + 2][st_x] = 0;
			grid[st_y + 2][st_x - 1] = 0;
		}
		if (rotationstate == 1)
		{
			grid[st_y][st_x] = 0;
			grid[st_y + 1][st_x] = 0;
			grid[st_y + 1][st_x + 1] = 0;
			grid[st_y + 1][st_x + 2] = 0;
		}
		if (rotationstate == 2)
		{
			grid[st_y][st_x] = 0;
			grid[st_y + 1][st_x] = 0;
			grid[st_y + 2][st_x] = 0;
			grid[st_y][st_x + 1] = 0;
		}
		if (rotationstate == 3)
		{
			grid[st_y][st_x] = 0;
			grid[st_y][st_x + 1] = 0;
			grid[st_y][st_x + 2] = 0;
			grid[st_y + 1][st_x + 2] = 0;
		}
	}

	bool checkspaceright(int grid[][10])
	{
		bool space = true;

		if (rotationstate == 0)
		{
			if (st_x + 1 > 9)
			{
				space = false;
				return space;
			}
			if (grid[st_y][st_x + 1] != 0 || grid[st_y + 1][st_x + 1] != 0 || grid[st_y + 2][st_x + 1] != 0)
			{
				space = false;
				return space;
			}
		}
		if (rotationstate == 1)
		{
			if (st_x + 3 > 9)
			{
				space = false;
				return space;
			}
			if (grid[st_y][st_x + 1] != 0 || grid[st_y + 1][st_x + 3])
			{
				space = false;
				return space;
			}
		}
		if (rotationstate == 2)
		{
			if (st_x + 2 > 9)
			{
				space = false;
				return space;
			}
			if (grid[st_y][st_x + 2] != 0 || grid[st_y + 1][st_x + 1] != 0 || grid[st_y + 2][st_x + 1] != 0)
			{
				space = false;
				return space;
			}
		}
		if (rotationstate == 3)
		{
			if (st_x + 3 > 9)
			{
				space = false;
				return space;
			}
			if (grid[st_y][st_x + 3] != 0 || grid[st_y + 1][st_x + 3] != 0)
			{
				space = false;
				return space;
			}
		}
		return space;
	}
	bool checkspaceleft(int grid[][10])
	{
		bool space = true;
		if (rotationstate == 0)
		{
			if (st_x - 2 < 0)
			{
				space = false;
				return space;
			}
			if (grid[st_y][st_x - 1] != 0 || grid[st_y + 1][st_x - 1] != 0 || grid[st_y + 2][st_x - 2] != 0)
			{
				space = false;
				return space;
			}
		}
		if (rotationstate == 1)
		{
			if (st_x - 1 < 0)
			{
				space = false;
				return space;
			}
			if (grid[st_y][st_x - 1] != 0 || grid[st_y + 1][st_x - 1] != 0)
			{
				space = false;
				return space;
			}
		}
		if (rotationstate == 2)
		{
			if (st_x - 1 < 0)
			{
				space = false;
				return space;
			}
			if (grid[st_y][st_x - 1] != 0 || grid[st_y + 1][st_x - 1] != 0 || grid[st_y + 2][st_x - 1] != 0)
			{
				space = false;
				return space;
			}
		}
		if (rotationstate == 3)
		{
			if (st_x - 1 < 0)
			{
				space = false;
				return space;
			}
			if (grid[st_y][st_x - 1] != 0 || grid[st_y + 1][st_x + 1] != 0)
			{
				space = false;
				return space;
			}
		}
		return space;
	}

	bool checkspacedown(int grid[][10])
	{
		bool space = true;
		updaterotation(rotationstate);
		if (rotationstate == 0 || rotationstate == 2)
		{
			if (st_y + 3 > 19)
			{
				space = false;
				return space;
			}
		}
		if (rotationstate == 1 || rotationstate == 3)
		{
			if (st_y + 2 > 19)
			{
				space = false;
				return space;
			}
		}
		if (rotationstate == 0)
		{
			if (grid[st_y + 3][st_x - 1] != 0 || grid[st_y + 3][st_x] != 0)
			{
				space = false;
				return space;
			}
		}
		if (rotationstate == 1)
		{
			if (grid[st_y + 2][st_x] != 0 || grid[st_y + 2][st_x + 1] != 0 || grid[st_y + 2][st_x + 2] != 0)
			{
				space = false;
				return false;
			}
		}
		if (rotationstate == 2)
		{
			if (grid[st_y + 1][st_x + 1] != 0 || grid[st_y + 3][st_x] != 0)
			{
				space = false;
				return space;
			}
		}
		if (rotationstate == 3)
		{
			if (grid[st_y + 1][st_x + 1] != 0 || grid[st_y + 2][st_x + 2] != 0 || grid[st_y + 1][st_x] != 0)
			{
				space = false;
				return space;
			}
		}
		return space;
	}
	bool rotationvalidity(int grid[][10])
	{
		bool valid = false;
		updaterotation(rotationstate);
		if (rotationstate == 0)
		{
			if (st_x + 1 <= 9)
			{
				if (grid[st_y][st_x] == 0 && grid[st_y + 1][st_x] == 0 && grid[st_y + 1][st_x + 2] == 0)
				{
					valid = true;
					return valid;
				}
				if (grid[st_y][st_x] != 0)
				{
					if (grid[st_y + 1][st_x] != 0 && grid[st_y + 2][st_x + 2] != 0)
					{
						valid = false;
						return valid;
					}
					emptytet(grid);
					st_y = st_y + 1;
					valid = true;
					return valid;
				}
				if (grid[st_y + 1][st_x] != 0)
				{
					if (st_x - 1 < 0 || grid[st_y + 1][st_x - 1] != 0 || grid[st_y + 2][st_x - 1] != 0)
					{
						valid = false;
						return valid;
					}
					emptytet(grid);
					st_y = st_y + 1;
					st_x = st_x - 1;
					valid = true;
					return valid;
				}
			}
			if (st_x + 1 > 9)
			{
				if (grid[st_y][st_x - 1] != 0 || grid[st_y + 1][st_x - 1] != 0 || grid[st_y + 2][st_x - 2] != 0)
				{
					valid = false;
					return valid;
				}
				emptytet(grid);
				st_x = st_x - 2;
				if (grid[st_y][st_x] == 0 && grid[st_y + 1][st_x] == 0 && grid[st_y + 1][st_x + 2] == 0)
				{
					valid = true;
					return valid;
				}
				if (grid[st_y][st_x] != 0)
				{
					if (grid[st_y + 1][st_x] != 0 && grid[st_y + 2][st_x + 2] != 0)
					{
						valid = false;
						return valid;
					}
					emptytet(grid);
					st_y = st_y + 1;
					valid = true;
					return valid;
				}
				if (grid[st_y + 1][st_x] != 0)
				{
					if (st_x - 1 < 0 || grid[st_y + 1][st_x - 1] != 0 || grid[st_y + 2][st_x - 1] != 0)
					{
						valid = false;
						return valid;
					}
					emptytet(grid);
					st_y = st_y + 1;
					st_x = st_x - 1;
					valid = true;
					return valid;
				}
			}

		}
		if (rotationstate == 1)
		{
			if (st_y + 2 <= 19)
			{
				if (grid[st_y][st_x + 1] == 0 && grid[st_y + 2][st_x] == 0)
				{
					valid = true;
					return valid;
				}
				if (grid[st_y][st_x + 1] != 0 || grid[st_y + 2][st_x] != 0)
				{
					if (st_y - 1 < 0 || grid[st_y - 1][st_x] != 0 || grid[st_y - 1][st_x + 1] != 0)
					{
						valid = false;
						return valid;
					}
					emptytet(grid);
					st_y = st_y - 1;
					valid = true;
					return valid;
				}
			}
			if (st_y + 2 > 19)
			{
				if (grid[st_y][st_x + 1] != 0 || grid[st_y][st_x + 2] != 0 || grid[st_y - 1][st_x] != 0)
				{
					valid = false;
					return valid;
				}
				if (grid[st_y][st_x + 1] == 0 && grid[st_y + 2][st_x] == 0)
				{
					valid = true;
					return valid;
				}
				if (grid[st_y][st_x + 1] != 0 || grid[st_y + 2][st_x] != 0)
				{
					if (st_y - 1 < 0 || grid[st_y - 1][st_x] != 0 || grid[st_y - 1][st_x + 1] != 0)
					{
						valid = false;
						return valid;
					}
					emptytet(grid);
					st_y = st_y - 1;
					valid = true;
					return valid;
				}
			}
		}
		if (rotationstate == 2)
		{
			if (st_x + 2 <= 9)
			{
				if (grid[st_y][st_x + 2] == 0 && grid[st_y + 1][st_x + 2] == 0)
				{
					valid = true;
					return valid;
				}
				if (grid[st_y][st_x + 2] != 0 || grid[st_y + 1][st_x + 2] != 0)
				{
					if (st_x - 1 < 0 || grid[st_y + 1][st_x + 1] != 0 || grid[st_y][st_x - 1] != 0)
					{
						valid = false;
						return false;
					}
					emptytet(grid);
					st_x = st_x - 1;
					valid = true;
					return valid;
				}

			}
			if (st_x + 2 > 9)
			{
				if (grid[st_y][st_x - 1] != 0 || grid[st_y + 1][st_x - 1] != 0 || grid[st_y + 2][st_x - 1] != 0)
				{
					valid = false;
					return valid;
				}
				emptytet(grid);
				st_x = st_x - 1;

				if (grid[st_y][st_x + 2] == 0 && grid[st_y + 1][st_x + 2] == 0)
				{
					valid = true;
					return valid;
				}
				if (grid[st_y][st_x + 2] != 0 || grid[st_y + 1][st_x + 2] != 0)
				{
					if (st_x - 1 < 0 || grid[st_y + 1][st_x + 1] != 0 || grid[st_y][st_x - 1] != 0)
					{
						valid = false;
						return false;
					}
					emptytet(grid);
					st_x = st_x - 1;
					valid = true;
					return valid;
				}
			}
		}
		if (rotationstate == 3)
		{
			if (st_y + 2 <= 19)
			{
				if (grid[st_y - 1][st_y + 2] == 0 && grid[st_y + 1][st_x + 1] == 0)
				{
					emptytet(grid);
					st_x = st_x + 2;
					st_y = st_y - 1;
					valid = true;
					return valid;
				}
				if (grid[st_y - 1][st_x + 2] != 0 || grid[st_y + 1][st_x + 1] != 0)
				{
					if (grid[st_y + 2][st_x + 1] != 0 || grid[st_y + 2][st_x + 2] != 0)
					{
						valid = false;
						return valid;
					}
					emptytet(grid);
					st_x = st_x + 2;
					st_y = st_y + 2;
					valid = true;
					return valid;

				}
			}
			if (st_y + 2 > 19)
			{
				if (grid[st_y - 1][st_x] != 0 || grid[st_y - 1][st_x + 1] != 0 || grid[st_y - 1][st_x + 2] != 0)
				{
					valid = false;
					return valid;
				}
				emptytet(grid);
				st_y = st_y - 1;
				if (grid[st_y - 1][st_y + 2] == 0 && grid[st_y + 1][st_x + 1] == 0)
				{
					emptytet(grid);
					st_x = st_x + 2;
					st_y = st_y - 1;
					valid = true;
					return valid;
				}
				if (grid[st_y - 1][st_x + 2] != 0 || grid[st_y + 1][st_x + 1] != 0)
				{
					if (grid[st_y + 2][st_x + 1] != 0 || grid[st_y + 2][st_x + 2] != 0)
					{
						valid = false;
						return valid;
					}
					emptytet(grid);
					st_x = st_x + 2;
					st_y = st_y + 2;
					valid = true;
					return valid;

				}
			}
		}
		return valid;
	}
	void moveleft(int grid[][10])
	{
		if (checkspaceleft(grid))
		{
			emptytet(grid);
			st_x--;
			drawtet(grid);
			return;
		}
	}
	void moveright(int grid[][10])
	{
		if (checkspaceright(grid))
		{
			emptytet(grid);
			st_x++;
			drawtet(grid);
			return;
		}
	}
	void rotate(int grid[][10])
	{
		if (rotationvalidity(grid)) {
			emptytet(grid);
			rotationstate = rotationstate + 1;
			if (rotationstate > 3) {
				updaterotation(rotationstate);
			}
			drawtet(grid);
		}
	}
	void continuousemove(int grid[][10])
	{
		if (checkspacedown(grid)) {
			emptytet(grid);
			st_y++;
			drawtet(grid);
		}

	}
	~Tet_J() { };

};

//_________________________************************************_________________________________-

class Tet_Z :public Tet
{
public:
	Tet_Z() :Tet(4, 0, 0)
	{
		if (rotationstate == 0 || rotationstate == 2)
		{
			h = 2;
			w = 3;
		}
		if (rotationstate == 1 || rotationstate == 3)
		{
			h = 3;
			w = 2;
		}
	}
	void drawtet(int grid[][10])
	{
		updaterotation(rotationstate);
		if (rotationstate == 0 || rotationstate == 2)
		{
			grid[st_y][st_x] = 6;
			grid[st_y][st_x + 1] = 6;
			grid[st_y + 1][st_x + 1] = 6;
			grid[st_y + 1][st_x + 2] = 6;
		}
		if (rotationstate == 1 || rotationstate == 3)
		{
			grid[st_y][st_x] = 6;
			grid[st_y + 1][st_x - 1] = 6;
			grid[st_y + 1][st_x] = 6;
			grid[st_y + 2][st_x - 1] = 6;
		}

	}
	void emptytet(int grid[][10])
	{
		updaterotation(rotationstate);
		if (rotationstate == 0 || rotationstate == 2)
		{
			grid[st_y][st_x] = 0;
			grid[st_y][st_x + 1] = 0;
			grid[st_y + 1][st_x + 1] = 0;
			grid[st_y + 1][st_x + 2] = 0;
		}
		if (rotationstate == 1 || rotationstate == 3)
		{
			grid[st_y][st_x] = 0;
			grid[st_y + 1][st_x - 1] = 0;
			grid[st_y + 1][st_x] = 0;
			grid[st_y + 2][st_x - 1] = 0;
		}

	}

	bool checkspaceleft(int grid[][10])
	{
		updaterotation(rotationstate);
		bool space = true;
		if (rotationstate == 0 || rotationstate == 2)
		{
			if (st_x - 1 < 0)
			{
				space = false;
				return space;
			}
			if (grid[st_y][st_x - 1] != 0 || grid[st_y + 1][st_x] != 0)
			{
				space = false;
				return false;
			}
		}
		if (rotationstate == 1 || rotationstate == 3)
		{
			if (st_x - 2 < 0)
			{
				space = false;
				return space;
			}
			if (grid[st_y][st_x - 1] != 0 || grid[st_y + 1][st_x - 2] || grid[st_y + 2][st_x - 2] != 0)
			{
				space = false;
				return space;
			}
		}
		return space;
	}

	bool checkspaceright(int grid[][10])
	{
		updaterotation(rotationstate);
		bool space = true;
		if (rotationstate == 1 || rotationstate == 3)
		{
			if (st_x + 1 > 9)
			{
				space = false;
				return space;
			}
			if (grid[st_y][st_x + 1] != 0 || grid[st_y + 1][st_x + 1] != 0 || grid[st_y + 2][st_x] != 0)
			{
				space = false;
				return space;
			}
		}
		if (rotationstate == 0 || rotationstate == 2)
		{
			if (st_x + 3 > 9)
			{
				space = false;
				return space;
			}
			if (grid[st_y][st_x + 2] != 0 || grid[st_y + 1][st_x + 3] != 0)
			{
				space = false;
				return space;
			}
		}
		return space;
	}
	bool checkspacedown(int grid[][10])
	{
		bool space = true;
		updaterotation(rotationstate);
		if (rotationstate == 0 || rotationstate == 2)
		{
			if (st_y + 2 > 19)
			{
				space = false;
				return space;
			}
			if (grid[st_y + 1][st_x] != 0 || grid[st_y + 2][st_x + 1] != 0 || grid[st_y + 2][st_x + 2] != 0)
			{
				space = false;
				return space;
			}
		}
		if (rotationstate == 1 || rotationstate == 3)
		{
			if (st_y + 3 > 19)
			{
				space = false;
				return space;
			}
			if (grid[st_y + 3][st_x - 1] != 0 || grid[st_y + 2][st_x] != 0)
			{
				space = false;
				return space;
			}
		}
		return space;
	}

	bool rotationvalidity(int grid[][10])
	{
		bool valid = false;
		updaterotation(rotationstate);
		if (rotationstate == 0 || rotationstate == 2)
		{
			if (st_y + 2 <= 19)
			{
				if (grid[st_y + 1][st_x] == 0 && grid[st_y + 2][st_x] == 0)
				{
					emptytet(grid);
					st_x = st_x + 1;
					valid = true;
					return valid;
				}
				if (grid[st_y + 1][st_x] != 0 || grid[st_y + 2][st_x] != 0)
				{
					if (grid[st_y][st_x + 2] != 0 || grid[st_y + 2][st_x + 1] != 0)
					{
						valid = false;
						return valid;
					}
					emptytet(grid);
					st_x = st_x + 2;
					valid = true;
					return valid;
				}
			}
			if (st_y + 2 > 19)
			{
				if (grid[st_y - 1][st_x] != 0 || grid[st_y - 1][st_x + 1] != 0 || grid[st_y][st_x + 2] != 0)
				{
					valid = false;
					return valid;
				}
				emptytet(grid);
				st_y = st_y - 1;
				if (grid[st_y + 1][st_x] == 0 && grid[st_y + 2][st_x] == 0)
				{
					emptytet(grid);
					st_x = st_x + 1;
					valid = true;
					return valid;
				}
				if (grid[st_y + 1][st_x] != 0 || grid[st_y + 2][st_x] != 0)
				{
					if (grid[st_y][st_x + 2] != 0 || grid[st_y + 2][st_x + 1] != 0)
					{
						valid = false;
						return valid;
					}
					emptytet(grid);
					st_x = st_x + 2;
					valid = true;
					return valid;
				}
			}
		}
		if (rotationstate == 1 || rotationstate == 3)
		{
			if (st_x + 1 <= 9)
			{
				if (grid[st_y][st_x - 1] == 0 && grid[st_y + 1][st_x + 1] == 0)
				{
					emptytet(grid);
					st_x = st_x - 1;
					valid = true;
					return valid;
				}
				if (grid[st_y][st_x - 1] != 0 || grid[st_y + 1][st_x + 1] != 0)
				{
					if (grid[st_y + 2][st_x] != 0 || grid[st_y + 2][st_x + 1] != 0)
					{
						valid = false;
						return valid;
					}
					emptytet(grid);
					st_y = st_y + 1;
					st_x = st_x - 1;
					valid = true;
					return valid;
				}
			}
			if (st_x + 1 > 9)
			{
				if (grid[st_y][st_x - 1] != 0 || grid[st_y + 1][st_x - 2] != 0 || grid[st_y + 2][st_x - 2] != 0)
				{
					valid = false;
					return valid;
				}
				emptytet(grid);
				st_x = st_x - 1;
				if (grid[st_y][st_x - 1] == 0 && grid[st_y + 1][st_x + 1] == 0)
				{
					emptytet(grid);
					st_x = st_x - 1;
					valid = true;
					return valid;
				}
				if (grid[st_y][st_x - 1] != 0 || grid[st_y + 1][st_x + 1] != 0)
				{
					if (grid[st_y + 2][st_x] != 0 || grid[st_y + 2][st_x + 1] != 0)
					{
						valid = false;
						return valid;
					}
					emptytet(grid);
					st_y = st_y + 1;
					st_x = st_x - 1;
					valid = true;
					return valid;
				}
			}
		}
		return valid;
	}
	void moveleft(int grid[][10])
	{
		if (checkspaceleft(grid))
		{
			emptytet(grid);
			st_x--;
			drawtet(grid);
			return;
		}
	}
	void moveright(int grid[][10])
	{
		if (checkspaceright(grid))
		{

			emptytet(grid);
			st_x++;
			drawtet(grid);
			return;
		}
	}
	void rotate(int grid[][10])
	{
		if (rotationvalidity(grid)) {
			emptytet(grid);
			rotationstate = rotationstate + 1;
			if (rotationstate > 3) {
				updaterotation(rotationstate);
			}
			drawtet(grid);
		}
	}
	void continuousemove(int grid[][10])
	{
		if (checkspacedown(grid)) {
			emptytet(grid);
			st_y++;

			drawtet(grid);
		}

	}
	~Tet_Z() { };

};

//_________________________************************************_________________________________-

class Tet_T :public Tet
{
public:
	Tet_T() :Tet(4, 0, 0)
	{
		if (rotationstate == 0 || rotationstate == 2)
		{
			h = 2;
			w = 3;
		}
		if (rotationstate == 1 || rotationstate == 3)
		{
			h = 3;
			w = 2;
		}
	}
	void drawtet(int grid[][10])
	{
		updaterotation(rotationstate);
		if (rotationstate == 0)
		{
			grid[st_y][st_x] = 7;
			grid[st_y][st_x - 1] = 7;
			grid[st_y][st_x + 1] = 7;
			grid[st_y + 1][st_x] = 7;
		}
		if (rotationstate == 1)
		{
			grid[st_y][st_x] = 7;
			grid[st_y + 1][st_x] = 7;
			grid[st_y + 2][st_x] = 7;
			grid[st_y + 1][st_x - 1] = 7;
		}
		if (rotationstate == 2)
		{
			grid[st_y][st_x] = 7;
			grid[st_y + 1][st_x - 1] = 7;
			grid[st_y + 1][st_x + 1] = 7;
			grid[st_y + 1][st_x] = 7;
		}
		if (rotationstate == 3)
		{
			grid[st_y][st_x] = 7;
			grid[st_y + 1][st_x] = 7;
			grid[st_y + 2][st_x] = 7;
			grid[st_y + 1][st_x + 1] = 7;
		}
	}
	void emptytet(int grid[][10])
	{
		updaterotation(rotationstate);
		if (rotationstate == 0)
		{
			grid[st_y][st_x] = 0;
			grid[st_y][st_x - 1] = 0;
			grid[st_y][st_x + 1] = 0;
			grid[st_y + 1][st_x] = 0;
		}
		if (rotationstate == 1)
		{
			grid[st_y][st_x] = 0;
			grid[st_y + 1][st_x] = 0;
			grid[st_y + 2][st_x] = 0;
			grid[st_y + 1][st_x - 1] = 0;
		}
		if (rotationstate == 2)
		{
			grid[st_y][st_x] = 0;
			grid[st_y + 1][st_x - 1] = 0;
			grid[st_y + 1][st_x + 1] = 0;
			grid[st_y + 1][st_x] = 0;
		}
		if (rotationstate == 3)
		{
			grid[st_y][st_x] = 0;
			grid[st_y + 1][st_x] = 0;
			grid[st_y + 2][st_x] = 0;
			grid[st_y + 1][st_x + 1] = 0;
		}
	}
	bool checkspaceleft(int grid[][10])
	{
		bool space = true;
		if (rotationstate == 0)
		{
			if (st_x - 2 < 0)
			{
				space = false;
				return space;
			}
			if (grid[st_y][st_x - 2] != 0 || grid[st_y + 1][st_x - 1] != 0)
			{
				space = false;
				return space;
			}
		}
		if (rotationstate == 1)
		{
			if (st_x - 2 < 0)
			{
				space = false;
				return space;
			}
			if (grid[st_y][st_x - 1] != 0 || grid[st_y + 1][st_x - 2] != 0 || grid[st_y + 2][st_x - 1] != 0)
			{
				space = false;
				return space;
			}
		}
		if (rotationstate == 2)
		{
			if (st_x - 2 < 0)
			{
				space = false;
				return space;
			}
			if (grid[st_y][st_x - 1] != 0 || grid[st_y + 1][st_x - 2] != 0)
			{
				space = false;
				return space;
			}
		}
		if (rotationstate == 3)
		{
			if (st_x - 1 < 0)
			{
				space = false;
				return space;
			}
			if (grid[st_y][st_x - 1] != 0 || grid[st_y + 1][st_x - 1] != 0 || grid[st_y + 2][st_x - 1] != 0)
			{
				space = false;
				return space;
			}
		}
		return space;
	}
	bool checkspaceright(int grid[][10])
	{
		bool space = true;
		updaterotation(rotationstate);
		if (rotationstate == 0)
		{
			if (st_x + 2 > 9)
			{
				space = false;
				return space;
			}
			if (grid[st_y + 1][st_x + 1] != 0 || grid[st_y][st_x + 2] != 0)
			{
				space = false;
				return space;
			}
		}
		if (rotationstate == 1)
		{
			if (st_x + 1 > 9)
			{
				space = false;
				return space;
			}
			if (grid[st_y][st_x + 1] != 0 || grid[st_y + 1][st_x + 1] != 0 || grid[st_y + 2][st_x + 1] != 0)
			{
				space = false;
				return space;
			}
		}
		if (rotationstate == 2)
		{
			if (st_x + 2 > 9)
			{
				space = false;
				return space;
			}
			if (grid[st_y][st_x + 1] != 0 || grid[st_y + 1][st_x + 2] != 0)
			{
				space = false;
				return space;
			}
		}
		if (rotationstate == 3)
		{
			if (st_x + 2 > 9)
			{
				space = false;
				return space;
			}
			if (grid[st_y][st_x + 1] != 0 || grid[st_y + 1][st_x + 2] != 0 || grid[st_y + 2][st_x + 1] != 0)
			{
				space = false;
				return space;
			}
		}
		return space;
	}
	bool checkspacedown(int grid[][10])
	{
		bool space = true;
		updaterotation(rotationstate);
		if (rotationstate == 0)
		{
			if (st_y + 2 > 19)
			{
				space = false;
				return space;
			}
			if (grid[st_y + 1][st_x - 1] != 0 || grid[st_y + 2][st_x] != 0 || grid[st_y + 1][st_x + 1] != 0)
			{
				space = false;
				return space;
			}
		}
		if (rotationstate == 1)
		{
			if (st_y + 3 > 19)
			{
				space = false;
				return space;
			}
			if (grid[st_y + 3][st_x] != 0 || grid[st_y + 2][st_x - 1] != 0)
			{
				space = false;
				return space;
			}
		}
		if (rotationstate == 2)
		{
			if (st_y + 2 > 19)
			{
				space = false;
				return space;
			}
			if (grid[st_y + 2][st_x - 1] != 0 || grid[st_y + 2][st_x] != 0 || grid[st_y + 2][st_x + 1] != 0)
			{
				space = false;
				return space;
			}
		}
		if (rotationstate == 3)
		{
			if (st_y + 3 > 19)
			{
				space = false;
				return space;
			}
			if (grid[st_y + 3][st_x] != 0 || grid[st_y + 2][st_x + 1] != 0)
			{
				space = false;
				return space;
			}
		}
		return space;
	}
	bool rotationvalidity(int grid[][10])
	{
		bool valid = false;
		updaterotation(rotationstate);
		if (rotationstate == 0)
		{
			if (st_y - 1 >= 0 && grid[st_y - 1][st_x] == 0)
			{
				emptytet(grid);
				st_y = st_y - 1;
				valid = true;
				return valid;
			}
			if (st_y - 1 < 0 || grid[st_y - 1][st_x] != 0)
			{
				if (st_y + 2 > 19 || grid[st_y + 2][st_x] != 0 || grid[st_y + 1][st_x - 1] != 0)
				{
					valid = false;
					return false;
				}
				valid = true;
				return valid;
			}
		}
		if (rotationstate == 1)
		{
			if (st_x + 1 <= 9 && grid[st_y + 1][st_x + 1] == 0)
			{
				valid = true;
				return valid;
			}
			if (st_x + 1 > 9 || grid[st_y + 1][st_x + 1] != 0)
			{
				if (grid[st_y + 2][st_x - 1] != 0 || grid[st_y + 2][st_x - 2] != 0)
				{
					valid = false;
					return valid;
				}
				emptytet(grid);
				st_y = st_y + 1;
				st_x = st_x - 1;
				valid = true;
				return valid;
			}
		}
		if (rotationstate == 2)
		{
			if (st_y + 2 <= 19 && grid[st_y + 2][st_x] == 0)
			{
				valid = true;
				return valid;
			}
			if (st_y + 2 > 19 || grid[st_y + 2][st_x] != 0)
			{
				if (grid[st_y - 1][st_x] != 0 || grid[st_y][st_x + 1] != 0)
				{
					valid = false;
					return valid;
				}
				emptytet(grid);
				st_y = st_y - 1;
				valid = true;
				return valid;
			}
		}
		if (rotationstate == 3)
		{
			if (st_x - 1 >= 0 && grid[st_y + 1][st_x - 1] == 0)
			{
				valid = true;
				return valid;
			}
			if (st_x - 1 < 0 || grid[st_y + 1][st_x - 1] != 0)
			{
				if (grid[st_y][st_x + 1] != 0 || grid[st_y + 1][st_x + 2] != 0)
				{
					valid = false;
					return valid;
				}
				emptytet(grid);
				st_x = st_x + 1;
			}
		}
		return valid;
	}
	void moveleft(int grid[][10])
	{
		if (checkspaceleft(grid))
		{
			emptytet(grid);
			st_x--;
			drawtet(grid);
			return;
		}
	}
	void moveright(int grid[][10])
	{
		if (checkspaceright(grid))
		{

			emptytet(grid);
			st_x++;
			drawtet(grid);
			return;
		}
	}
	void rotate(int grid[][10])
	{
		if (rotationvalidity(grid)) {
			emptytet(grid);
			rotationstate = rotationstate + 1;
			if (rotationstate > 3) {
				updaterotation(rotationstate);
			}
			drawtet(grid);
		}
	}
	void continuousemove(int grid[][10])
	{
		if (checkspacedown(grid)) {
			emptytet(grid);
			st_y++;
			drawtet(grid);
		}

	}
	~Tet_T() { };
};