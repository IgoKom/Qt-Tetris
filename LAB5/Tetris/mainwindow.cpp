#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox aboutWindow(QMessageBox::Question, "About", "C++, Qt. Practice work #5", QMessageBox::Ok, this);
    aboutWindow.exec();
}


