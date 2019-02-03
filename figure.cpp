#include "figure.h"
#include <QRandomGenerator>

Figure::Figure(uint r, uint c) {
    m_i = r;
    m_j = c;
    fig.resize(3);
    fig.fill(emptyCell);
    cell = QApplication::desktop()->screenGeometry().width()/80;
}
Figure Figure::operator=(Figure &ref){
    m_i = ref.m_i;
    m_j = ref.m_j;
    for(int i=0; i<3;i++)
            fig[i] = ref.fig[i];
}

void Figure::setIndices(uint r, uint c) {
    m_i = r;
    m_j = c;
}
void Figure::getIndices(uint* indAr) {
    indAr[0]=m_i;
    indAr[1]=m_j;
}
void Figure::shiftColors(bool direction){

    if(direction) {
        QColor tmp = fig[2];
        fig[2] = fig[1];
        fig[1] = fig[0];
        fig[0] = tmp;
    }
    else {
        QColor tmp = fig[0];
        fig[0] = fig[1];
        fig[1] = fig[2];
        fig[2] = tmp;
    }
}

QVector<QColor> Figure::getColors() {
    return fig;
}

QColor Figure::MakeRandomColor() {
   QColor col;
   value1 = QRandomGenerator::global()->generate();
   switch(value1%7) {
       case 0: return Qt::red;
       case 1: return Qt::green;
       case 2: return Qt::blue;
       case 3: return Qt::yellow;
       case 4: return Qt::white;
       case 5: return Qt::black;
       case 6: return Qt::magenta;
       default: return emptyCell;
   }
}

void Figure::MakeRandomColors(){
    fig = {MakeRandomColor(), MakeRandomColor(), MakeRandomColor()};
}

void Figure::CleanFigure()
{
    fig.fill(emptyCell);
}
void Figure::paintFigure(QPainter& painter){
    painter.fillRect(m_j*cell, m_i*cell, (cell-2), (cell-2), QBrush(fig[0]));
    painter.fillRect(m_j*cell, (m_i+1)*cell, (cell-2), (cell-2), QBrush(fig[1]));
    painter.fillRect(m_j*cell, (m_i+2)*cell, (cell-2), (cell-2), QBrush(fig[2]));
}
