#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QValidator>
#include <QRegExp>

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->scannerType = Scanner::ScannerType::TCP;

    connect(ui->radioButtonTCPScan, SIGNAL(clicked()), this, SLOT(radioButtonTCPScanClicked()));
    connect(ui->radioButtonUDPScan, SIGNAL(clicked()), this, SLOT(radioButtonUDPScanClicked()));
    connect(ui->radioButtonICMPScan, SIGNAL(clicked()), this, SLOT(radioButtonICMPScanClicked()));

    connect(ui->pushButtonScan, SIGNAL(clicked()), this, SLOT(pushButtonScanButtonClicked()));

    lineEditPortFirst   = ui->lineEditPortFirst;
    lineEditPortLast    = ui->lineEditPortLast;
    lineEditIP          = ui->lineEditIP;

    lineEditPortFirst->setValidator(new QIntValidator(1, 65535, this));
    lineEditPortLast->setValidator(new QIntValidator(1, 65535, this));

    QRegExp regex(QString::fromStdString(MainWindow::IP_REGEX));
    lineEditIP->setValidator(new QRegExpValidator(regex));

    // @TODO add tcp and udp scanners enable radio buttons
    ui->radioButtonTCPScan->setEnabled(false);
    ui->radioButtonUDPScan->setEnabled(false);
    enablePortInputs(false);
    ui->radioButtonICMPScan->setChecked(true);

    // QTreeWidget item example
    QTreeWidget * tree = ui->treeWidget;
    QTreeWidgetItem * topLevel = new QTreeWidgetItem();
    topLevel->setText(0, "192.168.1.1");

    for(int i=0; i<5; i++)
    {
        QTreeWidgetItem * item = new QTreeWidgetItem();
        item->setText(0,"item " + QString::number(i+1));
        topLevel->addChild(item);
    }

    tree->addTopLevelItem(topLevel);
    tree->expandAll();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::enablePortInputs(bool status) {
    lineEditPortFirst->setEnabled(status);
    lineEditPortLast->setEnabled(status);
}

void MainWindow::radioButtonTCPScanClicked() {
    scannerType = Scanner::ScannerType::TCP;
    std::cout << "TCP Clicked" << std::endl;
    enablePortInputs(true);
}

void MainWindow::radioButtonUDPScanClicked() {
    scannerType = Scanner::ScannerType::UDP;
    std::cout << "UDP Clicked" << std::endl;
    enablePortInputs(true);
}

void MainWindow::radioButtonICMPScanClicked() {
    scannerType = Scanner::ScannerType::ICMP;
    std::cout << "ICMP Clicked" << std::endl;
    enablePortInputs(false);
}

void MainWindow::pushButtonScanButtonClicked() {
    QString ipRange = lineEditIP->text();
    QRegularExpression re(QString::fromStdString(IP_REGEX));
    QRegularExpressionMatch match = re.match(ipRange);

    if( !ipRange.isEmpty()) {
        if(match.hasMatch()) {
            // @TODO: create threads for scanning

        }
        else {
            std::cout << "Sorry.. this is not an IP" << std::endl;
        }
    }
    std::cout << "clicked scan button" << std::endl;
}

const std::string MainWindow::IP_REGEX = "(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])";
