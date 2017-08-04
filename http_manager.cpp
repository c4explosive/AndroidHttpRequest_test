#include "http_manager.h"


http_manager::http_manager()
{

}

QString http_manager::http_post_get(QString zquery, int mode)
{
    myURL = new QUrl(QString("http://127.0.0.1:3000/api/viewall"));
    request = new QNetworkRequest(*myURL);
    params.setPath("zquery="+zquery);
    switch (mode) {
    case 0:
        reply = nmgr.post(*request,params.toEncoded());
        break;
    case 1:
        reply = nmgr.get(*request);
        break;
    default:
        break;
    }
    QObject::connect(&nmgr,SIGNAL(finished(QNetworkReply*)),&eventLoop,SLOT(quit()));
    eventLoop.exec();
    response = QObject::tr(reply->readAll());
    qDebug() << "In String" << response;
    return response;
}
