#include "mainwindow.h"
#include "processcontrol.h"
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
{
    //add buttons
    this->wdg = new QWidget(this);
    QVBoxLayout *vlay = new QVBoxLayout(wdg);
//    QPushButton *btn1 = new QPushButton("btn1");
    this->btn1 = new QPushButton("Scan Object");
    vlay->addWidget(this->btn1);
    this->btn2 = new QPushButton("Detect object");
    vlay->addWidget(btn2);
    this->btn3 = new QPushButton("Start continuous detection");
    this->btn3->setCheckable(true);
    vlay->addWidget(btn3);
    this->textfield = new QPlainTextEdit();
//    this->textfield->setReadOnly(true);
    vlay->addWidget(this->textfield);
    wdg->setLayout(vlay);
    setCentralWidget(wdg);
    //connect
    this->myTimer = new QTimer();
    connect(btn1, SIGNAL(clicked()), this, SLOT(btn1_clicked()));
    connect(btn2, SIGNAL(clicked()), this, SLOT(btn2_clicked()));
    connect(btn3, SIGNAL(clicked()), this, SLOT(btn3_clicked()));
    connect(myTimer,SIGNAL(timeout()), this, SLOT(timerfire()));
    //start process when opening main window:
    printStatus();
}
void MainWindow::btn1_clicked(){
//    proc.m_Status << "Trigger...\n";
//    printStatus();
    proc.ScanObject();
    printStatus();
}
void MainWindow::btn2_clicked(){
    proc.DetectObject();

}
void MainWindow::btn3_clicked(){
    if( btn3->isChecked()){
        btn3->setText("Stop continuous detection");
        this->btn1->setEnabled(false);
        this->btn2->setEnabled(false);
        this->myTimer->start(50);
        proc.m_Status <<"Continuous trigger...\n";
        printStatus();
    }
    else{
        btn3->setText("Start continuous detection");
        this->myTimer->stop();
        this->btn1->setEnabled(true);
        this->btn2->setEnabled(true);
        proc.m_Status << "...stopped.\n";
        printStatus();
    }
}
void MainWindow::timerfire(){
    proc.Trigger();
}
void MainWindow::printStatus(){
    this->textfield->setPlainText(QString::fromStdString(proc.m_Status.str()));
    wdg->update();
}
