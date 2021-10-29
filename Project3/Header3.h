#include<iostream>
#include<string>
using namespace std;

class DataSIM {
private:
	string passport;
	string number;
	int dateofissue;
	int expdate;
	DataSIM* next;
	friend class List;
public:
	DataSIM();
	DataSIM(string pas, string num, int iss, int exp);
	void set(string pas, string num, int iss, int exp);
	void print();
};

class List{
private:
	DataSIM* head;
	DataSIM* temp;
public:
	List();
	~List();
	void add(DataSIM* a);
	void printall();
	bool del(string str);
	DataSIM* find(string num);
	void delall();
	bool uniq(string num);
	DataSIM* mergesort(DataSIM* c);
	DataSIM* merge(DataSIM* a, DataSIM* b);
	DataSIM* rethead();
	void withnull();
	void outnull();
	void getnumb(DataSIM* sim);
};