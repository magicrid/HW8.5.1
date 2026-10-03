#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "stopwatch.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    stopwatch = new StopWatch(this);
    ui->setupUi(this);

    ui->pb_circle->setEnabled(false);
    ui->pb_circle->setText("Круг");

    ui->pb_clear->setText("Очистить");

    ui->pb_start->setCheckable(true);
    ui->pb_start->setText("Старт");

    connect(stopwatch, &StopWatch::sig_updateTime, this, &MainWindow::rcv_updateTime);
//    connect(this, &MainWindow::sig_circleTime, stopwatch, &StopWatch::circleTime);
    connect(this, &MainWindow::sig_clearTime, stopwatch, &StopWatch::clearTime);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::rcv_updateTime(QString text)
{
    ui->appLabel->setText(text);
}

void MainWindow::on_pb_start_clicked()
{
    if(ui->pb_start->isChecked()) {

        stopwatch->startTimer();
        ui->pb_start->setText("СТОП");
        ui->pb_circle->setEnabled(true);
    }
    else
    {
        stopwatch->stopTimer();
        ui->pb_start->setText("CTAPT");
        ui->pb_circle->setEnabled(false);
    }
}

void MainWindow::on_pb_circle_clicked()
{
    emit sig_circleTime();
    QString text = stopwatch->getCircleTime();
    ui->appBrowser->append(text);
}

void MainWindow::on_pb_clear_clicked()
{
    ui->appLabel->setText("00:00.0");
    ui->appBrowser->clear();
    emit sig_clearTime();
}
