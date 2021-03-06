#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <opencv.hpp>
#include <QFileDialog>
#include <QDir>
#include <QFileInfo>
#include <QList>
#include "handpiecimage.h"
#include "imageprocthread.h"
#include "autopieceimage.h"
using namespace cv;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_SelectFileBtn_clicked();
    void on_StartprocessBtn_clicked();
    void on_ExitBtn_clicked();
    void on_Hand_Templete_triggered();
    void on_actionAuto_Templete_triggered();
public slots:
    void accept_return_signal(int);
    void accept_newtempleteFile(int);
    void accept_dispImage(QImage);
    void accept_sendTime(QString);
    void accept_ishaveGj(bool);
    void accept_templeteImage(QImage);
    void send_singleLineInfo(int,int);
    void send_secondLineInof(Point,Point);
public:
    Point jcpoint_1;
    Point jcpoint_2;
    int time;
    bool ishaveGj;
signals:
    void send_MatchImageFileInfo(QString);
    void send_istempsignals(int);
public:
    HandPiecImage *m_handpiec;
    ImageProcThread *m_ImageThread;
    autoPieceImage *m_autoimage;
    QString MatchImageFilePath;
    QList<QFileInfo> *MatchImageFileInfo;
    int MatchImageNum;
    bool isStartBtnCliked;
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
