#ifndef HCOMPRESSION_H
#define HCOMPRESSION_H

#include <QByteArray>

#include "hcore_global.h"

class HCORE_EXPORT HCompression
{
public:
    static QByteArray decompress(const QByteArray &data, bool *ok = nullptr);
    static QByteArray compress(const QByteArray &data, bool *ok = nullptr);

    HCompression();
};

#endif // HCOMPRESSION_H
