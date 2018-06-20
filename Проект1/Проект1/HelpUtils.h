#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <istream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

template <class Type>
Type InputNumber(Type min, Type max, string message)
{
	Type n;
	do
	{
		cout << message;
		while ((!(cin >> n)) || (cin.get() != '\n'))
		{
			cout << "Неправильный ввод! Повторите ввод\n";
			cin.clear(); //Восстанавливает поток, если он в ошибочном состоянии
			cin.sync(); //Очищает поток от имеющихся символов
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << message;
		}
	} while ((n < min) || (n > max));
	return n;
}

double InputDoubleNumber(int min, int max, string message)
{
	double n;
	do
	{
		cout << message;
		while ((!(cin >> n)) || (cin.get() != '\n'))
		{
			cout << "Неправильный ввод! Повторите ввод\n";
			cin.clear(); //Восстанавливает поток, если он в ошибочном состоянии
			cin.sync(); //Очищает поток от имеющихся символов
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << message;
		}
	} while ((n < min) || (n > max));
	return n;
}

//Ввод информации
string InputInformation(string message)
{
	string a, result;
	cout << message;
	do {
		cin >> a;
		result = result + ' ' + a;
	} while (cin.get() != '\n');
	return result;
}

//Проверка символа на корректность в имени файла
bool CorrectSymbol(char c)
{
	switch (c)
	{
	case '.':
	case '*':
	case '?':
	case '<':
	case '>':
	case ':':
	case '|':
	case '/':
	case '\\':
		return false;
	default:
		return true;
	}
}

//Проверка имени файла на корректность
bool CorrectName(string name)
{
	int i = 0;
	bool check = true;
	for (int i = 0; (i < name.length() && check); i++)
	{
		check = CorrectSymbol(name[i]);
	}
	return check;
}

string GetValueOfStr(ifstream& input)
{
	string s;
	if (!input.eof())
	{
		getline(input, s, '\n');
		int pos = s.find(':');
		string str = s.substr(pos, s.length()).c_str();
		return str;
	}
}

string GetValue(string str) {
	int pos = str.find(':');
	auto s = str.begin() + pos + 1;
	while (isspace(*s)) s++;
	auto f = str.end();
	while (isspace(*(f-1))) f--;
	string res;
	res.assign(s, f);
	return res;
}

//Ввод имени файла
string InputFileName()
{
	string filename;
	do
	{
		cout << "Введите имя файла (не более 32 символов): ";
		cin >> filename;
		if (filename.length() > 32)
		{
			filename.erase(filename.begin(), filename.begin() + 32);
		}
		if (CorrectName(filename))
		{
			break;
		}
		else
			cout << "Неверное имя файла\n";
	} while (true);
	return filename+".txt";
}