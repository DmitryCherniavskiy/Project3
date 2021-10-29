#include"Header1.h"

client::client() {
	passport = " ";
	place = " ";
	date = " ";
	fullname = " ";
	birthyear = 0;
	address = " ";
	right = nullptr;
	left = nullptr;
	depth = 0;
	_height = 1;
}

client::~client() {
}

void client::set(client* a) {
	passport = a->passport;
	place = a->place;
	date = a->date;
	fullname = a->fullname;
	birthyear = a->birthyear;
	address = a->address;
	right = nullptr;
	left = nullptr;
	_height = 1;
}

void client::set(string pas, string pl, string dat, string full, int year, string addr) {
	passport = pas;
	place = pl;
	date = dat;
	fullname = full;
	birthyear = year;
	address = addr;
	right = nullptr;
	left = nullptr;
	depth = 0;
}

void client::show() {
	cout << "����� ��������:" << passport << endl
		<< "����� ���������: " << place << endl
		<< "���� ���������: " << date << endl
		<< "���: " << fullname << endl
		<< "��� ��������: " << birthyear << endl
		<< "�����: " << address << endl << endl;
}

string client::returnnum() {
	return passport;
}

client* client::retright() {
	return right;
}

//////////////////////////////////////////////////////////////////////////

void client::del(client* &h) {
	if (h != nullptr) {
		del(h->left);
		del(h->right);
		delete h;
		h = nullptr;
	}
}

unsigned char client::height(client* p)
{
	return p ? p->_height : 0;
}

//������ ����(������)
void client::fixdepth(client* p)
{
	if (p) {
		if (p->right) {
			p->right->depth = p->depth + 1;
			fixdepth(p->right);
		}
		if (p->left) {
			p->left->depth = p->depth + 1;
			fixdepth(p->left);
		}
	}
}

client* client::find(client* head, string data) {
	client *a, *b;
	if (head == nullptr) {
		return nullptr;
	}
	if (head->passport == data) {
		return head;
	}
	else {
		a = find(head->right, data);
		b = find(head->left, data);
		if (a == nullptr) {
			return b;
		}
		else return a;
	}
}

void client::showtree(client *h) {
	if (h == nullptr)    return;    //���� ������ ���, �������
	h->show(); //�������� ����
	if (h->left != nullptr)
	cout << "����� ���������" << endl;
	h->left->showtree(h->left); //������ ����� ��������� 
	if (h->right != nullptr)
	cout << "������ ���������" << endl;
	h->right->showtree(h->right); //������ ������ ���������
};

void client::bypass(client *p) //������ ������� ������
{
	if (p != NULL)
	{
		std::cout << p->passport << "\t";
		bypass(p->left);
		bypass(p->right);
	}
}
//
void client::fixheight(client* p)//
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->_height = (hl > hr ? hl : hr) + 1;
}

void client::add(client *&h, client* added) {
	if (h == nullptr) {
		client *head = new client;
		head->set(added);
		head->right = nullptr;
		head->left = nullptr;
		h = head;
		return;
	}
	if (added->passport < h->passport)
		add(h->left, added);
	if (added->passport > h->passport)
		add(h->right,added);
	if (added->passport == h->passport)
		cout << "����� ������� ��� ����" << endl;
	h = balance(h);
}

int client::bfactor(client* p)
{
	return height(p->right) - height(p->left);
}

client* client::remove(client* h, string k) // �������� ����� k �� ������ h
{
	if (h == nullptr)
		return nullptr;
	
	if (k < h->passport)
		h->left = remove(h->left, k);
	else if (k > h->passport)
		h->right = remove(h->right, k);
	else // k == h->key
	{
		client* q = h->left;
		client* r = h->right;
		delete h;
		if (r == nullptr) return q;
		client* min = findmin(r);
		min->right = removemin(r);
		min->left = q;
		min = balance(min);
		return min;
	}
	return balance(h);
}

client* client::rotateright(client* p) // ������ ������� ������ p
{
	client* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

client* client::rotateleft(client* q) // ����� ������� ������ q
{
	client* p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

client* client::balance(client* p) // ������������ ���� p
{
	fixheight(p);
	if (bfactor(p) == 2)
	{
		if (bfactor(p->right) < 0)
			p->right = rotateright(p->right);
		return rotateleft(p);
	}
	if (bfactor(p) == -2)
	{
		if (bfactor(p->left) > 0)
			p->left = rotateleft(p->left);
		return rotateright(p);
	}
	return p; // ������������ �� �����
}

client* client::findmin(client* h) // ����� ���� � ����������� ��������� � ������ h
{
	return h->left ? findmin(h->left) : h;
}

client* client::removemin(client* h) // �������� ���� � ����������� ��������� �� ������ h
{
	if (h->left == nullptr)
		return h->right;
	h->left = removemin(h->left);
	return balance(h);
}

int client::AlgSearch(string str, string substr) {
	int sl, ssl;
	int res = -1;
	sl = str.length();
	ssl = substr.length();
	if (sl == 0)
		cout << "������� ������ ������\n";
	else if (ssl == 0)
		cout << "������� ������ ���������\n";
	else
		for (int i = 0; i < sl - ssl + 1; i++)
			for (int j = 0; j < ssl; j++)
				if (substr[j] != str[i + j])
					break;
				else if (j == ssl - 1) {
					res = i;
					break;
				}
	return res;
}

void client::search(client* h, string substr) {
	if (h == nullptr)    return;  //���� ������ ���, �������
	if ((h->AlgSearch(h->address,substr) != -1)||(h->AlgSearch(h->fullname, substr)!= -1))
		h->show(); //�������� ����
	if (h->left != nullptr)
	h->left->search(h->left, substr); //������ ����� ��������� 
	if (h->right != nullptr)
	h->right->search(h->right, substr);
}