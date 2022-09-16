#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
using namespace std;

int line_num = 0;
int word_num = 0;
int num_num = 0;
int capital_num = 0;

bool isOnE = false;

char input='a';
string deleteStr;
string newStr;
string line[100];
vector<string> numb;
vector<string> capital;
vector<string> palindrome;
ifstream file("data.txt");

void load_file();
void word_counter();
void reverse();
void word_reverse();
void palindrome_func();

int main() {
	load_file();
	word_counter();
	while (input != 'q')
	{
		cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
		cout << "d:문장뒤집기 e:@넣기 f:단어별 뒤집기 g:문자열바꾸기 h:회문축소판 찾기 q:프로그램 종료" << endl;
		cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
		cout << "명령어를 입력하세요: ";
		cin >> input;
		system("cls");
		

		if (input == 'd')
		{
			reverse();
		}
		else if (input == 'e')
		{
			if (!isOnE)
				isOnE = true;
			else
				isOnE = false;
			word_counter();
		}
		else if (input == 'f')
		{
			word_reverse();
		}
		else if (input == 'g')
		{
			word_counter();
			cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
			cout << "무엇을 바꿀까요?: ";
			cin >> deleteStr;
			cout << "무엇으로 바꿀까요?: ";
			cin >> newStr;
			for (int i = 0; i < line_num; ++i)
			{
				line[i]=regex_replace(line[i], regex(deleteStr), newStr);
			}
			system("cls");
			word_counter();
		}
		else if (input == 'h')
		{
			palindrome_func();
		}
	}

}

void load_file()
{
	if (file.is_open()) {
		while (getline(file, line[line_num])) {
			line_num++;
		}
		file.close();
	}
	else {
		cout << "Unable to open file";
	}
}

void word_counter()
{
	int eCount = 0;
	string temp_str;
	char prior_char = 'a';
	bool isWord = false;
	bool isCapital = false;
	word_num = 0;
	num_num = 0;
	capital_num = 0;
	numb.clear();
	capital.clear();
	

	for (int i = 0; i < line_num; ++i)
	{
		for (int j = 0; j < line[i].length(); ++j)
		{
			if (line[i][j] != ' ')
			{
				if (int(line[i][j]) < 48 || int(line[i][j]) > 57)
					isWord = true;

				if (int(line[i][j]) >= 65 && int(line[i][j]) <= 90)
					isCapital = true;

				temp_str += line[i][j];
			}

			if ((prior_char != ' ' && line[i][j] == ' ') || (j==line[i].length()-1 && prior_char != ' '))
			{
				if (!isWord)
				{
					num_num++;
					numb.push_back(temp_str);
				}
				if (isCapital)
				{
					capital_num++;
					capital.push_back(temp_str);
				}
				temp_str = "";
				isWord = false;
				isCapital = false;
			}
			
			if (prior_char == ' ' && line[i][j] != ' ')
			{
				word_num++;
			}
			prior_char = line[i][j];
		}
		prior_char = 'a';
	}
	for (int i = 0; i < line_num; ++i)
	{
		for (int j = 0; j < line[i].size(); ++j)
		{
			cout << line[i][j];
			eCount++;
			if (eCount % 3 == 0 && eCount != 0 && isOnE)
			{
				cout << "@@";
			}
		}
		cout << endl;
	}


	cout << endl << "word count: " << word_num << endl << endl;
	cout  << "num count: " << num_num << endl;
	cout << "( ";
	for (int i = 0; i < numb.size(); ++i)
	{
		if (i % 10 == 0 && i != 0)
			cout << endl;
		cout << numb[i]<<" ";
	}
	cout << ")" << endl << endl;
	cout << "capital count: " << capital_num << endl;
	cout << "( ";
	for (int i = 0; i < capital.size(); ++i)
	{
		if (i % 10 == 0 && i != 0)
			cout << endl;
		cout << capital[i] << " ";
		
	}
	cout << ") " << endl;
}

void reverse()
{
	string temp_str;
	for (int i = 0; i < line_num; ++i)
	{
		temp_str = "";
		for (int j = line[i].size() - 1; j >= 0; --j)
		{
			temp_str += line[i][j];
		}
		line[i] = temp_str;
	}
	word_counter();
}

void word_reverse()
{
	string temp_str="";
	char prior_char = 'a';
	
	for (int i = 0; i < line_num; ++i)
	{
		temp_str = "";
		for (int j = 0; j < line[i].size(); ++j)
		{
			if (line[i][j] != ' ')
			{
				temp_str += line[i][j];
			}

			if ((prior_char != ' ' && line[i][j] == ' '))
			{
				for (int k = 0; k < temp_str.size(); ++k)
				{
					line[i][j-k-1] = temp_str[k];
				}
				temp_str = "";
			}

			if ((j == line[i].length() - 1 && prior_char != ' '))
			{
				for (int k = 0; k < temp_str.size(); ++k)
				{
					line[i][j - k] = temp_str[k];
				}
				temp_str = "";
			}
			prior_char = line[i][j];
			
		}
		prior_char = 'a';
	}
	
	word_counter();
}

void palindrome_func()
{
	for (int i = 0; i < line_num; ++i)
	{
		bool isSame = true;
		cout << line[i] << " :";
		for (int j = 0; j < line[i].size(); ++j)
		{
			if (j >= line[i].size() - j - 1)
				break;

			if (line[i][0] != line[i][line[i].size() - 1])
			{
				cout << 0 ;
				break;
			}

			if (line[i][j] != line[i][line[i].size() - 1 - j])
			{
				break;
			}

			if(line[i][j]!=' ')
				cout << line[i][j];
		}
		cout << endl << endl;
	}
}