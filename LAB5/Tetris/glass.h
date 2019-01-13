#ifndef GLASS_H
#define GLASS_H

#include <QWidget>
#include <QDebug>
#include <QKeyEvent>
#include <QPainter>
#include <QTimer>
#include "figure.h"

#define emptyCell QColor(150,150,150)

class Glass : public QWidget
{
    Q_OBJECT
    static const uint W=20;
    uint m_rows;
    unsigned int m_columns;
    bool gameOn;
    uint score;
    uint timerInterval;
    QVector<QVector<QColor>>glassArray;
    Figure *cur, *next;
private:
    void fillGlass();
public:

    Q_PROPERTY(uint rows READ rows WRITE setRows)
    Q_PROPERTY(unsigned int columns READ columns WRITE setColumns)
    explicit Glass(QWidget *parent = nullptr);
    ~Glass(){ delete cur; delete next;}

    uint rows() const {
        return m_rows;
    }
    unsigned int columns() const {
        return m_columns;
    }

    void clearGlass();
    QSize calcGlassSize();


 protected:
    void paintEvent(QPaintEvent*event);
    void keyPressEvent(QKeyEvent*event);

signals:
    void signalGlassInit();
public slots:
    void setRows(uint rows) {
        m_rows = rows;
    }
    void setColumns(unsigned int columns) {
        m_columns = columns;
    }
    void slotGlassInit();
    void slotNewGame();

};

#endif // GLASS_H
