#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QApplication>
#include <QMainWindow>
#include <QDialog>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QFormLayout>
#include <QMessageBox>
#include <QTextEdit>
#include <QLabel>
#include "processcontrol.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void printStatus();
//    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QWidget *wdg;
    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;
//    QPlainTextEdit * textfield = new QPlainTextEdit();
    QPlainTextEdit *textfield;
    QTimer* myTimer;
    ProcessControl proc;
private slots:
    void btn1_clicked();
    void btn2_clicked();
    void btn3_clicked();
    void timerfire();
};

//MainWindow::~MainWindow()
//{
//delete ui;
//}
#endif // MAINWINDOW_H



