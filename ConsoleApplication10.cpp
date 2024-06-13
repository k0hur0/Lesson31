#include <iostream>
#include "freeSoft.h"
using namespace std;

int main()
{
    Soft* obj = new freeSoft("Paint", "Microsoft");

    obj->showInfo();
}

