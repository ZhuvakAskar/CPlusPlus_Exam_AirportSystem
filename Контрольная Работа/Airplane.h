#pragma once
#include"Header.h"
#include"Passengers.h"

class Airplane
{
	string flight;
	string pname;
	int serialnum;
	int pcoutnow = 0, pmax = 0;
	Passenger* mas;
public:
	Airplane();
	~Airplane();
	Airplane(const Airplane& obj);

	void setFlight(string flight);
	string getFlight()const;

	void setPname(string pname);
	string getPname()const;

	void setsernum(int sernum);
	int getsernum()const&;

	int getpcountnow()const&;

	void setPmax(int pmax);
	int getPmax()const;

	void addPassegers(Passenger obj);
	void delPassegers(Passenger obj);

	void showPassegers()const&;
	int findpassegerfor()const&;

	bool operator == (const Airplane& obj)const;
	bool operator > (const Airplane& obj)const;

	friend istream& operator >> (istream& is, Airplane& obj);
	friend ostream& operator << (ostream& os, const Airplane& obj);

	void operator ++(int n);
	void operator --(int n);
};

