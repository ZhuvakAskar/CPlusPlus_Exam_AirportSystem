#include "Airplane.h"

Airplane::Airplane()
{
    this->flight = "";
    this->pname = "";
    this->serialnum = rand() % 1000;
    this->pcoutnow = 0;
    this->mas = new Passenger[pcoutnow];
}

Airplane::~Airplane()
{
    if(this->mas != NULL)
    delete[]mas;
}

Airplane::Airplane(const Airplane& obj)
{
    this->flight = obj.flight;
    this->pname = obj.pname;
    this->pmax = obj.pmax;
    this->pcoutnow = obj.pcoutnow;
    this->mas = new Passenger[this->pcoutnow];
    for (int i = 0; i < pcoutnow; i++)
    {
        this->mas[i] = obj.mas[i];
    }
}

void Airplane::setFlight(string flight)
{
    this->flight = flight;
}

string Airplane::getFlight() const
{
    return this->flight;
}

void Airplane::setPname(string pname)
{
    if (!pname.empty())
        this->pname = pname;
}

string Airplane::getPname() const
{
    return this->flight;
}

void Airplane::setsernum(int sernum)
{
    this->serialnum = sernum;
}

int Airplane::findpassegerfor() const&
{
    int n = -1;
    if (this->mas != NULL) {
        string p;
        cout << "1 - поиско по Ф.И.О." << endl;
        cout << "2 - поиско по посадочнуому месту" << endl;
        cin >> n;
        if (n == 1) {
            cout << "Введите Ф.И.О." << endl;
            cin >> p;
            for (int i = 0; i < this->pcoutnow; i++) {
                if (mas[i].getName() == p) {
                    n = i;
                    break;
                }
            }
        }
        else if (n == 2) {
            cout << "Введите посадочное место" << endl;
            cin >> p;
            for (int i = 0; i < this->pcoutnow; i++) {
                if (mas[i].getPlace() == p) {
                    n = i;
                    break;
                }
            }
        }
        else cout << "Ошибка ввода" << endl;
        return n;
    }
}

int Airplane::getsernum() const&
{
    return this->serialnum;
}

int Airplane::getpcountnow() const&
{
    return this->pcoutnow;
}

void Airplane::setPmax(int pmax)
{
    this->pmax = pmax;
}

int Airplane::getPmax() const
{
    return this->pmax;
}

void Airplane::addPassegers(Passenger obj)
{
    if (this->pcoutnow < this->pmax) {
        Passenger* tmp = new Passenger[++pcoutnow];
        for (int i = 0; i < pcoutnow - 1; i++) {
            tmp[i] = mas[i];
        }
        if (mas != NULL) {
            delete[]mas;
        }
        tmp[pcoutnow - 1] = obj;
        mas = tmp;
        this->pcoutnow++;
    }
    else cout << "Самолёт переполнен" << endl;
}

void Airplane::delPassegers(Passenger obj)
{
    for (int i = 0; i < pcoutnow; i++) {
        if (this->pcoutnow > 0) {
            if (obj.getName() == mas[i].getName()) {
                mas[i] = mas[pcoutnow - 1];
                this->pcoutnow--;
            }
        }
    }
}

void Airplane::showPassegers() const&
{
    int i = 0;
    while (i < this->pcoutnow)
    {
        cout << this->mas[i];
    }
    
}

bool Airplane::operator==(const Airplane& obj) const
{
    return this->pname == obj.pname;
}

bool Airplane::operator>(const Airplane& obj) const
{
    return this->pmax < obj.pmax;
}
void Airplane::operator++(int n)
{
    this->pmax =+ n;
}
void Airplane::operator--(int n)
{
    if (pmax - n > this->pcoutnow) {
        this->pmax =- n;
    }
    else {
        cout << "Невозможно изменить характеристики самолёта" << endl <<
            "После изменения в самолёте будет больше пасажиров чем он сможет вместить" << endl;
    }
}
istream& operator>>(istream& is, Airplane& obj)
{
    cout << "Ведите модель самолёта" << endl;
    is >> obj.pname;
    cout << "Ведите рейс самолёта" << endl;
    is >> obj.flight;
    cout << "Ведите количество посадочных мест" << endl;
    is >> obj.pmax;
    cout << "Ведите серийный номер" << endl;
    is >> obj.serialnum;
    if (obj.serialnum == NULL) {
        obj.serialnum = rand();
    }
    return is;
}

ostream& operator<<(ostream& os, const Airplane& obj)
{
    os << "Самолёт: " << obj.pname << endl;
    os << "Рейс: " << obj.flight << endl;
    os << "Серийный номер: " << obj.serialnum << endl;
    os << "Посадочные места: " << obj.pmax << endl;
    os << "Количество пасажиров: " << obj.pcoutnow << endl;
    return os;
}
