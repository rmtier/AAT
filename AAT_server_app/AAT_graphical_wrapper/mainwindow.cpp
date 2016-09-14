#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../dyn_lib_aligment_core/include/aat.h"

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

void MainWindow::on_querry_com_box_currentIndexChanged(const QString &arg1)
{

}

void MainWindow::on_second_querry_comb_box_currentIndexChanged(const QString &arg1)
{

}

void MainWindow::on_run_button_clicked()
{
    AAT::AatCore aat;

    aat.Run();
}

