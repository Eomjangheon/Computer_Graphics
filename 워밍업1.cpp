#include <iostream>
#include <random>

using namespace std;

void set();
void print(char);
void print_2(int);
void add();
void sub();
void mul();
void tra(int);
int det_3(int);
int det_4(int);
int calc(int,int);

int matrix[6][4][4];
int temp_matrix[3][3];
int m_size = 3;

int main()
{
	char input='a';
	set();

	while (input != 'q')
	{
		cout << endl << endl;
		cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
		cout << "���� ��� ũ��: " << m_size << " * " << m_size << endl;
		cout << "m)����  a)����  d)����  r)��Ľİ�  t)��ġ���" << endl;
		if(m_size==3)
			cout << "h)ũ�⺯��(3*3 -> 4*4)  s)��İ� �ٽ� ����  q)����" << endl;
		else
			cout << "h)ũ�⺯��(4*4 -> 3*3)  s)��İ� �ٽ� ����  q)����" << endl;
		cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
		cout << "��ɾ� �Է�: ";
		cin >> input;
		system("cls");
		
		if (input == 'a')
		{
			add();
		}
		else if (input == 'd')
		{
			sub();
		}
		else if (input == 'm')
		{
			mul();
		}
		else if (input == 'r')
		{
			cout << "1�� ���" << endl;
			print_2(0);
			cout << "1�� ��Ľ�: ";
			if (m_size == 3)
				cout << det_3(0) << endl << endl << endl;
			else
				cout << det_4(0) << endl << endl << endl;

			cout << "2�� ���" << endl;
			print_2(1);
			cout << "2�� ��Ľ�: ";
			if (m_size == 3)
				cout << det_3(1) << endl << endl << endl;
			else
				cout << det_4(1) << endl << endl << endl;
		}
		else if (input == 't')
		{
			tra(0);
			cout << "1�� ���" << endl << endl;
			print_2(0);
			cout << "1�� ����� ��ġ���"<< endl << endl;
			print_2(3);
			cout << "1�� ����� ��ġ��� ��Ľ�: ";
			if(m_size==3)
				cout << det_3(3) << endl << endl << endl;
			else
				cout << det_4(3) << endl << endl << endl;

			tra(1);
			cout << "2�� ���" << endl << endl;
			print_2(1);
			cout << "2�� ����� ��ġ���" << endl << endl;
			print_2(3);
			cout << "2�� ����� ��ġ��� ��Ľ�: ";
			if (m_size == 3)
				cout << det_3(3) << endl << endl << endl;
			else
				cout << det_4(3) << endl << endl << endl;

		}
		else if (input == 'h')
		{
			if (m_size == 3)
			{
				m_size = 4;
				matrix[0][3][3] = 1;
				matrix[1][3][3] = 1;

				cout << "1�� ���" << endl;
				print_2(0);
				cout << "1�� ��Ľ�: ";
				cout << det_4(0) << endl << endl;

				cout << "2�� ���" << endl;
				print_2(1);
				cout << "2�� ��Ľ�: ";
				cout << det_4(1) << endl << endl;
			}
			else
			{
				m_size = 3;
			}
		}
		else if (input == 's')
		{
			cout << "������ 1�� ���" << endl << endl;
			print_2(0);

			cout << "������ 2�� ���" << endl << endl;
			print_2(1);

			set();

			cout << "������ 1�� ���" << endl << endl;
			print_2(0);

			cout << "������ 2�� ���" << endl << endl;
			print_2(1);

		}
		else
		{
			cout << "�ؿ� �ִ� ��ɾ ���� �����մϴ�";
		}
		
	}
}

void set()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 2);

	for (int i = 0; i < m_size; ++i)
	{
		for (int j = 0; j < m_size; ++j)
		{
			matrix[0][i][j] = dis(gen);
			matrix[1][i][j] = dis(gen);
		}
	}
}

void print(char op)
{
	for (int i = 0; i < m_size; ++i)
	{
		for (int k = 0; k < 3; ++k)
		{
			cout << "| ";
			for (int j = 0; j < m_size; ++j)
			{
				cout.width(2);
				cout << matrix[k][i][j] << " ";
			}
			if (i == 1 && k == 0)
				cout << "|" << op;
			else if (i == 1 && k == 1)
				cout << "|=";
			else if(k!=2)
				cout << "| ";
		}
		cout << "| "<<endl;
	}
}

void print_2(int n)
{
	for (int i = 0; i < m_size; ++i)
	{
		cout << "| ";
		for (int j = 0; j < m_size; ++j)
		{
			cout.width(2);
			cout << matrix[n][i][j] << " ";
		}
		cout << "| " << endl;

	}
	cout << endl;
}

void add()
{
	cout << endl << "����� ����" << endl << endl;
	for (int i = 0; i < m_size; ++i)
	{
		for (int j = 0; j < m_size; ++j)
		{
			matrix[2][i][j] = matrix[0][i][j] + matrix[1][i][j];
		}
	}
	print('+');
}

void sub()
{
	cout << endl << "����� ����" << endl << endl;
	for (int i = 0; i < m_size; ++i)
	{
		for (int j = 0; j < m_size; ++j)
		{
			matrix[2][i][j] = matrix[0][i][j] - matrix[1][i][j];
		}
	}
	print('-');
}

void mul()
{
	cout << endl << "����� ����" << endl << endl;
	for (int i = 0; i < m_size; ++i)
	{
		for (int j = 0; j < m_size; ++j)
		{
			matrix[2][i][j] = calc(i, j);
		}
	}
	print('*');
}

int calc(int y,int x)
{
	int temp=0;
	for (int i = 0; i < m_size; ++i)
	{
		temp += matrix[0][y][i] * matrix[1][i][x];
	}
	return temp;
}

int det_3(int a)
{
	int ans=0;
	int temp = 1;
	for (int j = 0; j < 3; ++j)
	{
		int temp = 1;
		for (int i = 0; i < 3; ++i)
			temp *= matrix[a][i][(i + j) % 3];
		ans += temp;
	}

	for (int j = 0; j < 3; ++j)
	{
		int temp = 1;
		for (int i = 0; i < 3; ++i)
			temp *= matrix[a][i][(8 - i -j) % 3];
		ans -= temp;
	}


	return ans;
}

int det_4(int a)
{
	int ans = 0;
	int temp = 0;
	int countX = 0;
	int countY = -1;
	for (int k = 0; k < 4; ++k)
	{
		countX = 0;
		countY = -1;
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				if (i != 0 && j != k)
				{
					matrix[4][countY][countX] = matrix[a][i][j];
					countX++;
				}

			}
			countX = 0;
			countY++;
		}
		if (k % 2 == 0)
		{
			ans += matrix[a][0][k] * det_3(4);
		}
		else
			ans -= matrix[a][0][k] * det_3(4);
	}
	return ans;
}

void tra(int n)
{
	for (int i = 0; i < m_size; ++i)
	{
		for (int j = 0; j < m_size; ++j)
			matrix[3][i][j] = matrix[n][j][i];
	}
	
}