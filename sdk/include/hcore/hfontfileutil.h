#ifndef HFONTFILEUTIL_H
#define HFONTFILEUTIL_H

#include <QByteArray>
#include "hcore_global.h"

class HCORE_EXPORT HFontFileUtil
{
public:
    static QByteArray WOFF2ToTTF(const QByteArray &data);

    HFontFileUtil();
};

#endif // HFONTFILEUTIL_H
