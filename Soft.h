#pragma once
#include "Data.h"
#include <string>
using namespace std;

class Soft
{
	string name;
	string company;

public:
	Soft();
	Soft(string name, string company);
	virtual~Soft();

	void setName(string name);
	void setCompany(string company);

	string getName()const;
	string getCompany()const;

	virtual void showInfo()const = 0;
	virtual bool isAvailable()const = 0;
};

