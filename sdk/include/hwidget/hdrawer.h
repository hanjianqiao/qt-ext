#ifndef HDRAWER_H
#define HDRAWER_H

#include <QWidget>
#include <QSpacerItem>
#include <QPropertyAnimation>
#include "hwidget_global.h"

class HWIDGET_EXPORT HDrawer : public QWidget
{
    Q_OBJECT
public:
    enum Edge {
        Left, Right, Top, Bottom,
    };
    explicit HDrawer(Edge edge, QWidget *parent);

    void setInLayout(bool inLayout);
    bool inLayout() const;
    Edge edge() const;
    void stopAllAnimations();

protected:
    bool eventFilter(QObject *object, QEvent *event) override;

signals:

public slots:
    void open();
    void close();
    void toggle();

protected:
    bool m_inLayout;
    Edge m_edge;
    QPropertyAnimation *m_openAnimation;
    QPropertyAnimation *m_closeAnimation;
    QWidget *m_mask;
};
#endif // HDRAWER_H
