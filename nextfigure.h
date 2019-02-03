#ifndef NEXTFIGURE_H
#define NEXTFIGURE_H

#include <QWidget>
#include "figure.h"
#include <QApplication>
#include <QDesktopWidget>


class NextFigure : public QWidget
{
private:
    Q_OBJECT
    Figure *tooltip;
    void paintEvent(QPaintEvent*event);
public:
    uint cell;
    explicit NextFigure(QWidget *parent = nullptr);

    ~NextFigure() {delete tooltip;}
signals:    
public slots:
    void paintTooltip(Figure* source);
};

#endif // NEXTFIGURE_H
