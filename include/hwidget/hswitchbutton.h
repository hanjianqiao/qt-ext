#ifndef HSWITCHBUTTON_H
#define HSWITCHBUTTON_H

#include "hwidget_global.h"
#include <QWidget>


class HSwitchButtonPrivate;

class HWIDGET_EXPORT HSwitchButton : public QWidget
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(HSwitchButton)

    Q_PROPERTY(qreal openness READ openness WRITE setOpenness NOTIFY opennessChanged)

public:
    explicit HSwitchButton(QWidget *parent = nullptr);

    void setOpen(bool open);
    bool isOpen() const;

private:
    void setOpenness(qreal value);
    qreal openness() const;

protected:
    void paintEvent(QPaintEvent *event) override;
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

    HSwitchButton(HSwitchButtonPrivate &dd, QWidget* parent = nullptr);

signals:
    void stateChanged(bool opened);
    void opennessChanged(qreal value);

private:
    Q_DISABLE_COPY(HSwitchButton)
};

#endif // HSWITCHBUTTON_H
