#ifndef HENCODING_H
#define HENCODING_H

#include <QString>
#include <QByteArray>
#include "hcore_global.h"

class HCORE_EXPORT HEncoding
{
public:
    static QString toBase32(const QByteArray &data, bool *ok = nullptr);
    static QByteArray fromBase32(const QString &str, bool *ok = nullptr);

    HEncoding() = delete;
};

#endif // HENCODING_H
