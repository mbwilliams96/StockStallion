#ifndef STOCKSTALLIONWINDOW_H
#define STOCKSTALLIONWINDOW_H

#include <QMainWindow>

namespace Ui {
class StockStallionWindow;
}

class StockStallionWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StockStallionWindow(QWidget *parent = 0);
    ~StockStallionWindow();

private:
    Ui::StockStallionWindow *ui;
};

#endif // STOCKSTALLIONWINDOW_H
