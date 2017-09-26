#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   isStartBtnCliked = false;
    m_handpiec = new HandPiecImage();
    m_ImageThread = new ImageProcThread();
    connect(m_handpiec,SIGNAL(send_return_siganl(int)),this,SLOT(accept_return_signal(int)));
    connect(this,SIGNAL(send_MatchImageFileInfo(QString)),m_ImageThread,SLOT(accept_MatchFileInfo(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_SelectFileBtn_clicked()
{
  MatchImageFilePath = QFileDialog::getExistingDirectory();
  send_MatchImageFileInfo(MatchImageFilePath);
}

void MainWindow::on_StartprocessBtn_clicked()
{
    isStartBtnCliked = !isStartBtnCliked;
    if(isStartBtnCliked)
    {
        ui->StartprocessBtn->setText("停止");
        m_ImageThread->start();
    }
    else
    {
        ui->StartprocessBtn->setText("开始");
        m_ImageThread->quit();
    }
}

void MainWindow::on_ExitBtn_clicked()
{
     exit(EXIT_SUCCESS);
}

void MainWindow::on_Hand_Templete_triggered()
{
    m_handpiec->show();
    this->close();
}

void MainWindow::accept_return_signal(int windowNum)
{
    switch(windowNum)
    {
    case 1:
        this->show();
        m_handpiec->close();
        break;
    default:
        break;

    }
}
