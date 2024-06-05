#ifndef HRANDOM_H
#define HRANDOM_H

#include <QString>
#include "hcore_global.h"

class HCORE_EXPORT HRandom
{
public:
    static QString randomString(
        qsizetype minLength, qsizetype maxLength = -1,
        bool withUpperCase = true, bool withLowerCase = true, bool withNumber = true, bool withSymbole = false,
        const QString &possibleCharacters = QString());
    static QString randomCombineTimes(qsizetype minTimes, const QStringList &possibleStrs, qsizetype maxTimes = -1);
    static QString randomCombineLength(qsizetype minLength, const QStringList &possibleStrs, qsizetype maxLength = -1);

    HRandom();
};

#endif // HRANDOM_H
