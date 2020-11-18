#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
	int seed;
	cin >> seed;
	srand(seed);
	int value[9*9] = {0};
	for (int i = 0; i < 10; )
	{
		int x = rand()%9, y = rand()%9;
		if (value[x*9+y]!=9)
		{
			value[x*9+y]=9;
			i++;
		}
	}
	for (int x = 0; x < 9; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			if (value[x*9+y] == 9)
			{
				continue;
			}
			for (int x_d = -1;x_d <= 1; x_d++)
			{
				for (int y_d = -1;y_d <= 1; y_d++)
				{
					if (x_d == 0 && y_d == 0)
					{
						continue;
					}
					if (x+x_d>=0 && x+x_d<=8 && y+y_d>=0 && y+y_d<=8)
					{
						if (value[(x+x_d)*9+y+y_d] == 9)
						{
							value[x*9+y]++;
						}
					}
				}
			}
		}
	}
	for (int x = 0; x < 9; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			cout << value[x*9+y];
		}
		cout << endl;
	}
	
	return 0;
}
