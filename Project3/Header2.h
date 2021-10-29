#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;

const int n = 20;  //кол-во сегментов хеш-таблицы
const int m = 11;    //длина ключа 
const int m1 = 12;    //длина ключа +1 
const int tour = 11;  //кол-во итераций поиска 
const int c = 12; //шаг при разрешении коллизии

class SIM {
private:
	string number;
	string rate;
	int year;
	int instock;
	friend class Hashtable;
	friend class List;
public:
	SIM();
	SIM(string numb, string r, int y, int in);
	void set(string numb, string r, int y, int in);
	void print();
};

class Hashtable {
private:
	SIM* table[n];
	friend class SIM;
public:
	Hashtable();
	int hashi1(string key);
	int hashi2(string key);
	bool add(SIM* s);
	short find(string numb);
	bool del(string numb);
	void print();
	void printone(int i);
	void delall();
	void showtarif(string str);
	int retinstock(string num);
	void editinstock(int i, string str);
};



