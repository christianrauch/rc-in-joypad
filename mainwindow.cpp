#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // DBG
    shmrc.set({300,400,500,600,0,0,0,0});
}

MainWindow::~MainWindow()
{
    delete ui;
}

