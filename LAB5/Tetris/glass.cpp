#include "glass.h"

#include <QThread>


Glass::Glass(QWidget *parent) : QWidget(parent) {
    qDebug()<< "*";
    gameOn = false;
    score = 0;
    timerInterval = 0;
  //  glassArray.clear();
    setColumns(0);
    setRows(0);
    cur = new Figure(0, 0);
    next = new Figure(0, 0);
    connect(this, &Glass::signalGlassInit, this, &Glass::slotGlassInit, Qt::QueuedConnection);
    emit signalGlassInit();
}

void Glass::slotGlassInit() {

    glassArray.resize(rows());
    for (uint i=0; i<rows(); i++) {
        glassArray[i].resize(columns());
    }
    clearGlass();
    QSize s = calcGlassSize();
    setFixedSize(s);
    qDebug()<< s;
}

void Glass::clearGlass() {
    for (uint i=0; i<rows(); i++) {
//        for (uint j=0; j<columns(); j++) {
//            glassArray[i][j] = emptyCell;
//        }
        glassArray[i].fill(emptyCell);
    }
    score = 0;
    timerInterval = 10;
}

QSize Glass::calcGlassSize() {
    return QSize(W*columns(), W*rows());
}

void Glass::paintEvent(QPaintEvent*event) {
    QPainter painter(this);
    //painter.SetBrush();
    //painter.drawRect();
    for (uint i=0; i<rows(); i++) {
        for (uint j=0; j<columns(); j++) {
            painter.fillRect(j*W, i*W, (W-2), (W-2), QBrush(glassArray[i][j]));
        }
    }
    if(gameOn) {
        cur->paintFigure(painter);
    }
}

void Glass::slotNewGame() {
    gameOn = true;
    clearGlass();
    cur->setIndices(0, columns()/2);
    cur->MakeRandomColors();
    next->setIndices(0,columns()/2);
    next->MakeRandomColors();
// emit paint
    //QTimer sdc
    setFocus();
    repaint();
}

void Glass::fillGlass() {
    uint arI[2] = {};
    (cur)->getIndices(arI);
    for (int i=0; i<=2; i++) glassArray[arI[0]+i][arI[1]] = (cur)->getColors()[i];
    if(gameOn){
        Figure* tmp = cur;
        cur = next;
        next = tmp;
        next->setIndices(0, columns()/2);
        next->MakeRandomColors();
    }
    repaint();
}

void Glass::keyPressEvent(QKeyEvent *event) {
    if(gameOn) {
        uint arI[2] = {};
        cur->getIndices(arI);
        switch(event->key()) {
            case Qt::Key_Left:
                //если есть «куда», перемещаем фигурку влево
                if(arI[1]>0) cur->setIndices(arI[0], arI[1]-1);
                break;
            case Qt::Key_Right:
                if(arI[1]<(columns()-1)) cur->setIndices(arI[0], arI[1]+1);
                break;
            case Qt::Key_Down:
                cur->shiftColors(true);
                break;
            case Qt::Key_Up:
                cur->shiftColors(false);
                break;
            case Qt::Key_Space: {
                uint i = arI[0]+3;
                glassArray[19][4] = Qt::red;
                while(i<m_rows && glassArray[i][arI[1]] == emptyCell) {
                    i++;
                    cur->setIndices(i-3, arI[1]);
                    QThread::msleep(10);
                    repaint();
                }
                fillGlass();
                break;
            }
            default: QWidget::keyPressEvent(event); //принажатии любых других клавиш вызываем базовую обработку события
        }
    }
    else QWidget::keyPressEvent(event);
    repaint();
}

