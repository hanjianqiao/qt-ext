#ifndef HOTP_H
#define HOTP_H

#include "hcore_global.h"

class HCORE_EXPORT HOTP
{
public:
    HOTP();
};

class HCORE_EXPORT HTOTP
{
public:
    static int generatePassword(const QString &originSecret, qint64 second = -1);
};

#endif // HOTP_H
