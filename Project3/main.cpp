#include"Header1.h"
#include"Header2.h"
#include"Header3.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	bool yet = 1;
	string arg1, arg2, arg3, arg4, arg5;
	client* temp;
	int argint1, argint2, n1=0;
	int argbool;
	int n;
	Hashtable HT;
	client* head;
	List list;
	head = nullptr;;
	while (yet) {
		system("cls");
		cout << "�������:\n1, ���� ������ �������� � SIM �������\n" <<
			"2, ���� ������ �������� � ���������\n" <<
			"3, ���� ������ �������� � ������� � ������� � SIM-������\n" <<
			"4, ���� ������ ���������� ������ ���������\n";
		cin >> n;
		switch (n) {
		case(1):
			system("cls");
			n1 = 0;
			while (n1 != 7) {
				cout << "������� :\n" <<
					"1, ���� ������ �������� SIM-�����\n" <<
					"2, ���� ������ ������� SIM-�����\n" <<
					"3, ���� ������ ������� ������ � SIM-�����\n" <<
					"4, ���� ������ ������� ��� �������\n" <<
					"5, ���� ������ ������� ��� ������ �� �������\n" <<
					"6, ���� ������ ������� ��� SIM-����� � ������ �������\n" <<
					"7, ���� ������ ��������� ������ � ���-��������\n";
				cin >> n1;
				cin.ignore();
				switch (n1) {
				case 1:
					SIM* sim;
					sim = new SIM;
					cout << "������� ����� SIM-����� � ������� NNN-NNNNNNN" << endl;
					getline(cin,arg1);
					cout << "������� ����� SIM-�����" << endl;
					getline(cin, arg2);
					cout << "������� ��� ������� SIM-�����" << endl;
					cin >> argint1;
					cin.ignore();
					cout << "������� 0 ���� ����� SIM-����� �� ��������, � ����� ������ �����, ���� ��������" << endl;
					cin >> argbool;
					cin.ignore();
					sim->set(arg1, arg2, argint1, argbool);
					if (HT.add(sim)) {
						cout << "SIM-����� ���������" << endl;
					}
					else {
						cout << "������� ���������" << endl;
					}
					break;
				case 2:
					cout << "������� ����� SIM-����� � ������� NNN-NNNNNNN, ������� ������ �������" << endl;
					getline(cin, arg1);
					HT.del(arg1);
					break;
				case 3:
					cout << "������� ����� SIM-����� � ������� NNN-NNNNNNN, ������ ������� ������ �������" << endl;
					getline(cin, arg1);
					if (HT.find(arg1) != -1)
						HT.printone(HT.find(arg1));
					else
						cout << "����� SIM-����� �� �������" << endl;
					break;
				case 4:
					HT.print();
					break;
				case 5:
					HT.delall();
					cout << "������� �������" << endl;
					break;
				case 6:
					cout << "������� �����, SIM-����� � ������� ������ �����" << endl;
					getline(cin, arg1);
					HT.showtarif(arg1);
					break;
				}
			}
			break;
		case(2):
			system("cls");
			n1 = 0;
			while (n1 != 7) {
				cout << "������� : \n" <<
					"1, ���� ������ �������� �������\n" <<
					"2, ���� ������ ������� �������\n" <<
					"3, ���� ������ ������� ������ ��������\n" <<
					"4, ���� ������ ������� ������ �������\n" <<
					"5, ���� ������ ������� ���� ��������\n" <<
					"6, ���� ������ ����������� ����� �� ��� � ������\n" <<
					"7, ���� ������ ��������� ������ � �������\n";
				cin >> n1;
				cin.ignore();
				switch (n1) {
				case(1):
					cout << "������� ����� �������� � ������� NNNN-NNNNNN" << endl;
					getline(cin, arg1);
					cout << "������� ����� ����������" << endl;
					getline(cin, arg2);
					cout << "������� ���� ��������� ��������" << endl;
					getline(cin, arg3);
					cout << "������� ������ ��� � �������" << endl;
					getline(cin, arg4);
					cout << "������� ��� ��������" << endl;
					cin >> argint1;
					cin.ignore();
					cout << "������� �����" << endl;
					getline(cin, arg5);
					temp = new client;
					temp->set(arg1, arg2, arg3, arg4, argint1, arg5);
					head->add(head, temp);
					break;
				case 2:
					cout << "������� ����� �������� �������, �������� �� ������ �������, � ������� NNNN-NNNNNN" << endl;
					getline(cin, arg1);
					client* cl;
					cl = nullptr;
					bool flag;
					flag = 0;
					if (head->find(head, arg1) != nullptr)
						head = head->remove(head, arg1);
					else
						cout << "�������� �� �������" << endl;
					if (flag == 1) {
						head = cl;
					}
					break;
				case 3:
					head->showtree(head);
					break;
				case 4:
					cout << "������� ����� �������� � ������� NNNN-NNNNNN" << endl;
					getline(cin, arg1);
					head->find(head, arg1)->show();
					break;
				case 5:
					head->del(head);
					cout << "�������� �����������" << endl;
					break;
				case 6:
					cout << "������� ������ ��������, ������� �� ������ �����" << endl;
					getline(cin, arg1);
					head->search(head, arg1);
					break;
				}
			}
			break;
		case(3):
			system("cls");
			n1 = 0;
			while (n1 != 7) {
				cout << "������� : \n" <<
					"1, ���� ������ ���������������� SIM-�����\n" <<
					"2, ���� ������ ���������� ������������ SIM-�����\n" <<
					"3, ���� ������ ������� ������ � ����������� SIM-�����\n" <<
					"4, ���� ������ ������� ���� ������\n" <<
					"5, ���� ������ ������� ���� ������\n" <<
					"6, ���� ������ ������������� ������\n" <<
					"7, ���� ������ ��������� ������ �� �������\n";
				cin >> n1;
				cin.ignore();
				switch (n1) {
				case(1):
					cout << "������� ����� �������� ��������� � ������� NNNN-NNNNNN " << endl;
					getline(cin, arg1);
					while (head->find(head, arg1) == nullptr) {
						cout << "������ ����������. �������� ����. " << endl;
						getline(cin, arg1);
					}
					cout << "������� ����� SIM-����� � ������� NNN-NNNNNNN" << endl;
					getline(cin, arg2);
					while (HT.retinstock(arg2)!=1) {
						cout << "SIM-����� ����������. ��������� ����" << endl;
						getline(cin, arg2);
					}
					cout << "������� ���� ������������" << endl;
					cin >> argint1;
					cin.ignore();
					cout << "������� ���� �� ������� ����� �����" << endl;
					cin >> argint2;
					cin.ignore();
					DataSIM* t;
					t = new DataSIM;
					t->set(arg1, arg2, argint1, argint2);
					list.add(t);
					HT.editinstock(0, arg2);
					break;
				case(2):
					cout << "������� ����� SIM-����� � ������� NNN-NNNNNNN" << endl;
					getline(cin, arg1);
					if (list.del(arg1) == 0) {
						cout << "������� �� ������" << endl;
					}
					else {
						cout << "������� ������" << endl;
						HT.editinstock(1, arg2);
					}
					break;
				case(3):
					cout << "������� ����� SIM-����� � ������� NNN-NNNNNNN, ������ ������� ������ �������" << endl;
					getline(cin, arg1);
					if (list.find(arg1) != nullptr)
						list.find(arg1)->print();
					else cout << "SIM-����� � ����� ������� �� ����������" << endl;
					break;
				case(4):
					list.printall();
					break;
				case(5):
					list.delall();
					break;
				case(6):
					list.withnull();
					list.getnumb(list.mergesort(list.rethead()));
					list.outnull();
					break;
				}
			}
			break;
		case(4):
			yet = 0;
			system("cls");
			cout << "���� ���� ������" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}