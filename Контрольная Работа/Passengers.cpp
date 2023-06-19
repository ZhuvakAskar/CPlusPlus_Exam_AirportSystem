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
	cout << "Ведите Ф.И.О." << endl;
	is.ignore();
	getline(is,obj.name);
	cout << "Ведите посадочное место" << endl;
	is.ignore();
	getline(is, obj.place);
	// TODO: вставьте здесь оператор return
	return is;
}

ostream& operator<<(ostream& os, const Passenger& obj)
{
	os << "Ф.И.О.: " << obj.name << endl;
	os << "Посадочное место: " << obj.place << endl;
	// TODO: вставьте здесь оператор return
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
