#ifndef HFLOWLAYOUT_H
#define HFLOWLAYOUT_H

#include <QLayout>
#include <QStyle>
#include "hwidget_global.h"

class HFlowLayoutPrivate;

class HWIDGET_EXPORT HFlowLayout : public QLayout
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(HFlowLayout)
public:
    explicit HFlowLayout(QWidget *parent, int margin = -1, int hSpacing = -1, int vSpacing = -1);
    explicit HFlowLayout(int margin = -1, int hSpacing = -1, int vSpacing = -1);
    ~HFlowLayout();

    void addItem(QLayoutItem *item) override;
    int horizontalSpacing() const;
    int verticalSpacing() const;
    Qt::Orientations expandingDirections() const override;
    bool hasHeightForWidth() const override;
    int heightForWidth(int) const override;
    int count() const override;
    QLayoutItem *itemAt(int index) const override;
    QSize minimumSize() const override;
    void setGeometry(const QRect &rect) override;
    QSize sizeHint() const override;
    QLayoutItem *takeAt(int index) override;

    void insertWidget(int i, QWidget *widget);

private:
    Q_DISABLE_COPY(HFlowLayout)

private:
    int doLayout(const QRect &rect, bool testOnly) const;
    int smartSpacing(QStyle::PixelMetric pm) const;

    QList<QLayoutItem *> itemList;
    int m_hSpace;
    int m_vSpace;
};

#endif // HFLOWLAYOUT_H
