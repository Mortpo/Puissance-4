#ifndef QOBJECT_H
#define QOBJECT_H

#include <QObject>

class QObject : public QObject
{
    Q_OBJECT
public:
    explicit QObject(QObject *parent = nullptr);

signals:

};

#endif // QOBJECT_H
