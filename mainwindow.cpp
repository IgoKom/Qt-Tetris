#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->pause->setCheckable(true);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_actionAbout_triggered() {
    ui->widget->gamover();
    ui->pause->setChecked(true);
    QMessageBox aboutWindow(QMessageBox::Question, "About", "This program was written for Milana", QMessageBox::Ok, this);
    aboutWindow.exec();
}

void MainWindow::on_actionStart_Game_triggered() {
    ui->widget->slotNewGame();
}

void MainWindow::on_actionExit_triggered() {
    ui->pushButton->clicked();
}

