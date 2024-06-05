#ifndef HGLOBALMOUSEGRABBER_H
#define HGLOBALMOUSEGRABBER_H

#include <QObject>
#include <QEvent>
#include <QMouseEvent>
#include <QWheelEvent>
#include "hwidget_global.h"

class QMouseEvent;
class QWheelEvent;

class HWIDGET_EXPORT HGlobalMouseGrabber : public QObject
{
    Q_OBJECT
public:
    static HGlobalMouseGrabber* getInstance();

    static bool installMouseEvent();      // 安装全局鼠标事件监听器
    static bool removeMouseEvent();       // 卸载全局鼠标事件监听器

signals:
    /**
     * @brief 由于传递的是指针，为了保证不会出现内存泄露，需要在槽函数中delete。
     *        建议此信号只绑定一次，因为如果绑定多次可能会出现一个槽函数里把信号delete了，另外一个槽函数还在使用，出现野指针，或者多个槽函数多次delete
     */
    void mouseEvent(QEvent::Type type, const QPoint &pos, Qt::MouseButton button, Qt::MouseButtons buttons, Qt::KeyboardModifiers modifiers);
    void wheelEvent(int delta, const QPoint &pos, Qt::MouseButton button, Qt::KeyboardModifiers modifiers);

private:
    HGlobalMouseGrabber();
    int m_refCount;
};

#endif // HGLOBALMOUSEGRABBER_H
