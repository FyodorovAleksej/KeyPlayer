#include "nullproperties.h"

NullProperties::NullProperties()
{
    this->theme_ = "Default";
    this->volume_def_ = 100;
    this->shift_inv_ = true;
    this->caps_def_ = false;
    this->repeat_def_ = false;
}

bool NullProperties::IsNull()
{
    return true;
}
