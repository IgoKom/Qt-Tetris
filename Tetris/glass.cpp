#include "glass.h"

Glass::Glass(QWidget *parent) : QWidget(parent) {
    qDebug()<< "*";
    gameOn = false;
    score = 0;
    timerInterval = 0;
    idTimer =0;
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
    timerInterval = 500;
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
    emit drawPattern(next);
    idTimer = startTimer(timerInterval);
    setFocus();
    repaint();
}

void Glass::fillGlass() {
    uint arI[2] = {};
    (cur)->getIndices(arI);
    for (int i=0; i<=2; i++) glassArray[arI[0]+i][arI[1]] = (cur)->getColors()[i];
    int r=100;
    do {
        r = glassScan();
    } while(r==2);
    if(r==1) {
        Figure* tmp = cur;
        cur = next;
        next = tmp;
        next->setIndices(0, columns()/2);
        next->MakeRandomColors();
        emit drawPattern(next);
    }
    else {
        killTimer(idTimer);
        gameOn =false;
        QMessageBox MesWindow(QMessageBox::Question, "gamover", "WASTED", QMessageBox::Ok, this);
        MesWindow.exec();

        //emit gamover();
    }
    repaint();
}

bool Glass::refresh() {
    bool wasMoved=false;
    //do {
        //wasMoved=false;
        for (uint i=rows()-1; i>0; i--) {
            for (uint j=0; j<columns(); j++) {
                if(glassArray[i][j]==emptyCell && glassArray[i-1][j]!=emptyCell) {
                    glassArray[i][j]=glassArray[i-1][j];
                    glassArray[i-1][j]=emptyCell;
                    wasMoved=true;
                }
            }
        }
    //} while(wasMoved);
        return wasMoved;
}

int Glass::glassScan() {
    uint top = rows()-1, horEqCel =0;
    QList<QPair<int,int>> collectionForDel;
    for (uint j=0; j<columns(); j++) {
        horEqCel =1;
        for (uint i=rows()-1; i>0; i--) {
            if(i<rows()-1 && glassArray[i][j]!=emptyCell && glassArray[i+1][j]==glassArray[i][j])
                horEqCel+=1;
            else horEqCel=1;


            if(horEqCel>=3) {
                for (uint a=0; a<horEqCel; a++)
                    collectionForDel.append(QPair<int,int>(i+a,j));
            }
        }
    }
    for (uint i=0; i<rows(); i++) {
        horEqCel =1;
        for (uint j=0; j<columns(); j++) {
            //painter.fillRect(j*W, i*W, (W-2), (W-2), QBrush(glassArray[i][j]));
            if(glassArray[i][j]!=emptyCell && top>i && j== columns()/2)
                top = i;    //gamover
            if(j>0 && glassArray[i][j]!=emptyCell && glassArray[i][j-1]==glassArray[i][j])
                horEqCel+=1;
            else horEqCel=1;
            if(horEqCel>=3) {
                for (uint a=1; a<=horEqCel; a++)
                    collectionForDel.append(QPair<int,int>(i,j+1-a));
            }
        }
    }
    if(collectionForDel.size()) {
        QThread::msleep(1000);
        QPair<int,int> cell;
        foreach (cell, collectionForDel) {
            glassArray[cell.first][cell.second] = emptyCell;
        }
        repaint();
    }
    if(top<=3) return 0;
    else if (refresh()) return 2;
    else return 1;
}

bool Glass::leftSideFreeSpaceAv() {
    uint arI[2] = {};
    cur->getIndices(arI);
    if(arI[1]>0 &&  glassArray[arI[0]][arI[1]-1]==emptyCell &&
                    glassArray[arI[0]+1][arI[1]-1]==emptyCell &&
                    glassArray[arI[0]+2][arI[1]-1]==emptyCell) return true;
    else return false;
}

bool Glass::rightSideFreeSpaceAv() {
    uint arI[2] = {};
    cur->getIndices(arI);
    if(arI[1]<(columns()-1) &&  glassArray[arI[0]][arI[1]+1]==emptyCell &&
                                glassArray[arI[0]+1][arI[1]+1]==emptyCell &&
                                glassArray[arI[0]+2][arI[1]+1]==emptyCell) return true;
    else return false;
}

void Glass::timerEvent(QTimerEvent*event) {
    if(gameOn) {
        uint arI[2] = {};
        cur->getIndices(arI);
        //uint i = arI[0]+3;
        if(arI[0]+3<rows() && glassArray[arI[0]+3][arI[1]] == emptyCell) {
            //i++;
            cur->setIndices(arI[0]+1, arI[1]);
            //QThread::msleep(10);
            repaint();
        }
        else {
            killTimer(idTimer);
            fillGlass();
            idTimer = startTimer(timerInterval);
        }
    }
}

void Glass::keyPressEvent(QKeyEvent *event) {
    if(gameOn) {
        uint arI[2] = {};
        cur->getIndices(arI);
        switch(event->key()) {
            case Qt::Key_Left:
                //если есть «куда», перемещаем фигурку влево
                if(leftSideFreeSpaceAv()) cur->setIndices(arI[0], arI[1]-1);
                break;
            case Qt::Key_Right:
                if(rightSideFreeSpaceAv()) cur->setIndices(arI[0], arI[1]+1);
                break;
            case Qt::Key_Down:
                cur->shiftColors(true);
                break;
            case Qt::Key_Up:
                cur->shiftColors(false);
                break;
            case Qt::Key_Space: {
                uint i = arI[0]+3;
//                glassArray[0][0] = Qt::red;
//                glassArray[1][0] = Qt::red;
//                glassArray[2][0] = Qt::red;
//                glassArray[16][0] = Qt::red;
//                glassArray[17][0] = Qt::red;
//                glassArray[18][0] = Qt::red;
//                glassArray[19][0] = Qt::red;
//                glassArray[22][0] = Qt::red;
//                glassArray[23][0] = Qt::red;
//                glassArray[24][0] = Qt::red;
                while(i<rows() && glassArray[i][arI[1]] == emptyCell) {
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

