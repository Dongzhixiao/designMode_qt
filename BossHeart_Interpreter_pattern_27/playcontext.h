#ifndef PLAYCONTEXT_H
#define PLAYCONTEXT_H

#include <QString>

class PlayContext   //演奏内容类
{
public:
    QString GetPlayText()
    {
        return _text;
    }
    void SetPlayText(QString text)
    {
        _text = text;
    }
private:
    QString _text;
};

class Expression   //表达式类
{
public:
    void Interpret(PlayContext* context)
    {

    }
};

#endif // PLAYCONTEXT_H
