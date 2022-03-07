#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(showTime()));
    timer->start();

    QDate date = QDate::currentDate();
    QString dateTimeText = date.toString();
    ui->date->setText(dateTimeText);

    QTimer *moscowClock = new QTimer(this);
    connect(moscowClock, SIGNAL(timeout()),this, SLOT(showTime()));
    moscowClock->start();
}

void MainWindow::showTime()
{
    QTime localTime = QTime::currentTime();
    QTime moscowTime = localTime.addSecs(39600);
    QString time_text2 = moscowTime.toString("hh : mm : ss");
    if((moscowTime.second() % 2) == 0)
    {
        time_text2[3] = ' ';
        time_text2[8] = ' ';
    }
    ui->moscowClock->setText(time_text2);

    QString time_text = localTime .toString("hh : mm : ss");
    if((localTime.second() % 2) == 0)
    {
        time_text[3] = ' ';
        time_text[8] = ' ';
    }
    ui->Digital_clock->setText(time_text);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_centralwidget_customContextMenuRequested(const QPoint &pos)
{

}

