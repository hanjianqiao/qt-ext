#ifndef HICONFONT_H
#define HICONFONT_H

#include <QString>
#include <QHash>
#include <QFont>
#include <QIcon>
#include <QChar>
#include <QVariant>
#include "hwidget_global.h"

class HIconFontPrivate;
class HIconFont;


class HWIDGET_EXPORT HIconFontIconOption{
public:
    HIconFontIconOption();

    QColor color(QIcon::Mode mode, QIcon::State state) const;
    QColor duotoneColor(QIcon::Mode mode, QIcon::State state) const;
    QString text(QIcon::Mode mode, QIcon::State state) const;
    qreal scaleFactor() const;
    int fontIndex() const;
    bool duotone() const;

    void setFontIndex(int index);
    void setDuotone(bool duotone);
    void setScaleFactor(qreal scaleFactor);
    void setText(const QString &text, QIcon::State state = QIcon::State::On, QIcon::Mode mode = QIcon::Mode::Normal);
    void setColor(const QColor &color, QIcon::State state = QIcon::State::On, QIcon::Mode mode = QIcon::Mode::Normal);
    void setDuotoneColor(const QColor &color, QIcon::State state = QIcon::State::On, QIcon::Mode mode = QIcon::Mode::Normal);

private:
    bool m_duotone;
    double m_scaleFactor;
    int m_fontIndex;
    QString m_text[2][4];
    QColor m_color[2][4];
    QColor m_duotoneColor[2][4];
};

class HWIDGET_EXPORT HIconFontIconPainter
{
public:
    virtual ~HIconFontIconPainter();
    virtual void paint(HIconFont* hIconFont, QPainter* painter, const QRect& rect,  QIcon::Mode mode, QIcon::State state,
                       const HIconFontIconOption &options) = 0;
};

struct HWIDGET_EXPORT HIconFontFontRegisterInfo{
    QString fontFamily;
    QFont::Weight weight;
    QString fileName;
    int fontID;

    HIconFontFontRegisterInfo(const QString &fileName, QFont::Weight weight);
};

class HWIDGET_EXPORT HIconFont
{
    Q_DECLARE_PRIVATE(HIconFont)
public:
    static HIconFont *g();
    static bool initializeG(const QList<HIconFontFontRegisterInfo> &fonts);

    HIconFont();
    ~HIconFont();
    QFont font(int fontIndex, int size) const;
    bool registerFonts(const QList<HIconFontFontRegisterInfo> &fonts);

    const QList<HIconFontFontRegisterInfo> &registeredFonts() const;
    QIcon icon(HIconFontIconPainter *painter, const HIconFontIconOption &options);
    QIcon icon(int fontIndex, int character, const HIconFontIconOption &options = HIconFontIconOption());

private:
    static HIconFont *s_singleton;

    HIconFontIconPainter *m_defaultPainter;
    QList<HIconFontFontRegisterInfo> m_registeredFonts;
    QHash<QString, int> m_iconNameIndexHash;

    HIconFontPrivate *d_ptr;
};

#endif // HICONFONT_H
