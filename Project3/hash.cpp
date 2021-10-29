#include"Header2.h"

/////////////////////////////////////////////////////////////////////////

SIM::SIM() {
	number = "000-0000000";
	rate = "0";
	year = 2020;
	instock = 0;
}

SIM::SIM(string numb, string r, int y, int in) {
	number = numb;
	rate = r;
	year = y;
	instock = in;
}

void SIM::set(string numb, string r, int y, int in) {
	number = numb;
	rate = r;
	year = y;
	instock = in;
}

void SIM::print() {
	cout << "Номер SIM-карты :" << number << endl;
	cout << "Тариф: " << rate << endl;
	cout << "Год выпуска :" << year << endl;
	cout << "Наличие :" << instock << endl;
}

/////////////////////////////////////////////////////////////////////////////

Hashtable::Hashtable() {
	for (int i = 0; i < n; i++) {
		table[i] = nullptr;
	}
}

int Hashtable::hashi1(string key) {
	long rez = 0;
	for (int i = 0; i < m; i++)
		rez += pow(double(key[i]), 2);
	rez = (rez % n) +1;
	return rez;
}

int Hashtable::hashi2(string key) {
	long rez = 0;
	for (int i = 0; i < m; i++)
		rez += pow(double(key[i]), 3);
	rez %= n;
	return rez;
}

bool Hashtable::add(SIM* s) {
	int id;
	id = hashi1(s->number)% n;
	for (int i = 0; i < n; i++) {
		if (table[id] != nullptr)
			if ((table[id]->number != s->number) && table[id]->number != "Udalen______") {
			id = (id + (hashi2(s->number)) * i) %n;
			}
		if (table[id] != nullptr)
			if (table[id]->number == s->number) {
				return true;
			}
		if (id >= n)
			break;
		if (table[id] == nullptr || table[id]->number == "Udalen______") {
			table[id] = s;
			return true;
		}
	}
	return false;
}

short Hashtable::find(string numb) {
	int id;
	for (unsigned long i = 0; i < n; i++) {
		id = (hashi1(numb) + i * hashi2(numb)) % n;
		if (table[id] == nullptr)
			return -1;
		if (table[id]->number == numb)
			return id;
	}
	return -1;
}

bool Hashtable::del(string numb) {
	if (find(numb) == -1)
		return false;
	int i = find(numb);
	table[i]->number = "Udalen______";
	table[i]->rate = "Udalen______";
	table[i]->year = 0;
	table[i]->instock = 0;
	return true;
}

void Hashtable::printone(int i) {
	table[i]->print();
}

void Hashtable::print() {
	for (int i = 0; i < n; i++) {
		cout << i << ":     " << endl;
		if (table[i] != nullptr){
			table[i]->print();
		}
		else {
			cout << endl;
		}
	}
}

void Hashtable::delall() {
	for (int i = 0; i < n; i++) {
		table[i] = nullptr;
	}
}

void Hashtable::showtarif(string str) {
	for (int i = 0; i < n; i++) {
		if (table[i] != nullptr) {
			if (table[i]->rate == str) {
				table[i]->print();
			}
		}
	}
}

int Hashtable::retinstock(string num) {
	if (find(num) == -1) {
		return -1;
	}
	if (table[find(num)]->instock == 0) {
		return 0;
	}
	else
		return 1;
}

void Hashtable::editinstock(int i, string str) {
	if (find(str) == -1) {
		return;
	}
	table[find(str)]->instock = i;
}