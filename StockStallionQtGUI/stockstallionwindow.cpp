#include "stockstallionwindow.h"
#include "ui_stockstallionwindow.h"

StockStallionWindow::StockStallionWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StockStallionWindow)
{
    ui->setupUi(this);
}

StockStallionWindow::~StockStallionWindow()
{
    delete ui;
}
