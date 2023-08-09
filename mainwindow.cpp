#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(clickMenuButton()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clickMenuButton()
{
    std::cout << "bam" << std::endl;
    // DBG
    shmrc.set({300,400,500,600,0,0,0,0});
}
