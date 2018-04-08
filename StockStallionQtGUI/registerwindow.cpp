#include "registerwindow.h"
#include "ui_registerwindow.h"
#include <QMouseEvent>

RegisterWindow::RegisterWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);

    //Make Window transparent and frameless
    Qt::WindowFlags flags = windowFlags();
    setWindowFlags(flags | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    QWidget::setFixedSize(RegisterWindow::width(), RegisterWindow::height());

    RegisterWindow::setCentralWidget(ui->windowFrame);

    //Colors the top portion of the window blue
    ui->windowFrame->setObjectName("windowFrame");
    ui->windowFrame->setStyleSheet(" #windowFrame {background-color: qlineargradient(x1:0, x2: 0, y1: 0, y2: .5, stop: 0 #84A9FF, stop: 0.205 #84A9FF, stop: 0.2051 white, stop: 1 white); border-radius:5px; border:1px solid black}");

    //Stock Stallion Logo
    QPixmap logo("StockStallion Images\\Login Form\\stallionLogoWhite.png");
    ui->stockStallionLogo->setPixmap(logo.scaled(ui->stockStallionLogo->width(), ui->stockStallionLogo->height(), Qt::KeepAspectRatio));

}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_pushButton_2_clicked()
{
    this->close();
}

void RegisterWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        isMouseDown = true;

        QRect pos = geometry();
        offset = new QPoint(event->globalPos().x() - pos.x(), event->globalPos().y() - pos.y());
    }
}

void RegisterWindow::mouseReleaseEvent(QMouseEvent *event)
{
    isMouseDown = false;
    offset = 0;
}

void RegisterWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(isMouseDown)
    {
        QPoint *newPoint = new QPoint(event->globalPos().x() - offset->x(), event->globalPos().y() - offset->y());
        move(*newPoint);
    }
}

void RegisterWindow::on_registerButton_pressed()
{
    ui->registerButton->setStyleSheet("background-color: Silver;"
                                   "border-style: solid;"
                                   "border-width:2px;"
                                   "border-radius:7px;"
                                   "border-color: black;"
                                   "font: 12pt \"Century Gothic\"");
}

void RegisterWindow::on_registerButton_released()
{
    ui->registerButton->setStyleSheet("background-color: Gainsboro;"
                                   "border-style: solid;"
                                   "border-width:2px;"
                                   "border-radius:7px;"
                                   "border-color: black;"
                                   "font: 12pt \"Century Gothic\"");
}

void RegisterWindow::on_registerButton_clicked()
{
    ui->usernameErrorLabel->setStyleSheet("color: red");
    ui->emailErrorLabel->setStyleSheet("color: red");
    ui->passwordErrorLabel->setStyleSheet("color: red");
    ui->passwordConfirmErrorLabel->setStyleSheet("color: red");
}
