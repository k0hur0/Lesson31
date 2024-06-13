#pragma once
#include "Soft.h"

class freeSoft : public Soft
{
public:
	freeSoft();
	freeSoft(string name, string company);

	void showInfo()const override;
	bool isAvailable()const override;
};

