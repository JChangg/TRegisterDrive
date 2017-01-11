#include "webservice.h"

void sync_person(Person p)
{
    if (!p.loaded)
    {
        // TODO: throw exceptions
        return;
    }
    QString jsondata("{'value1': 1234}") ;
    QNetworkAccessmanager mngr;

    QNetworkRequest request(__IFTTT_URL);
    request.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));

    QNetworkReply* reply = mngr.put(request, jsondata.toUtf8());
}
