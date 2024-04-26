#ifndef HCODEEDIT_H
#define HCODEEDIT_H

#include <QPlainTextEdit>
#include "hwidget_global.h"

class HCodeEditLineNumberArea;

class HWIDGET_EXPORT HCodeEdit : public QPlainTextEdit
{
    Q_OBJECT

public:
    enum Shortcut{
        ShiftEnter,
    };

    explicit HCodeEdit(QWidget *parent = nullptr);

protected:
    void resizeEvent(QResizeEvent *event) override;
    void keyPressEvent(QKeyEvent *e) override;

private:
    void init();

Q_SIGNALS:
    void shortcutActivited(Shortcut shortcut);

private Q_SLOTS:
    void updateLineNumberAreaWidth(int newBlockCount);
    void highlightCurrentLine();
    void updateLineNumberArea(const QRect &rect, int dy);

private:
    HCodeEditLineNumberArea *m_lineArea;

    friend class HCodeEditLineNumberArea;
};

#endif // HCODEEDIT_H
