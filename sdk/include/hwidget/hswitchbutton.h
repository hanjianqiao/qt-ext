#ifndef HSWITCHBUTTON_H
#define HSWITCHBUTTON_H

#include "hwidget_global.h"
#include <QWidget>


class HSwitchButtonPrivate;

class HWIDGET_EXPORT HSwitchButton : public QWidget
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(HSwitchButton)

public:
    enum State{
        Off,
        On,
    };
    Q_ENUM(State)

    explicit HSwitchButton(QWidget *parent = nullptr);

    void setState(State state);
    State state() const;
    void setOpen(bool open);
    bool isOpen() const;

    void setPixmap(const QPixmap &onPixmap, const QPixmap &offPixmap);
    void setTrackColor(const QColor &onColor, const QColor &offColor);
    void setTrackBorderColor(const QColor &onColor, const QColor &offColor);
    void setHandleColor(const QColor &onColor, const QColor &offColor);
    void setTrackHeight(int height);
    void setHandlSizeDelta(int delta);
    QSize handleIconSize() const;

    void setFixedSize(int w, int h);
    void setFixedSize(const QSize &size);

protected:
    void paintEvent(QPaintEvent *event) override;
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

    HSwitchButton(HSwitchButtonPrivate &dd, QWidget* parent = nullptr);

private:


signals:
    void stateChanged(State state);

private:
    Q_DISABLE_COPY(HSwitchButton)
};

#endif // HSWITCHBUTTON_H
