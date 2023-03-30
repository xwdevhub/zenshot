#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QLocalSocket>

class Client : public QObject
{
    Q_OBJECT
public:
    //explicit Client(QObject *parent = nullptr);
    Client(QLocalSocket *qLocalSocket);


signals:

private slots:
    void OnReadyRead();

private:
    QLocalSocket *mLocalSocket;


};

#endif // CLIENT_H
