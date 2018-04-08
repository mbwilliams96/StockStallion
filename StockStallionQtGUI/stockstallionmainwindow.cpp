#include "stockstallionmainwindow.h"
#include "ui_stockstallionmainwindow.h"

StockStallionMainWindow::StockStallionMainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StockStallionMainWindow)
{
    ui->setupUi(this);
}

StockStallionMainWindow::~StockStallionMainWindow()
{
    delete ui;
}
