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
    explicit HDrawer(int size, int topOffset, Edge edge, QWidget *parent);

    void setDrawerSize(int size);
    int drawerSize() const;
    void setInLayout(bool inLayout);
    bool inLayout() const;
    Edge edge() const;
    void stopAllAnimations();

    void setContentWidget(QWidget *w);

protected:
    bool eventFilter(QObject *object, QEvent *event) override;

signals:

public slots:
    void open();
    void close();
    void toggle();

protected:
    QWidget *m_contentWidget;
    bool m_inLayout;
    int m_drawerSize; // width or height of drawer
    int m_topOffset;
    Edge m_edge;
    QPropertyAnimation *m_openAnimation;
    QPropertyAnimation *m_closeAnimation;
    QWidget *m_mask;
    QWidget *m_topSpacer;
};
#endif // HDRAWER_H
