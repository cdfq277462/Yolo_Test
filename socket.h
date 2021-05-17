#ifndef SOCKET_H
#define SOCKET_H

#include <QObject>
#include <QThread>

class socket : public QThread
{
    Q_OBJECT
public:
    socket();

signals:

};

#endif // SOCKET_H
