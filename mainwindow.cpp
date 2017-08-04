#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_btn_POST_clicked()
{
    QUrl myURL(QString("http://192.168.1.101:3000/api/viewall"));
   QNetworkRequest request(myURL);
   QNetworkAccessManager mgr;


   QUrlQuery qu;
   //qu.addQueryItem("unm","auser");

    QUrl params;
    //params.setQuery(qu);
    params.setPath("zquery="+ui->lineEdit->text());
    QNetworkReply *reply = mgr.post(request, params.toEncoded());
    //QNetworkReply *reply = mgr.get(request);



    QEventLoop eventLoop;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    eventLoop.exec();

    //QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)),this,SLOT(finished(QNetworkReply*)));

    QString response = QObject::tr(reply->readAll());
    //qDebug() << "Success" <<reply->readAll();

    qDebug() << "In String" << response;
    ui->lbl_Response->setText(response);
}

QString MainWindow::finished(QNetworkReply* reply)
{
    QString response = QString::fromUtf8(reply->readAll(),reply->readAll().size());

    qDebug() << "In String" << QObject::tr(reply->readAll());
    return response;
}

void MainWindow::on_btn_GET_clicked()
{
    QUrl myURL(QString("http://192.168.1.101:3000/api/viewall"));
   QNetworkRequest request(myURL);
   QNetworkAccessManager mgr;


   QUrlQuery qu;
   //qu.addQueryItem("unm","auser");

    QUrl params;
    //params.setQuery(qu);
    //QNetworkReply *reply = mgr.post(request, params.toEncoded());
    QNetworkReply *reply = mgr.get(request);



    QEventLoop eventLoop;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    eventLoop.exec();

    //QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)),this,SLOT(finished(QNetworkReply*)));

    QString response = QObject::tr(reply->readAll());
    //qDebug() << "Success" <<reply->readAll();

    qDebug() << "In String" << response;
    ui->lbl_Response->setText(response);
}
