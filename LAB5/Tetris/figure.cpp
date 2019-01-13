#include "figure.h"

Figure::Figure(uint r, uint c) {
    m_i = r;
    m_j = c;
    fig.resize(3);
    fig.fill(emptyCell);
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
   switch(rand()%6) {
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
void Figure::paintFigure(QPainter& painter){
    painter.fillRect(m_j*W, m_i*W, (W-2), (W-2), QBrush(fig[0]));
    painter.fillRect(m_j*W, (m_i+1)*W, (W-2), (W-2), QBrush(fig[1]));
    painter.fillRect(m_j*W, (m_i+2)*W, (W-2), (W-2), QBrush(fig[2]));
}
