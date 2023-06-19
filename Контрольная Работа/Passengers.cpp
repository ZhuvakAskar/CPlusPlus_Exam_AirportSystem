#include "Passengers.h"
using namespace std;

Passenger::Passenger()
{
	this->name = "";
	this->place = "";
}

Passenger::Passenger(string name, string place)
{
		this->name = name;
		this->place = place;
}

Passenger::Passenger(const Passenger& obj)
{
	this->name = obj.name;
	this->place = obj.place;
}

void Passenger::setName(string name)
{
	if (name.empty())
		this -> name = name;
}

void Passenger::setPlace(string place)
{
	if(place.empty())
		this->place = place;
}

string Passenger::getName()
{
	return string(name);
}

string Passenger::getPlace()
{
	return place;
}

istream& operator>>(istream& is, Passenger& obj)
{
	cout << "������ �.�.�." << endl;
	is.ignore();
	getline(is,obj.name);
	cout << "������ ���������� �����" << endl;
	is.ignore();
	getline(is, obj.place);
	// TODO: �������� ����� �������� return
	return is;
}

ostream& operator<<(ostream& os, const Passenger& obj)
{
	os << "�.�.�.: " << obj.name << endl;
	os << "���������� �����: " << obj.place << endl;
	// TODO: �������� ����� �������� return
	return os;
}

bool Passenger::operator==(const Passenger& obj) const
{
	return obj.name == this->name;
}

bool Passenger::operator<=(const Passenger& obj) const
{
	return this->place <= obj.place;
}

bool Passenger::operator>=(const Passenger& obj) const
{
	return this->place >= obj.place;
}
