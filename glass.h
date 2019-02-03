#ifndef GLASS_H
#define GLASS_H

#include <QApplication>
#include <QDesktopWidget>
#include <QWidget>
#include <QDebug>
#include <QKeyEvent>
#include <QPainter>
#include <QTimer>
#include <QMessageBox>
#include <QThread>
#include <QList>
#include <QPair>
#include "figure.h"

#define emptyCell QColor(150,150,150)

class Glass : public QWidget
{
private:
    Q_OBJECT    
    uint m_rows;
    unsigned int m_columns;
    bool gameOn, drawFigure;
    uint score;
    int timerInterval;
    QVector<QVector<QColor>>glassArray;
    int idTimer;
    Figure *cur, *next;

    void fillGlass();
    int glassScan();
    bool leftSideFreeSpaceAv();
    bool rightSideFreeSpaceAv();
    bool refresh();

public:
    uint _cell;
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
    void timerEvent(QTimerEvent*event);

signals:
    void signalGlassInit();
    void gamover();
    void drawPattern(Figure*);
    void setScore(int);
public slots:
    void gamOver();
    void pause();
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
