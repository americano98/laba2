#pragma once
#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include <iostream>
#include <string>
#include "HelpUtils.h"

using namespace std;

class Computer {
private:
	//Код компьютера
	int computerID;
	//Название марки компьютера
	string computername;
	//Тип процессора
	string typeofCPU;
	//Частота процессора
	double CPUfrequency;
	//Объем оперативной памяти
	int capacityRAM;
	//Объем жесткого диска
	int capacityHDD;
	//Объем памяти видеокарты
	int capacityGPU;
	//Стоимость компьютера
	double cost;
	//Количество экземпляров
	int count;


	int typesearch;
public:
	//конструктор по умолчанию
	Computer()
	{
		int computerID = 0;
		string computername = "";
		string typeofCPU = "";
		double CPUfrequency = 0;
		int capacityRAM = 0;
		int capacityHDD = 0;
		int capacityGPU = 0;
		double cost = 0;
		int count = 0;
	}

	//Код компьютера
	int ComputerID() {
		return computerID;
	}
	//Название марки компьютера
	string ComputerName() {
		return computername;
	}
	//Тип процессора
	string TypeOfCPU() {
		return typeofCPU;
	}	//Частота процессора
	double CPUFrequency() {
		return CPUfrequency;
	}
	//Объем оперативной памяти
	int CapacityRAM() {
		return capacityRAM;
	}
	//Объем жесткого диска
	int CapacityHDD() {
		return capacityHDD;
	}
	//Объем памяти видеокарты
	int CapacityGPU() {
		return capacityGPU;
	}
	//Стоимость компьютера
	double Cost() {
		return cost;
	}
	//Количество экземпляров
	int Count() {
		return count;
	}
	//сеттеры
	//Код компьютера
	void ComputerID(int value) {
		computerID = value;
	}
	//Название марки компьютера
	void ComputerName(string value) {
		computername = value;
	}
	//Тип процессора
	void TypeOfCPU(string value) {
		typeofCPU = value;
	}	//Частота процессора
	void CPUFrequency(double value) {
		CPUfrequency = value;
	}
	//Объем оперативной памяти
	void CapacityRAM(int value) {
		capacityRAM = value;
	}
	//Объем жесткого диска
	void CapacityHDD(int value) {
		capacityHDD = value;
	}
	//Объем памяти видеокарты
	void CapacityGPU(int value) {
		capacityGPU = value;
	}
	//Стоимость компьютера
	void Cost(double value) {
		cost = value;
	}
	//Количество экземпляров
	void Count(int value) {
		count = value;
	}

	int TypeSearch() {
		return typesearch;
	}
	//сеттеры
	//Код компьютера
	void TypeSearch(int value) {
		typesearch = value;
	}


	//Изменение структуры "Компьютер"
	Computer ChangeComputer(Computer &result)
	{
		int num = InputNumber(0, 9, "Что хотите изменить\n1 - ID\n2 - Name\n3 - Type Cpu\n4 - frequency\n5 - Ram\n6 - Hdd\n7 - Gpu\n8 - cost\n9 - count\n0 - exit\n");
		switch (num)
		{
		case 1:
			result.computerID = InputNumber(0, 999999, "Введите новый код компьютера (0-999.999): ");
			break;
		case 2:
			result.computername = InputInformation("Введите новое имя компьютера: ");
			break;
		case 3:
			result.typeofCPU = InputInformation("Введите новый тип процессора: ");
			break;
		case 4:
			result.CPUfrequency = InputDoubleNumber(0, 6, "Введите новую частоту процессора (0-6 ГГц): ");
			break;
		case 5:
			result.capacityRAM = InputNumber(0, 256, "Введите новый объем оперативной памяти (0-256 GB): ");
			break;
		case 6:
			result.capacityHDD = InputNumber(0, 8192, "Введите новый объем жесткого диска (0-8.192 GB): ");
			break;
		case 7:
			result.capacityGPU = InputNumber(0, 16, "Введите новый объем памяти видеокарты (0-16 GB): ");
			break;
		case 8:
			result.cost = InputDoubleNumber(0, 1000000, "Введите новую стоимость компьютера (0-1.000.000 руб.): ");
			break;
		case 9:
			result.count = InputNumber(0, 100, "Введите новое количество экземпляров (0-100 шт.): ");
			break;
		case 0:
			break;
		default:
			break;
		}
		return result;
	}

	//Перегруженный оператор равенства для структуры "Компьютер"
	Computer& operator = (Computer c)
	{
		computerID = c.computerID;
		computername = c.computername;
		typeofCPU = c.typeofCPU;
		CPUfrequency = c.CPUfrequency;
		capacityRAM = c.capacityRAM;
		capacityHDD = c.capacityHDD;
		capacityGPU = c.capacityGPU;
		cost = c.cost;
		count = c.count;

		return (*this);
	}

	//Поиск равного элемента по выбранному критерию
	bool SearchElement(Computer second)
	{
		switch (typesearch)
		{
		case 1:
			return ((*this).typeofCPU == second.typeofCPU);
		case 2:
			return ((*this).capacityRAM == second.capacityRAM);
		case 3:
			return ((*this).capacityGPU == second.capacityGPU);
		case 4:
			return ((*this).capacityHDD == second.capacityHDD);
		default:
			return false;
		}
	}
};
	//Функция ввода структуры "Компьютер" с консоли
	Computer InputScreenComputer()
	{
		Computer c;
		c.ComputerID( InputNumber(0, 999999, "Введите код компьютера (0-999.999): "));
		c.ComputerName ( InputInformation("Введите имя компьютера: "));
		c.TypeOfCPU (InputInformation("Введите тип процессора: "));
		c.CPUFrequency ( InputDoubleNumber(0, 6, "Введите частоту процессора (0-6 ГГц): "));
		c.CapacityRAM ( InputNumber(0, 256, "Введите объем оперативной памяти (0-256 GB): "));
		c.CapacityHDD ( InputNumber(0, 8192, "Введите объем жесткого диска (0-8.192 GB): "));
		c.CapacityGPU ( InputNumber(0, 16, "Введите объем памяти видеокарты (0-16 GB): "));
		c.Cost ( InputDoubleNumber(0, 1000000, "Введите стоимость компьютера (0-1.000.000 руб.): "));
		c.Count (InputNumber(0, 100, "Введите количество экземпляров (0-100 шт.): "));
		return c;
	}

	//Функция вывода структуры "Компьютер" на консоль
	void OutputScreenComputer(Computer c)
	{
		cout << "Код компьютера: " << c.ComputerID() << endl;
		cout << "Имя марки компьютера: " << c.ComputerName() << endl;
		cout << "Тип процессора: " << c.TypeOfCPU() << endl;
		cout << "Частота процессора: " << c.CPUFrequency() << " ГГц" << endl;
		cout << "Объем оперативной памяти: " << c.CapacityRAM() << " GB" << endl;
		cout << "Объем жесткого диска: " << c.CapacityHDD() << " GB" << endl;
		cout << "Объем памяти видеокарты: " << c.CapacityGPU() << " GB" << endl;
		cout << "Стоимость компьютера: " << c.Cost() << " руб." << endl;
		cout << "Количество экземпляров: " << c.Count() << " шт." << endl;
	}

	//Перевод структуры "Компьютер" в строку
	string ToString(Computer c,int i=-1)
	{
		string s="";
		if (i != -1) s = "Запись № " + to_string(i) + "\r\n";
		return s + 
			"Код компьютера: " + to_string(c.ComputerID()) + "\r\n" + 
			"Имя компьютера: " + c.ComputerName() + "\r\n" + 
			"Тип процессора: " + c.TypeOfCPU() + "\r\n" + 
			"Частота процессора (В ГГц): " + to_string(c.CPUFrequency()) + "\r\n"+ 
			"Объем оперативной памяти (В GB): " + to_string(c.CapacityRAM()) + "\r\n" + 
			"Объем жесткого диска (B GB): " + to_string(c.CapacityHDD()) + "\r\n" + 
			"Объем памяти видеокарты (B DB): " + to_string(c.CapacityGPU()) + "\r\n" +
			"Стоимость компьютера (В руб.): " + to_string(c.Cost()) + "\r\n" + 
			"Количество экземпляров (В шт.): " + to_string(c.Count()) + "\r\n";
	}

	//Считывание структуры "Компьютер" из строки
	bool ReadFromString(ifstream& input, Computer &c)
	{
		string s;
		
		try
		{
			if (!input.eof())
			{
				getline(input, s);
				if (s == "") return false;
				c.ComputerID(stoi(GetValue(s)));
			}
			else
				return false;
			if (!input.eof())
			{
				getline(input, s);
				c.ComputerName(GetValue(s));
			}
			else
				return false;
			if (!input.eof())
			{
				getline(input, s);
				c.TypeOfCPU(GetValue(s));
			}
			else
				return false;
			if (!input.eof())
			{
				getline(input, s);
				c.CPUFrequency (stoi(GetValue(s)));
			}
			else
				return false;
			if (!input.eof())
			{
				getline(input, s);
				c.CapacityRAM(stoi(GetValue(s)));
			}
			else
				return false;
			if (!input.eof())
			{
				getline(input, s);
				c.CapacityHDD(stoi(GetValue(s)));
			}
			else
				return false;
			if (!input.eof())
			{
				getline(input, s);
				c.CapacityGPU(stoi(GetValue(s)));
			}
			else
				return false;
			if (!input.eof())
			{
				getline(input, s);
				c.Cost(stoi(GetValue(s)));
			}
			else
				return false;
			if (!input.eof())
			{
				getline(input, s);
				c.Count(stoi(GetValue(s)));
			}
			else
				return false;
		}
		catch (...)
		{
			cout << "Ошибка записи в файл!" << endl;
			return false;
		}
		return true;
	}

	//Ввод критерия поиска в зависимости от выбранного типа
	Computer InputChangeTypeSearch(int typesearch)
	{
		Computer c;
		switch (typesearch)
		{
		case 1:
			c.TypeOfCPU(InputInformation("Введите тип процессора: "));
			break;
		case 2:
			c.CapacityRAM(InputNumber(0, 256, "Введите объем оперативной памяти (0-256 GB) :"));
			break;
		case 3:
			c.CapacityGPU ( InputNumber(0, 16, "Введите объем памяти видеокарты (0-16 GB): "));
			break;
		case 4:
			c.CapacityHDD ( InputNumber(0, 8192, "Введите объем жесткого диска (0-8.192 GB): "));
			break;
		}
		return c;
	}

//Сравнение структур в зависимости от выбранного поля для сортировки
int Sort(Computer first, Computer second, int typesearch)
{
	switch (typesearch)
	{
	case 1:
		if (first.TypeOfCPU() > second.TypeOfCPU()) return 1;
		else if (first.TypeOfCPU() < second.TypeOfCPU()) return -1;
		else return 0;
	case 2:
		if (first.CapacityRAM() > second.CapacityRAM()) return 1;
		else if (first.CapacityRAM() < second.CapacityRAM()) return -1;
		else return 0;
	case 3:
		if (first.CapacityGPU() > second.CapacityGPU()) return 1;
		else if (first.CapacityGPU() < second.CapacityGPU()) return -1;
		else return 0;
	case 4:
		if (first.CapacityHDD() > second.CapacityHDD()) return 1;
		else if (first.CapacityHDD() < second.CapacityHDD()) return -1;
		else return 0;
	default:
		return -2;
	}
};