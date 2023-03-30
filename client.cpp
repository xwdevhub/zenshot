#include "client.h"
#include "spdlogwrapper.hpp"


Client::Client(QLocalSocket *qLocalSocket):mLocalSocket(qLocalSocket){

    connect(mLocalSocket,SIGNAL(readyRead()),this,SLOT(OnReadyRead()));
}


void Client::OnReadyRead(){

    L_DEBUG("Client::OnReadyRead");
    L_DEBUG("receive data before");
    //mLocalSocket->waitForReadyRead();
    QByteArray  data1= mLocalSocket->readAll();
    std::string astd=  data1.toStdString();

    L_DEBUG("receive data");
    // L_DEBUG("收到的数据");
    L_DEBUG(astd);
    int code=0;
    if(astd=="1"){
        L_DEBUG("astd==1");
        code=1;
    }
    L_DEBUG("code==0");
    mLocalSocket->disconnectFromServer();
    mLocalSocket->close();

    L_TRACE("already running ...");
    exit(code);

}

