#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:    

private slots:
    void on_actionAbout_triggered();
    void on_actionStart_Game_triggered();
    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
