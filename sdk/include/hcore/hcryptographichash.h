#ifndef HCRYPTOGRAPHICHASH_H
#define HCRYPTOGRAPHICHASH_H

#include <QtCore/qcryptographichash.h>
#include "hcore_global.h"

class HCryptographicHashPrivate;

class HCORE_EXPORT HCryptographicHash
{
    Q_GADGET
public:
    enum Algorithm{
        SM3 = QCryptographicHash::NumAlgorithms + 1,
    };
    Q_ENUM(Algorithm)

    HCryptographicHash();
    ~HCryptographicHash();

    static QByteArray hash(QByteArrayView data, Algorithm method);

private:
    Q_DISABLE_COPY(HCryptographicHash)
    HCryptographicHashPrivate *d;
};

class HCORE_EXPORT HHmacSha1
{
public:
    static QByteArray hmacSha1(QByteArray key, QByteArray baseString);
};

#endif // HCRYPTOGRAPHICHASH_H
