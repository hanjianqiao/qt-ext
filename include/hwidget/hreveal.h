#ifndef HREVEAL_H
#define HREVEAL_H

#include "hwidget_global.h"
#include <QWidget>
#include <QPainter>
#include <QPropertyAnimation>

class HWIDGET_EXPORT HReveal : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(int radius MEMBER m_radius NOTIFY radiusChanged)

public:
    explicit HReveal(QWidget *parent = nullptr);

    void start(int w, int h, const QPoint& center, int radius);

    void paintEvent(QPaintEvent *event) override;

Q_SIGNALS:
    void imageChanged();
    void radiusChanged();

private:
    QPropertyAnimation *m_anim;
    QPixmap m_source;
    QPoint m_center;
    int m_radius;

};

#endif // HREVEAL_H
