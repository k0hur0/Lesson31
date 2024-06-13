#include "freeSoft.h"

freeSoft::freeSoft() : Soft("free", "company")
{
    
}

freeSoft::freeSoft(string name, string company) : Soft(name, company)
{

}

void freeSoft::showInfo() const
{
    cout << "Name: " << getName() << endl;
    cout << "Company: " << getCompany() << endl;
    cout << "Is available: " << isAvailable() << endl;
}

bool freeSoft::isAvailable() const
{
    return true;
}
