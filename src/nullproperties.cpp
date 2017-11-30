#include "nullproperties.h"

NullProperties::NullProperties()
{
    this->theme = "Default";
    this->volumeDef = 100;
    this->shiftInv = true;
    this->capsDef = false;
    this->repeatDef = false;
}

bool NullProperties::isNull()
{
    return true;
}
