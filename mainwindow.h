#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QLineEdit>
#include <string>
#include "scanner.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void enablePortInputs(bool status);

private slots:
    void radioButtonTCPScanClicked();
    void radioButtonUDPScanClicked();
    void radioButtonICMPScanClicked();

    void pushButtonScanButtonClicked();
private:
    Ui::MainWindow *ui;
    Scanner::ScannerType scannerType;
    QLineEdit *lineEditPortFirst, *lineEditPortLast, *lineEditIP;

    static const std::string IP_REGEX;
};

#endif // MAINWINDOW_H
