#ifndef HFONTAWESOME_H
#define HFONTAWESOME_H

#include <QObject>
#include <QIcon>
#include <QIconEngine>
#include <QPainter>
#include <QRect>
#include <QVariantMap>
#include "hiconfont.h"

#include "hwidget_global.h"

#define FONT_AWESOME_PRO

#include "QtAwesomeEnumGenerated.h"

namespace fa{

enum fa_styles {
    fa_solid = 0,
    fa_regular = 1,
    fa_brands = 2,
    fa_light = 3,
    fa_thin = 4,
    fa_duotone = 5,
    fa_sharp_solid = 6,
    fa_sharp_regular = 7,
    fa_sharp_light = 8,
    fa_sharp_thin = 9,
};

}

class HWIDGET_EXPORT HFontAwesome
{
public:
    static void initialize();
    static QIcon icon(int fontIndex, int character, const HIconFontIconOption &options = HIconFontIconOption());

private:
    static HIconFont *s_iconFont;
};

#endif // HFONTAWESOME_H
