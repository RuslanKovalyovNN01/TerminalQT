#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fileutils.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    chrt = new QChart();
    ui-> vchrt1 ->setChart(chrt);
    chrt->setTitle("Magnetometer");

    QValueAxis *axisX = new QValueAxis;
    axisX->setRange(0,100);
    axisX->setTickCount(11);
    axisX->setLabelFormat("%.2f");

    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(-10.5, 10.5);
    axisY->setTickCount(3);
    axisY->setLabelFormat("%g");

    QLineSeries* series1 = new QLineSeries();

    Generator generator(100);
    std::vector<int> test_data = generator.generate_sawtooth();
    for(int i = 0; i < 100; i++){
        series1->append(i,test_data[i]);
    }
    chrt->addSeries(series1);
    chrt->setAxisX(axisX,series1);
    chrt->setAxisY(axisY,series1);

    acc_chrt = new QChart();
    ui->acc_vchrt -> setChart(acc_chrt);
    acc_chrt->setTitle("Accelerometer");

    QValueAxis *accX = new QValueAxis;
    accX->setRange(0,100);
    accX->setTickCount(11);
    accX->setLabelFormat("%.2f");

    QValueAxis *accY = new QValueAxis;
    accY->setRange(-10.5, 10.5);
    accY->setTickCount(3);
    accY->setLabelFormat("%g");

    QLineSeries* acc_series = new QLineSeries();
    std::vector<int> acc_test_data = generator.generate_sawtooth();
    for(int i = 0; i < 100; i++){
        acc_series->append(i,test_data[i]);
    }
    acc_chrt->addSeries(acc_series);
    acc_chrt->setAxisX(accX,acc_series);
    acc_chrt->setAxisY(accY,acc_series);
}

MainWindow::~MainWindow()
{
    delete ui;
}
