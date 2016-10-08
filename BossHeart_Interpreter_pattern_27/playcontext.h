#ifndef PLAYCONTEXT_H
#define PLAYCONTEXT_H

#include <QString>
#include <QDebug>

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
        if(context->GetPlayText().length() == 0)
            return;
        else
        {
            QString playKey = context->GetPlayText().section(' ',0);
            int playValue = context->GetPlayText().section(' ',1).toInt();
            context->SetPlayText(context->GetPlayText().section(' ',2,-1));

            Excute(playKey,playValue);
        }
    }
    virtual void Excute(QString,int) = 0;
};

class Note final : public Expression   //音符类
{
public:
    void Excute(QString key,int value) override
    {
        QString note;
        if(key == "C")
            note = '1';
        else if(key == "D")
            note = '2';
        else if(key == "E")
            note = '3';
        else if(key == "F")
            note = '4';
        else if(key == "G")
            note = '5';
        else if(key == "A")
            note = '6';
        else if(key == "B")
            note = '7';

        qDebug()<<note;
    }
};

class Scale final : public Expression   //音符类
{
public:
    void Excute(QString key,int value) override
    {
        QString scale;

        switch (value) {
        case 1:
            scale = "低音";
            break;
        case 2:
            scale = "中音";
            break;
        case 3:
            scale = "高音";
            break;
        default:
            break;
        }

        qDebug()<<scale;
    }
};


#endif // PLAYCONTEXT_H
