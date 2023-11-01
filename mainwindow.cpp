#include "mainwindow.hpp"
#include "ui_mainwindow.h"

// based on: https://github.com/tobiasThomer/Joypad-Widget

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(clickMenuButton()));


    // RPYT
    // -1 ... +1 to 1000 ... 2000

    connect(ui->widget, &JoyPad::xChanged, this, [this](float x){
        std::cout << "joy1: x: " << x << " y: " << ui->widget->y() << std::endl;
        // yaw
        shmrc.set(2, 1500 + (x*500));
    });


    connect(ui->widget, &JoyPad::yChanged, this, [this](float y){
        std::cout << "joy1: x: " << ui->widget->x() << " y: " << y << std::endl;
        // throttle
        shmrc.set(3, 1500 + (y*500));
    });

    connect(ui->widget_2, &JoyPad::xChanged, this, [this](float x){
        std::cout << "joy2: x: " << x << " y: " << ui->widget->y() << std::endl;
        // roll
        shmrc.set(0, 1500 + (x * 500));
    });


    connect(ui->widget, &JoyPad::yChanged, this, [this](float y){
        std::cout << "joy2: x: " << ui->widget->x() << " y: " << y << std::endl;
        // pitch
        shmrc.set(1, 1500 + (y * 500));
    });
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
