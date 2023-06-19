#pragma once
#include "Header.h"
class Passenger
{
	string name;
	string place;
public:
	Passenger();
	Passenger(string name, string place);
	Passenger(const Passenger& obj);

	void setName(string name);
	void setPlace(string place);
	string getName();
	string getPlace();

	bool operator == (const Passenger& obj)const;
	bool operator <= (const Passenger& obj)const;
	bool operator >= (const Passenger& obj)const;

	friend istream& operator >> (istream& is, Passenger& obj);
	friend ostream& operator << (ostream& os, const Passenger& obj);
};

