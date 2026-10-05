#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_dino_clicked()
{
    ui->GraphicsDisplay->pos = 0;
    ui->GraphicsDisplay->mode =1;
    ui->GraphicsDisplay->repaint();
}


