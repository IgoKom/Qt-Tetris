#ifndef FIGURE_H
#define FIGURE_H
#define emptyCell QColor(150,150,150)

#include <QApplication>
#include <QDesktopWidget>
#include <QVector>
#include <QColor>
#include <QPainter>

class Figure {
private:
    //static const unsigned int W=20;
    unsigned int m_i, m_j;
    QVector<QColor> fig;    

public:
    quint32 value1;
    uint cell;
    Figure(uint r, uint c);
    Figure operator=(Figure& ref);
    ~Figure(){}
    void setIndices(uint r, uint c);
    void getIndices(uint* indAr); //2-element UINT array
    void shiftColors(bool direction);
    void MakeRandomColors();
    void CleanFigure();
    void paintFigure(QPainter& painter);
    QVector<QColor> getColors();
    QColor MakeRandomColor();
};

#endif // FIGURE_H
