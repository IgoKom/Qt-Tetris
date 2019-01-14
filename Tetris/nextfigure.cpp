#include "nextfigure.h"

NextFigure::NextFigure(QWidget *parent) : QWidget(parent) {
    tooltip = new Figure(0,0);
}

void NextFigure::paintTooltip(Figure *source) {
    tooltip = source;
}
void NextFigure::paintEvent(QPaintEvent *event) {
    QPainter painter(this);    
    for (uint i=0; i<5; i++) {
        for (uint j=0; j<5; j++) {
            painter.fillRect(j*20, i*20, (18), (18), QBrush(emptyCell));            
        }
    }
    for (int i=0; i<=2; i++) painter.fillRect(2*20, i*20, (18), (18),QBrush((tooltip)->getColors()[i]));
}
