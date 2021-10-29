#include<iostream>
#include<string>
using namespace std;


class client {
private:
	string passport;
	string place;
	string date;
	string fullname;
	int birthyear;
	string address;
	client* right;
	client* left;
	int depth;
	unsigned char _height;
	friend class DataSIM;
public:
	client();
	~client();
	void set(client* a);
	void set(string pas, string pl, string dat, string full, int year, string addr);
	void show();
	string returnnum();
	client* retright();
	//////////////////////////////////////////////////////////////////////////////////////
	client* remove(client* h, string k);//удаление элемента с номером к
	client* findmin(client* h);// поиск минимального в поддереве h
	client* removemin(client* h);// удаление минимального в поддереве h
	client* rotateright(client* h); // правый большой поворот
	client* rotateleft(client* q); // левый большой поворот
	client* balance(client* h); // балансировка дерева
	void del(client*&h);// удаление всего дерева
	unsigned char height(client* p);// высота элемента
	void fixdepth(client* p);
	client* find(client*head, string data);
	void showtree(client *h);
	void bypass(client *p);
	void fixheight(client* p);
	void add(client *&h, client *added);
	int bfactor(client* p);
	int AlgSearch(string str, string substr);
	void search(client* h, string substr);
};
