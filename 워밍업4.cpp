#include <iostream>
#include <random>

using namespace std;

int x[4], y[4];
int turn = 0;

void makeRect();
void print();
void colide();

int main()
{
	char input;
	makeRect();
	print();

	while (true)
	{
		cout << "asdw로 이동합니다" << endl << "현재 움직이는 사각형: Rect" << turn + 1 << endl;
		cin >> input;
		system("cls");
		if (input == 'a')
		{
			if (x[turn * 2] - 20 >= 0)
			{
				x[turn * 2] -= 20;
				x[turn * 2 + 1] -= 20;
				turn += 1;
				turn %= 2;
			}
			else
				cout << "범위를 넘어가서 이동하지 못합니다" << endl;

		}

		else if (input == 'd')
		{
			if (x[turn * 2 + 1] + 20 <= 800)
			{
				x[turn * 2] += 20;
				x[turn * 2 + 1] += 20;
				turn += 1;
				turn %= 2;
			}
			else
				cout << "범위를 넘어가서 이동하지 못합니다" << endl;

		}

		else if (input == 's')
		{
			if (y[turn * 2] - 20 >= 0)
			{
				y[turn * 2] -= 20;
				y[turn * 2 + 1] -= 20;
				turn += 1;
				turn %= 2;
			}
			else
				cout << "범위를 넘어가서 이동하지 못합니다" << endl;

		}

		else if (input == 'w')
		{
			if (y[turn * 2 + 1] + 20 <= 600)
			{
				y[turn * 2] += 20;
				y[turn * 2 + 1] += 20;
				turn += 1;
				turn %= 2;
			}
			else
				cout << "범위를 넘어가서 이동하지 못합니다" << endl;

		}
		
		print();
		colide();
	}

}

void makeRect()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> disX(0, 800);
	std::uniform_int_distribution<int> disY(0, 600);

	for (int i = 0; i < 4; ++i)
	{
		x[i] = disX(gen);
		y[i] = disY(gen);
	}
	if (x[0] > x[1])
	{
		int temp = x[0];
		x[0] = x[1];
		x[1] = temp;
	}
	if (x[2] > x[3])
	{
		int temp = x[2];
		x[2] = x[3];
		x[3] = temp;
	}
	if (y[0] > y[1])
	{
		int temp = y[0];
		y[0] = y[1];
		y[1] = temp;
	}
	if (y[2] > y[3])
	{
		int temp = y[2];
		y[2] = y[3];
		y[3] = temp;
	}

	
}

void print()
{
	cout << "Rect1: ( " << x[0] << " , " << y[0] << " )" << "( " << x[1] << " , " << y[1] << " )" << endl;
	cout << "Rect2: ( " << x[2] << " , " << y[2] << " )" << "( " << x[3] << " , " << y[3] << " )" << endl;
}

void colide()
{
	if (x[1] >= x[2] && x[0] <= x[3] && y[1] >= y[2] && y[0] <= y[3])
	{
		cout << "충돌했습니다" << endl;
	}


}