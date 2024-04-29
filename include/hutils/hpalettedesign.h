#ifndef HPALETTEDESIGN_H
#define HPALETTEDESIGN_H

#include <QWidget>
#include <QStandardItemModel>
#include <QTableView>
#include "hutils_global.h"

class HPaletteDesignPrivate;

class HUTILS_EXPORT HPaletteDesign : public QWidget
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(HPaletteDesign)
public:
    explicit HPaletteDesign(QWidget *parent = nullptr);

    void updateTable();

signals:

private:
    void init();
    HPaletteDesign(HPaletteDesignPrivate &dd, QWidget* parent = nullptr);

private:
    QTableView *m_tableView;
    QStandardItemModel *m_tableModel;

};

#endif // HPALETTEDESIGN_H
