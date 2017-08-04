#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "http_manager.h"

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
    QString response;
    http_manager* htm = new http_manager();
    response=htm->http_post_get(ui->line_request->text(),0);
    ui->lbl_Response->setText(response);
}


void MainWindow::on_btn_GET_clicked()
{
    QString response;
    http_manager* htm = new http_manager();
    response=htm->http_post_get("back to the future",1);
    ui->lbl_Response->setText(response);

}
