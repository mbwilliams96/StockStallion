#ifndef STOCKSTALLIONMAINWINDOW_H
#define STOCKSTALLIONMAINWINDOW_H

#include <QDialog>

namespace Ui {
class StockStallionMainWindow;
}

class StockStallionMainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StockStallionMainWindow(QWidget *parent = 0);
    ~StockStallionMainWindow();

private:
    Ui::StockStallionMainWindow *ui;
};

#endif // STOCKSTALLIONMAINWINDOW_H
