#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int height = 0;
bool isSet = false;

void print();
void findFar();
void findClose();
void arrSet();

struct point
{
	int x;
	int y;
	int z;
	int dis;
};

deque<point>arr;
deque<point>arrFake;

int main()
{
	char input='a';
	int tempInput;
	print();
	while (input != 'q')
	{
		cout << "+:�����߰� -:������ e:�Ʒ��߰� d:�Ʒ����� l:���ǰ��� c:���� m:����հ� n:���尡���� s:����" << endl;
		cin >> input;
		system("cls");

		if (input == '+')
		{
			if(arr.size()>=10)
			{

				print();
				cout << "���̻� �߰��Ҽ� �����ϴ�" << endl;

			}
			else if (arr.size()+height < 10)
			{
				point tempPoint;
				cout << "x ���� �Է��ϼ���: ";
				cin >> tempInput;
				tempPoint.x = tempInput;

				cout << "y ���� �Է��ϼ���: ";
				cin >> tempInput;
				tempPoint.y = tempInput;

				cout << "z ���� �Է��ϼ���: ";
				cin >> tempInput;
				tempPoint.z = tempInput;

				tempPoint.dis = tempPoint.x * tempPoint.x + tempPoint.y * tempPoint.y + tempPoint.z * tempPoint.z;

				arr.push_back(tempPoint);
				print();
			}
			else if (arr.size() + height == 10)
			{
				point tempPoint;
				cout << "x ���� �Է��ϼ���: ";
				cin >> tempInput;
				tempPoint.x = tempInput;

				cout << "y ���� �Է��ϼ���: ";
				cin >> tempInput;
				tempPoint.y = tempInput;

				cout << "z ���� �Է��ϼ���: ";
				cin >> tempInput;
				tempPoint.z = tempInput;

				tempPoint.dis = tempPoint.x * tempPoint.x + tempPoint.y * tempPoint.y + tempPoint.z * tempPoint.z;

				arr.push_front(tempPoint);
				if(height>0)
				height--;
				print();
			}
			
		}

		else if (input == '-')
		{
			if (!arr.empty())
			{
				arr.pop_back();
				print();
			}
		}

		else if (input == 'e')
		{
			if (arr.size() < 10)
			{
				point tempPoint;
				cout << "x ���� �Է��ϼ���: ";
				cin >> tempInput;
				tempPoint.x = tempInput;

				cout << "y ���� �Է��ϼ���: ";
				cin >> tempInput;
				tempPoint.y = tempInput;

				cout << "z ���� �Է��ϼ���: ";
				cin >> tempInput;
				tempPoint.z = tempInput;

				tempPoint.dis = tempPoint.x * tempPoint.x + tempPoint.y * tempPoint.y + tempPoint.z * tempPoint.z;

				arr.push_front(tempPoint);

				if(height>0)
				height--;

				print();
			}
			else if(arr.size() >= 10)
			{

				print();
				cout << "���̻� �߰��Ҽ� �����ϴ�" << endl;

			}

		}

		else if (input == 'd')
		{
			arr.pop_front();
			height++;
			print();
		}

		else if (input == 'l')
		{
			print();
			cout << "����Ʈ����: " << arr.size()<<endl;
		}
		else if (input == 'c')
		{
			arr.clear();
			height = 0;
			print();
		}
		else if (input == 'm')
		{
			print();
			findFar();
		}
		else if (input == 'n')
		{
			print();
			findClose();
		}
		else if (input == 's')
		{
			arrFake.clear();
			for (int i = 0; i < arr.size();++i)
			{
				arrFake.push_back(arr[i]);
			}

			arrSet();
			if (!isSet)
				isSet = true;
			else
				isSet = false;
			print();
			
		}

		
	}
	
}

void print()
{
	if (!isSet)
	{
		for (int i = 9; i >= 0; --i)
		{
			cout << i << " : ";
			if (i < arr.size() + height && i >= height)
			{
				cout << arr[i - height].x << " " << arr[i - height].y << " " << arr[i - height].z << endl;
			}
			else
			{
				cout << "empty" << endl;
			}
		}
	}
	else
	{
		for (int i = 9; i >= 0; --i)
		{
			cout << i << " : ";
			if (i < arrFake.size())
			{
				cout << arrFake[i].x << " " << arrFake[i].y << " " << arrFake[i].z << endl;
			}
			else
			{
				cout << "empty" << endl;
			}
		}
	}
}

void findFar()
{
	int temp=-1;
	int num=-1;
	for (int i = 0; i < arr.size(); ++i)
	{
		if (temp < arr[i].dis)
		{
			temp = arr[i].dis;
			num = i;
		}
	}
	if(num!=-1)
		cout << "���� �� ��ǥ�� " << num +height<< " ��ġ�� �ִ� ��:" << arr[num].x << " " << arr[num].y << " " << arr[num].z << endl;
}

void findClose()
{
	int temp = 987654321;
	int num = -1;
	for (int i = 0; i < arr.size(); ++i)
	{
		if (temp > arr[i].dis)
		{
			temp = arr[i].dis;
			num = i;
		}
	}
	if (num != -1)
		cout << "���� ����� ��ǥ�� " << num+height << " ��ġ�� �ִ� ��:" << arr[num].x << " " << arr[num].y << " " << arr[num].z << endl;
}

void arrSet()
{
	sort(arrFake.begin(), arrFake.end(), [](point a, point b) {
		if (a.dis > b.dis) {
			return true;
		}
		else {
			return false;
		}

		});

}
