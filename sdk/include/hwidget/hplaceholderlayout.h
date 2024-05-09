#ifndef HPLACEHOLDERLAYOUT_H
#define HPLACEHOLDERLAYOUT_H

#include <QLayout>
#include "hwidget_global.h"

class HPlaceholderLayoutPrivate;

class HWIDGET_EXPORT HPlaceholderLayout : public QLayout
{
    Q_DECLARE_PRIVATE(HPlaceholderLayout)
public:
    explicit HPlaceholderLayout(QWidget *parent = nullptr);
    ~HPlaceholderLayout();

    void setWidget(QWidget *w);

    void addItem(QLayoutItem *item) override;
    QLayoutItem *takeAt(int index) override;
    int count() const override;
    QLayoutItem *itemAt(int index) const override;
    QSize sizeHint() const override;
    void setGeometry(const QRect &r) override;

private:
};

#endif // HPLACEHOLDERLAYOUT_H
