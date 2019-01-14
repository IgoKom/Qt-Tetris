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
    void gameOver();
private slots:
    void on_actionAbout_triggered();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
