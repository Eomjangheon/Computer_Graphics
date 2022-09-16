#include <iostream>
#include <deque>
#include <random>
#define max 15
using namespace std;

deque<deque<int>> map;
int x = 0, y = 0;
int cnt=1;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
bool check[4] = { false };
int priD;
int nowD;
int moveN;


void genMap();
void init();
void drawMap();
void move(int, int);
bool isPossible(int, int);

int main()
{
	char input = 'a';
	init();
	genMap();
	drawMap();

	
	while (input != 'q')
	{
		cout << "r:경로재설정 z:모두좌측이동 x:모두우측이동 q:프로그램종료" << endl;
		cout << "명령어 입력: ";
		cin >> input;
		system("cls");

		if (input == 'r')
		{
			for (int i = 0; i < max; ++i)
			{
				for (int j = 0; j < max; ++j)
				{
					map[i][j] = 0;
				}
			}
			x = 0;
			y = 0;
			cnt = 1;
			for (int i = 0; i < 4; ++i)
			{
				check[i] = false;
			}
			genMap();
			drawMap();
			
		}
		if (input == 'z')
		{
			map.push_back(map[0]);
			map.pop_front();
			drawMap();
		}
		if (input == 'x')
		{
			map.push_front(map[max-1]);
			map.pop_back();
			drawMap();
		}
	}
	
}

void init()
{
	deque<int> temp;
	for (int i = 0; i < max; ++i)
	{
		for (int k = 0; k < max; ++k)
		{
			temp.push_back(0);
		}
		map.push_back(temp);
	}
	
}

void drawMap()
{
	for (int i = 0; i < max; ++i)
	{
		for (int k = 0; k < max; ++k)
		{
			cout.width(3);
			cout << map[k][i]<<" ";
		}
		cout << endl;
	}
}

void genMap()
{
	map[y][x] = cnt;
	cnt++;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> disD(0, 3);
	std::uniform_int_distribution<int> disN(3, 6);
	if (disD(gen) % 2 == 0)
	{
		moveN = disN(gen);
		move(3, moveN);
		priD = 3;
	}
	else
	{
		moveN = disN(gen);
		move(2, moveN);
		priD = 2;
	}

	for (int i = 0; i < 12; ++i)
	{
		nowD = disD(gen);
		if (x == 0 && nowD == 0)
			continue;
		if (x == max-2 && nowD == 3)
			continue;
		if (y == 0 && nowD == 1)
			continue;
		if (y == max-2 && nowD == 2)
			continue;

		moveN = disN(gen);
		if (isPossible(priD,nowD))
		{
			check[nowD] = true;
			move(nowD, moveN);
			priD = nowD;
		}
	}

	while (!(check[0] && check[1] && check[2]&& check[3]))
	{
		nowD = disD(gen);
		if (x == 0 && nowD == 0)
			continue;
		if (x == max-2 && nowD == 3)
			continue;
		if (y == 0 && nowD == 1)
			continue;
		if (y == max-2 && nowD == 2)
			continue;

		moveN = disN(gen);
		if (isPossible(priD, nowD))
		{
			
			check[nowD] = true;
			move(nowD, moveN);
			priD = nowD;
		}
	}

	while (x < max-7 || y < max-7)
	{
		nowD = disD(gen);
		if (x == 0 && nowD == 0)
			continue;
		if (x == max-2 && nowD == 3)
			continue;
		if (y == 0 && nowD == 1)
			continue;
		if (y == max-2 && nowD == 2)
			continue;

		moveN = disN(gen);
		if (isPossible(priD, nowD))
		{
			move(nowD, moveN);
			priD = nowD;
		}
	}

	if (priD == 2)
	{
		move(3, 10);
		move(2, 10);
	}
	else if (priD == 3)
	{
		move(2, 10);
		move(3, 10);
	}
	else
	{
		move(2, 10);
		move(3, 10);
	}
	
	
}

void move(int d,int n)
{
	if (n == 10)
	{
		for (int i = 0; i < n; ++i)
		{
			if (x + dx[d] >= 0 && x + dx[d] < max && y + dy[d] >= 0 && y + dy[d] < max)
			{
				x += dx[d];
				y += dy[d];
				map[y][x] = cnt;
				cnt++;
			}
		}
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			if (x + dx[d] >= 0 && x + dx[d] < max-1 && y + dy[d] >= 0 && y + dy[d] < max-1)
			{
				x += dx[d];
				y += dy[d];
				map[y][x] = cnt;
				cnt++;
			}
		}
	}
}

bool isPossible(int pri, int now)
{
	if (pri == now)
		return false;
	if (pri != now)
	{
		if (pri == 0 && now == 3)
			return false;

		else if (pri == 1 && now == 2)
			return false;

		else if (pri == 2 && now == 1)
			return false;

		else if (pri == 3 && now == 0)
			return false;
		else
			return true;
	}
	return false;
}