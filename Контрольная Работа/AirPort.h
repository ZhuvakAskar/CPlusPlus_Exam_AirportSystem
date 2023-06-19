#pragma once
#include"Airplane.h"
#include"Header.h"
class AirPort
{
private:
	Airplane* mas;
	int airpcounte;
public:
	AirPort();
	~AirPort();

	void addAirplane();
	void dellAirplane();

	void showAllAirplanes()const&;
	void showinfoairplane()const&;

	int findairplanefor()const&;

	void systemUP();
};

