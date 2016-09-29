#ifndef MANAGER_H
#define MANAGER_H

#include <QString>
#include <QSharedPointer>

class Request
{
public:
    QString getRequestType(){return _requestType;}
    void setRequestType(QString requestType){_requestType = requestType;}
    QString getRequestContent(){return _requestContent;}
    void setRequestContent(QString requestContent){_requestContent = requestContent;}
    int getNumber(){return _number;}
    void setNumber(int number){_number = number;}
private:
    QString _requestType;
    QString _requestContent;
    int _number;
};

class Manager
{
public:
    explicit Manager(QString name)
    {
        _name = name;
    }
    void setSuperior(Manager* superior)
    {
        _superior = QSharedPointer<Manager>(superior);
    }
    virtual void RequestApplications(const Request &) = 0;
    virtual ~Manager(){}
protected:
    QString _name;
    QSharedPointer<Manager> _superior;
};



#endif // MANAGER_H
