#include "nextfigure.h"
#include <qevent.h>

NextFigure::NextFigure(QWidget *parent) : QWidget(parent) {
    tooltip = new Figure(0,0);
    cell = QApplication::desktop()->screenGeometry().width()/80;
    setFixedHeight(cell*5+4);
    setFixedWidth(cell*5+2);
}

void NextFigure::paintTooltip(Figure *source) {
    tooltip = source;
    repaint();
}
void NextFigure::paintEvent(QPaintEvent *event) {    
    QPainter painter(this);    
    for (uint i=0; i<5; i++) {
        for (uint j=0; j<5; j++) {
            painter.fillRect(j*cell, i*cell, (cell-2), (cell-2), QBrush(emptyCell));
        }
    }
    for (int k=0; k<=2; k++)
        painter.fillRect(2*cell, (k+1)*cell, (cell-2), (cell-2),QBrush((tooltip)->getColors()[k]));   
}
