#ifndef NULLPROPERTIES_H
#define NULLPROPERTIES_H

#include <QObject>
#include "properties.h"

/**
 * @brief The NullProperties class - the specfic class with default settings
 */
class NullProperties : public Properties
{
public:
    /**
     * @brief NullProperties - creating new object of properties with default properties
     */
    NullProperties();

    /**
     * @brief isNull - compare with Properties class
     * @return false
     */
    bool isNull();

};

#endif // NULLPROPERTIES_H
