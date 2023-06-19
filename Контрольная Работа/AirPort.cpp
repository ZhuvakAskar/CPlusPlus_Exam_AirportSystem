#include "AirPort.h"

AirPort::AirPort()
{
	this->airpcounte = 0;
	this->mas = NULL;
}

AirPort::~AirPort()
{
	if(this->airpcounte !=0)
	delete[]mas;
}

void AirPort::addAirplane()
{
	bool n = false;
	Airplane a;
	cin >> a;
	for (int i = 0; i < this->airpcounte; i++) {
			if (mas[i].getsernum() == a.getsernum()) {
				n = true;
				break;
			}
	}
	if (n == false) {
		Airplane* tmp = new Airplane[++airpcounte];
		for (int i = 0; i < airpcounte - 1; i++) {
			tmp[i] = mas[i];
		}

		tmp[airpcounte - 1] = a;


		if (mas != NULL) {
			//delete[] mas;
		}


			mas = tmp;
	}
	else {
		cout << "Самолёт с таким серийным номером уже загестрирован" << endl;
	}
}

void AirPort::dellAirplane()
{
	int n;
	int place = -1;
	if(airpcounte == 0) {
		cout << "База данных аэропорта пуста" << endl;
	}
	else {
		cout << "Ведите серийный номер самолёта" << endl;
		cin >> n;
		for (int i = 0; i < this->airpcounte; i++) {
				if (mas->getsernum() == n) {
					place = i;
					break;
				}
		}
		if (place == -1) {
			cout << "Самолёт не найден" << endl;
		}
		else {
			cout << mas[place];
			cout << "Вы действительно хотите удалить этот самолёт из БД?" << endl;
			cout << "1 - да                 0 - нет" << endl;
			cin >> n;
			if (n == 1) {
				for (int i = place; i < this->airpcounte - 1; i++) {
					mas[i] = mas[i + 1];
				}
				this->airpcounte -= 1;
			}
		}
	}
}

void AirPort::showAllAirplanes()const&
{
	if (this->airpcounte != 0) {
		for (int i = 0; i < this->airpcounte; i++) {
			cout << "----------------------------------------------------" << endl;
			cout << mas[i];
		}
	}
	else cout << "База данных пуста" << endl;
}

void AirPort::showinfoairplane() const&
{
	bool n = 0;
	int type = -1;
	cout << "1 - вывод самолёт по модели" << endl;
	cout << "2 - вывод самолётов по рейсам" << endl;
	cout << "3 - вывод самолёта по рерийному номеру" << endl;
	cin >> type;
	switch (type)
	{
	case 1: {
		string pname;
		cin.ignore();
		getline(cin, pname);
		for (int i = 0; i < this->airpcounte; i++) {
			if (mas[i].getPname() == pname)
				cout << mas[i];
			cout << "------------------------------------------" << endl;
			n = 1;
		}
		if (n == 0) {
			cout << "Самолёт не найден" << endl;
		}
		break;
	}
	case 2: {
		string flight;
		cin.ignore();
		getline(cin, flight);
		for (int i = 0; i < this->airpcounte; i++) {
			if (mas[i].getFlight() == flight)
				cout << mas[i];
			n = 1;
			cout << "------------------------------------------" << endl;
		}
		if (n == 0) {
			cout << "Самолёт не найден" << endl;
		}
		break;
	}
	case 3: {
		int sernum;
		cin >> sernum;
		for (int i = 0; i < this->airpcounte; i++) {
			if (mas[i].getsernum() == sernum)
				cout << mas[i];
			cout << "------------------------------------------" << endl;
		}
		if (n == 0) {
			cout << "Самолёт не найден" << endl;
		}
		break;
	}
	default:
		cout << "Ошибка ввода" << endl;
		break;
	}
}

int AirPort::findairplanefor()const&
{
	int sernum;
	cout << "Ведите серийный номер самолёта" << endl;
	cin >> sernum;
	for (int i = 0; i < this->airpcounte; i++) {
		if (mas[i].getsernum() == sernum)
			return i;
	}
	return -1;
}

void AirPort::systemUP()
{
	int menu = -0,n,n1;
	Airplane a;
	Passenger p;
	

	while (true)
	{
		cout << "-1 - Выход" << endl;
		cout << "1 - самолёты" << endl;
		cout << "2 - пасажиры" << endl;
		cout << "3 - отчистить экран" << endl;
		cin >> menu;
		cout << "----------------------------------------------------" << endl;
		switch (menu)
		{
		case -1: {
			break;
		}

		case 1: {
			while (menu != 0)
			{
				cout << "0 - назад" << endl;
				cout << "1 - список самолётов в БД" << endl;
				cout << "2 - поиск самолётов" << endl;
				cout << "3 - добавить самолёт" << endl;
				cout << "4 - удалить самолёт" << endl;
				//cout << "5 - редактировать самолёт" << endl;
				cout << "5 - отчистить экран" << endl;
				cin >> menu;
				switch (menu)
				{
				case 0: break;
				case 1: {
					this->showAllAirplanes();
					break;
				}

				case 2: {
					this->showinfoairplane();
					break;
				}

				case 3: {
					this->addAirplane();
					break;
				}

				case 4: {
					this->dellAirplane();
					break;
				}

				//case 5: {

				//	break;
				//}

				case 5: {
					system("cls");
					break;
				}
				default:
					cout << "Ошибка ввода" << endl;
					break;
				}
				cout << "----------------------------------------------------" << endl;
			}
			break;
		}

		case 2: {
			while (menu != 0)
			{
				cout << "0 - назад" << endl;
				cout << "1 - список посажиров самолёта" << endl;
				cout << "2 - добавить посажира" << endl;
				cout << "3 - удалить посажира" << endl;
				//cout << "4 - редактировать пасажира" << endl;
				cout << "4 - отчистить экран" << endl;
				cin >> menu;
				switch (menu)
				{
				case 0: break;
				case 1: {
					n = this->findairplanefor();
					if (n != -1) {
						mas[n].showPassegers();
					}
					else {
						cout << "Самолёт не найден" << endl;
					}
					break;
				}

				case 2: {
					n = this->findairplanefor();
					if (n != -1) {
						cin >> p;
						mas->addPassegers(p);
					}
					else {
						cout << "Самолёт не найден" << endl;
					}
					break;
				}

				case 3: {
					n = this->findairplanefor();
					if (n != -1) {
						cin >> p;
						mas->delPassegers(p);
					}
					else {
						cout << "Самолёт не найден" << endl;
					}
					break;
				}

				//case 4: {
				//	n = this->findairplanefor();
				//	if (n != -1) {
				//		n1 = mas[n].findpassegerfor();
				//		cout << ""
				//	}
				//	else {
				//		cout << "Самолёт не найден" << endl;
				//	}
				//	break;
				//}

				case 4: {
					system("cls");
					break;
				}

				default:
					cout << "Ошибка ввода" << endl;
					break;
				}
				cout << "----------------------------------------------------" << endl;
			}
			break; 
		}

		case 3: {
			system("cls");
			break; 
		}

		default:
			cout << "Ошибка ввода" << endl;
			break;
		}






		if (menu == -1) {
			cout << "Вы уверенны что хотите выйти?" << endl;
			cout << "1 - да                 0 - нет" << endl;
			cin >> menu;
			if (menu == 1) {
				break;
			}
		}
		cout << "===================================================" << endl;
	}
}
