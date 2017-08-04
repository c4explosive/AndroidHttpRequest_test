#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QUrl>
#include <QNetworkAccessManager>
#include <QUrlQuery>
#include <QNetworkReply>
#include <QDebug>
#include <QString>
#include <QJsonDocument>

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

    void on_btn_POST_clicked();
    QString finished(QNetworkReply*);

    void on_btn_GET_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
