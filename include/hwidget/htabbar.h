#ifndef HTABBAR_H
#define HTABBAR_H

#include <QWidget>
#include "hwidget_global.h"

class HTabBarPrivate;

class HWIDGET_EXPORT HTabBar : public QWidget
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(HTabBar)

public:
    explicit HTabBar(QWidget *parent = nullptr);

protected:
    HTabBar(HTabBarPrivate &dd, QWidget* parent = nullptr);

signals:


private:
    Q_DISABLE_COPY(HTabBar)
};

#endif // HTABBAR_H
