#include <iostream>
#include <random>
#include <windows.h>
using namespace std;

struct card {
	bool isOpen = false;
	bool isTempTurn = false;
	int color = 1;
	char alpha = 'a';
};
int score = 0;
bool cheatMode = false;
char alphaTable[8] = {'A','B','C','D','E','F','G','H'};
card board[4][4];
int gamecolor = 0;
int turn = 0;
string inputStr;
char cardX;
int cardY;
int tempX1, tempX2, tempY1, tempY2;
int tempC = 0;
void setBoard();
void shuffleBoard();
void swap(int, int, int, int);
void draw();
void play();
int gameCount;
int answerCount = 0;
int main()
{
	
	play();
	
}

void play()
{
	setBoard();
	system("cls");
	draw();
	while (true)
	{
		cout << endl << endl << endl;
		while (true)
		{
			cout << turn % 2 + 1 << "�� ī���� ���� �������ּ���(1, 2, 3, 4): ";
			cin >> inputStr;
			cardY = (int)inputStr[0] - 48;
			if (inputStr[0] == 'c')
			{
				cheatMode = true;
				system("cls");
				draw();
			}
			if (inputStr[0] == 'r')
			{
				system("cls");
				cout << "������մϴ�" << endl;
				setBoard();
			}
			cardY--;
			if (cardY >= 0 && cardY <= 3)
				break;
		}
		while (true)
		{
			cout << turn % 2 + 1 << "�� ī���� ���� �������ּ���(a, b, c, d): ";
			cin >> cardX;
			if (cardX >= 'a' && cardX <= 'd')
				break;
		}
		if (board[cardY][(int)cardX - 97].isOpen || board[cardY][(int)cardX - 97].isTempTurn)
		{
			cout << "�̹� �����ų� ���õ� ī���Դϴ�" << endl;
			continue;
		}

		if (turn % 2 == 0)
		{
			board[cardY][(int)cardX - 97].isTempTurn = true;
			system("cls");
			draw();
			turn++;
		}
		else if (turn % 2 == 1)
		{
			board[cardY][(int)cardX - 97].isTempTurn = true;
			gameCount--;
			system("cls");
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					if (board[i][j].isTempTurn && tempC == 0)
					{
						tempC = 1;
						tempX1 = j;
						tempY1 = i;
					}
					else if (board[i][j].isTempTurn && tempC == 1)
					{
						tempC = 2;
						tempX2 = j;
						tempY2 = i;

						if (board[tempY1][tempX1].alpha == board[tempY2][tempX2].alpha)
						{
							board[tempY1][tempX1].isOpen = true;
							board[tempY2][tempX2].isOpen = true;
							answerCount++;
						}
					}
				}
			}
			draw();
			cout << "2�ʰ� ī�带 �����ݴϴ�" << endl;
			Sleep(2000);
			board[tempY1][tempX1].isTempTurn = false;
			board[tempY2][tempX2].isTempTurn = false;
			tempC = 0;
			turn++;
			system("cls");
			draw();

			if (answerCount == 8)
			{
				cout << "������ Ŭ���� �߽��ϴ�." << endl;
				cout << "score: " << score + gameCount * 5 << endl;
				cout << "r�� �Է��ϸ� ������մϴ�" << endl;
				while (true)
				{
					char clearInput;
					cin >> clearInput;
					if (clearInput == 'r')
					{
						system("cls");
						setBoard();
					}
				}
			}

			if (gameCount == 0)
			{
				system("cls");
				cout << "���� Ŭ��� �����߽��ϴ�" << endl;
				setBoard();
			}



		}
	}
}

void shuffleBoard()
{
	int x,y;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 3);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; ++j)
		{
			for (int k = 0; k < 4; ++k)
			{
				x = dis(gen);
				y = dis(gen);
				swap(j, k, y, x);
			}
		}
	}
}

void setBoard()
{
	score = 500;
	cout << "������ 500 - ó�����ü���*10 + �������ü���*5 �Դϴ�." << endl;
	cout << "���ϴ� ī��� ����Ƚ���� �Է��ϼ���: ";
	cin >> gameCount;
	score -= gameCount * 10;
	cheatMode = false;
	answerCount = 0;
	turn = 0;
	int cnt = 0;
	gamecolor += 1;

	if (gamecolor == 15)
		gamecolor = 1;

	

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			board[i][j*2].isOpen = false;
			board[i][j*2+1].isOpen = false;

			board[i][j * 2].isTempTurn = false;
			board[i][j * 2 + 1].isTempTurn = false;

			board[i][j*2].alpha = alphaTable[cnt];
			board[i][j*2+1].alpha = alphaTable[cnt];
			

			board[i][j*2].color = cnt + gamecolor;
			board[i][j*2+1].color = cnt + gamecolor;
			cnt++;
		}
	}
	shuffleBoard();
	draw();
}

void swap(int y1, int x1, int y2, int x2)
{
	card temp=board[y1][x1];
	board[y1][x1] = board[y2][x2];
	board[y2][x2] = temp;
}

void draw()
{
	cout << "r:�����" << endl;
	cout << "���� ī��� ���� Ƚ��: " << gameCount << endl;
	cout << "   a  b  c  d" << endl << endl;
	for (int i = 0; i < 4; ++i)
	{
		cout << i + 1<<"  ";
		for (int j = 0; j < 4; ++j)
		{
			


			if (board[i][j].isOpen == true)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), board[i][j].color);
				cout << board[i][j].alpha << "  ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			else if (board[i][j].isTempTurn == true && tempC == 2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), board[i][j].color);
				cout << board[i][j].alpha << "  ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			else if (board[i][j].isTempTurn == true)
			{
				cout << "O  ";
			}
			else
				cout << "*  ";
		}
		cout << endl<<endl;
	}
	if (cheatMode)
	{
		cout << "   cheat mode" << endl;
		cout << "   a  b  c  d" << endl << endl;
		for (int i = 0; i < 4; ++i)
		{
			cout << i + 1 << "  ";
			for (int j = 0; j < 4; ++j)
			{
			
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), board[i][j].color);
					cout << board[i][j].alpha << "  ";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			
			}
			cout << endl << endl;
		}
		
	}
}