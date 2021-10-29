#include"Header3.h"

/////////////////////////////////////////////////////////////

DataSIM::DataSIM() {
	passport = "0";
	number = "0";
	dateofissue = 0;
	expdate = 0;
}

DataSIM::DataSIM(string pas, string num, int iss, int exp) {
	passport = pas;
	number = num;
	dateofissue = iss;
	expdate = exp;
}

void DataSIM::set(string pas, string num, int iss, int exp) {
	passport = pas;
	number = num;
	dateofissue = iss;
	expdate = exp;
}

void DataSIM::print() {
	cout << "Номер паспорта :" << passport << endl;
	cout << "Номер SIM-карты :" << number << endl;
	cout << "Дата изготовления :" << dateofissue << endl;
	cout << "Дата окончания действия :" << expdate << endl;
}

///////////////////////////////////////////////////////////////

List::List() {
	head = nullptr;
	temp = head;
}

List::~List() {
	this->delall();
}

void List::printall() {
	if (head == nullptr) return;
	head->print();
	cout << endl;
	temp = head->next;
	while (temp != head) {
		temp->print();
		cout << endl;
		temp = temp->next;
	}
}

void List::add(DataSIM* a) {
	if (head == nullptr) {
		head = a;
		head->next = head;
	}
	else {
		temp = head;
		while (temp->next != head) {
			temp = temp->next;
		}
		temp->next = a;
		a->next = head;
	}
}

bool List::del(string str) {
	if (head->number == str) {
		if (head->next == head) {
			delete head;
			head = nullptr;
			return 1;
		}
		else {
			DataSIM* tempend;
			tempend = head;
			temp = head->next;
			while (tempend->next != head) {
				tempend = tempend->next;
			}
				delete head;
				head = temp;
				tempend->next = temp;
				return 1;
		}
	}
	else {
		DataSIM* temp2;
		temp2 = head;
		temp = head->next;
		while (temp->number != str && temp !=head ) {
			temp2 = temp;
			temp = temp->next;
		}
		temp2->next = temp->next;
		delete temp;
		return 1;
	}
	return 0;
}

DataSIM* List::find(string str) {
	temp = head;
	while (temp->number != str) {
		temp = temp->next;
		if (temp == head) {
			return nullptr;
		}
	}
	return temp;
}

void List::delall() {
	if (head != nullptr) {
		while (head->next != head) {
			temp = head->next;
			head->next = temp->next;
			delete temp;
		}
		delete head;
		head = nullptr;
		temp = nullptr;
	}
}

//1 если значение уникально, 0 если нет
bool List::uniq(string str) {
	if (head == nullptr) {
		return 1;
	}
	temp = head;
	while (temp->number != str) {
		if (temp->number == str) {
			return 0;
		}
		if (temp->next == head) {
			return 1;
		}
		temp = temp->next;
	}
}

DataSIM* List::mergesort(DataSIM* c)
{
	if (c == nullptr || c->next == nullptr)
		return c;
	DataSIM* a = c;
	DataSIM* b = c->next;
	while ((b != nullptr) && (b->next != nullptr))
	{
		c = c->next;
		b = b->next->next;
	}
	b = c->next;
	c->next = nullptr;
	return merge(mergesort(a), mergesort(b));
}

DataSIM* List::merge(DataSIM* a, DataSIM* b)// сляние списков a и b
{
	DataSIM dummy;
	DataSIM* h = &dummy;
	DataSIM* c = h;
	while ((a != nullptr) && (b != nullptr))
		if (a->number < b->number)
		{
			c->next = a; c = a; a = a->next;
		}
		else
		{
			c->next = b; c = b; b = b->next;
		}
	c->next = (a == nullptr) ? b : a;
	return h->next;
}

DataSIM* List::rethead() {
	return head;
}

void List::withnull() {
	temp = head;
	while (temp->next != head) {
		temp = temp->next;
	}
	temp->next = nullptr;
}

void List::outnull() {
	temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next = head;
}

void List::getnumb(DataSIM* sim) {
	head = sim;
}
