#include "Patient.h"
#include <string>
using namespace std;
Patient::Patient()
{
    //ctor
}


void Patient::setPrimary(Doctor p)
{
    primary=p;
}

Doctor Patient::getPrimary()
{
    return primary;
}

Patient::~Patient()
{
    //dtor
}
