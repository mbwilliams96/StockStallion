#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "registerwindow.h"
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Make Window transparent and frameless
    Qt::WindowFlags flags = windowFlags();
    setWindowFlags(flags | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    QWidget::setFixedSize(MainWindow::width(), MainWindow::height());

    MainWindow::setCentralWidget(ui->windowFrame);

    //Colors the top portion of the window blue
    ui->windowFrame->setObjectName("windowFrame");
    ui->windowFrame->setStyleSheet(" #windowFrame {background-color: qlineargradient(x1:0, x2: 0, y1: 0, y2: .5, stop: 0 #84A9FF, stop: 0.29 #84A9FF, stop: 0.2901 white, stop: 1 white); border-radius:5px; border:1px solid black}");

    //Add drop shadow
    //QGraphicsDropShadowEffect* dropShadow = new QGraphicsDropShadowEffect();
    //dropShadow->setBlurRadius(1);
    //ui->frame->setGraphicsEffect(dropShadow);
    
    //Add images to qlabel

    //Stock Stallion Logo
    //QPixmap logo("C:\\Users\\Justin\\Desktop\\StockStallion Images\\Login Form\\stallionLogoWhite.png");
    QPixmap logo("StockStallion Images\\Login Form\\stallionLogoWhite.png");
    ui->stockStallionLogo->setPixmap(logo.scaled(ui->stockStallionLogo->width(), ui->stockStallionLogo->height(), Qt::KeepAspectRatio));

    //Username Icon
    //QPixmap userIcon("C:\\Users\\Justin\\Desktop\\StockStallion Images\\Login Form\\userName.png");
    QPixmap userIcon("StockStallion Images\\Login Form\\userName.png");
    ui->usernameIcon->setPixmap(userIcon.scaled(ui->usernameIcon->width(), ui->usernameIcon->height(), Qt::KeepAspectRatio));

    //Password Icon
    //QPixmap passIcon("C:\\Users\\Justin\\Desktop\\StockStallion Images\\Login Form\\passwordLock.png");
    QPixmap passIcon("StockStallion Images\\Login Form\\passwordLock.png");
    ui->passwordIcon->setPixmap(passIcon.scaled(ui->passwordIcon->width(), ui->passwordIcon->height(), Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        isMouseDown = true;

        QRect pos = geometry();
        offset = new QPoint(event->globalPos().x() - pos.x(), event->globalPos().y() - pos.y());
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    isMouseDown = false;
    offset = 0;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(isMouseDown)
    {
        QPoint *newPoint = new QPoint(event->globalPos().x() - offset->x(), event->globalPos().y() - offset->y());
        move(*newPoint);
    }
}

void MainWindow::on_loginButton_pressed()
{
    ui->loginButton->setStyleSheet("background-color: Silver;"
                                   "border-style: solid;"
                                   "border-width:2px;"
                                   "border-radius:7px;"
                                   "border-color: black;"
                                   "font: 12pt \"Century Gothic\"");
}

void MainWindow::on_loginButton_released()
{
    ui->loginButton->setStyleSheet("background-color: Gainsboro;"
                                   "border-style: solid;"
                                   "border-width:2px;"
                                   "border-radius:7px;"
                                   "border-color: black;"
                                   "font: 12pt \"Century Gothic\"");
}


void MainWindow::on_loginButton_clicked()
{
    //Login debug
    if(ui->usernameTextBox->text() == "Bob" && ui->passwordTextBox->text() == "Pass")
    {
        this->close();
    }
    else
    {
        ui->passwordTextBox->setText("");
        ui->usernameErrorLabel->setStyleSheet("color: red");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_clicked()
{
    this->hide();
    RegisterWindow *registerWindow = new RegisterWindow(this);
    registerWindow->show();
}
