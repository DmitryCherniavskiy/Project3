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
		cout << "Введите:\n1, если хотите работать с SIM картами\n" <<
			"2, если хотите работать с клиентами\n" <<
			"3, если хотите работать с данными с данными о SIM-картах\n" <<
			"4, если хотите прекратить работу программы\n";
		cin >> n;
		switch (n) {
		case(1):
			system("cls");
			n1 = 0;
			while (n1 != 7) {
				cout << "Введите :\n" <<
					"1, если хотите добавить SIM-карту\n" <<
					"2, если хотите удалить SIM-карту\n" <<
					"3, если хотите вывести данные о SIM-карте\n" <<
					"4, если хотите вывести всю таблицу\n" <<
					"5, если хотите удалить все данные из таблицы\n" <<
					"6, если хотите увидеть все SIM-карты с данным тарифом\n" <<
					"7, если хотите закончить работу с хеш-таблицей\n";
				cin >> n1;
				cin.ignore();
				switch (n1) {
				case 1:
					SIM* sim;
					sim = new SIM;
					cout << "Введите номер SIM-карты в формате NNN-NNNNNNN" << endl;
					getline(cin,arg1);
					cout << "Введите тариф SIM-карты" << endl;
					getline(cin, arg2);
					cout << "Введите год выпуска SIM-карты" << endl;
					cin >> argint1;
					cin.ignore();
					cout << "Введите 0 если такая SIM-картв не доступна, и любое другое число, если доступна" << endl;
					cin >> argbool;
					cin.ignore();
					sim->set(arg1, arg2, argint1, argbool);
					if (HT.add(sim)) {
						cout << "SIM-карта добавлена" << endl;
					}
					else {
						cout << "Таблица заполнена" << endl;
					}
					break;
				case 2:
					cout << "Введите номер SIM-карты в формате NNN-NNNNNNN, которую хотите удалить" << endl;
					getline(cin, arg1);
					HT.del(arg1);
					break;
				case 3:
					cout << "Введите номер SIM-карты в формате NNN-NNNNNNN, данные которой хотите увидеть" << endl;
					getline(cin, arg1);
					if (HT.find(arg1) != -1)
						HT.printone(HT.find(arg1));
					else
						cout << "Такой SIM-карты не найдено" << endl;
					break;
				case 4:
					HT.print();
					break;
				case 5:
					HT.delall();
					cout << "Таблица очищена" << endl;
					break;
				case 6:
					cout << "Введите тариф, SIM-карты с которым хотите найти" << endl;
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
				cout << "Введите : \n" <<
					"1, если хотите добавить клиента\n" <<
					"2, если хотите удалить клиента\n" <<
					"3, если хотите вывести дерево клиентов\n" <<
					"4, если хотите вывести данные клиента\n" <<
					"5, если хотите удалить всех клиентов\n" <<
					"6, если хотите осуществить поиск по ФИО и адресу\n" <<
					"7, если хотите закончить работу с деревом\n";
				cin >> n1;
				cin.ignore();
				switch (n1) {
				case(1):
					cout << "Введите номер паспорта в формате NNNN-NNNNNN" << endl;
					getline(cin, arg1);
					cout << "Введите место проживания" << endl;
					getline(cin, arg2);
					cout << "Введите дату получения паспорта" << endl;
					getline(cin, arg3);
					cout << "Введите полное имя и фамилию" << endl;
					getline(cin, arg4);
					cout << "Введите год рождения" << endl;
					cin >> argint1;
					cin.ignore();
					cout << "Введите адрес" << endl;
					getline(cin, arg5);
					temp = new client;
					temp->set(arg1, arg2, arg3, arg4, argint1, arg5);
					head->add(head, temp);
					break;
				case 2:
					cout << "Введите номер паспорта клиента, которого вы хотите удалить, в формате NNNN-NNNNNN" << endl;
					getline(cin, arg1);
					client* cl;
					cl = nullptr;
					bool flag;
					flag = 0;
					if (head->find(head, arg1) != nullptr)
						head = head->remove(head, arg1);
					else
						cout << "Элемента не найдено" << endl;
					if (flag == 1) {
						head = cl;
					}
					break;
				case 3:
					head->showtree(head);
					break;
				case 4:
					cout << "Введите номер паспорта в формате NNNN-NNNNNN" << endl;
					getline(cin, arg1);
					head->find(head, arg1)->show();
					break;
				case 5:
					head->del(head);
					cout << "Удаление произведено" << endl;
					break;
				case 6:
					cout << "Введите данные клиентов, которых вы хотите найти" << endl;
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
				cout << "Введите : \n" <<
					"1, если хотите зарегистрировать SIM-карту\n" <<
					"2, если хотите прекратить обслуживание SIM-карты\n" <<
					"3, если хотите вывести данные о регистрации SIM-карты\n" <<
					"4, если хотите вывести весь список\n" <<
					"5, если хотите удалить весь список\n" <<
					"6, если хотите отсортировать список\n" <<
					"7, если хотите закончить работу со списком\n";
				cin >> n1;
				cin.ignore();
				switch (n1) {
				case(1):
					cout << "Введите номер паспорта владельца в формате NNNN-NNNNNN " << endl;
					getline(cin, arg1);
					while (head->find(head, arg1) == nullptr) {
						cout << "Клиент неизвестен. Поворите ввод. " << endl;
						getline(cin, arg1);
					}
					cout << "Введите номер SIM-карты в формате NNN-NNNNNNN" << endl;
					getline(cin, arg2);
					while (HT.retinstock(arg2)!=1) {
						cout << "SIM-карта недоступна. Повторите ввод" << endl;
						getline(cin, arg2);
					}
					cout << "Введите дату производства" << endl;
					cin >> argint1;
					cin.ignore();
					cout << "Введите дату до которой карта годна" << endl;
					cin >> argint2;
					cin.ignore();
					DataSIM* t;
					t = new DataSIM;
					t->set(arg1, arg2, argint1, argint2);
					list.add(t);
					HT.editinstock(0, arg2);
					break;
				case(2):
					cout << "Введите номер SIM-карты в формате NNN-NNNNNNN" << endl;
					getline(cin, arg1);
					if (list.del(arg1) == 0) {
						cout << "Элемент не найден" << endl;
					}
					else {
						cout << "Элемент удален" << endl;
						HT.editinstock(1, arg2);
					}
					break;
				case(3):
					cout << "Введите номер SIM-карты в формате NNN-NNNNNNN, данные которой хотите увидеть" << endl;
					getline(cin, arg1);
					if (list.find(arg1) != nullptr)
						list.find(arg1)->print();
					else cout << "SIM-карты с таким номером не существует" << endl;
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
			cout << "Рады были помочь" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}