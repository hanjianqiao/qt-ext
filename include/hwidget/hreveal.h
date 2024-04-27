#ifndef HREVEAL_H
#define HREVEAL_H

#include "hwidget_global.h"
#include <QWidget>
#include <QPainter>
#include <QPropertyAnimation>

class HRevealPrivate;

class HWIDGET_EXPORT HReveal : public QWidget
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(HReveal)
    Q_PROPERTY(int radius READ radius WRITE setRadius NOTIFY radiusChanged)

public:
    explicit HReveal(QWidget *parent = nullptr);

    void start(int w, int h, const QPoint& center, int radius);
    int radius() const;
    void setRadius(int value);

    void paintEvent(QPaintEvent *event) override;

Q_SIGNALS:
    void imageChanged();
    void radiusChanged(int value);

};

#endif // HREVEAL_H
