#ifndef DRAWIT
#define DRAWIT
#include <QWidget>
#define use_sharedPtr

#include <QPaintEvent>
#include <QPen>
#include <QtDebug>

class DrawIt:public QWidget
{
public:
    explicit DrawIt(QWidget *parent=0);
    ~DrawIt();
    void setPen(QPen *);
protected:
    virtual void paintEvent(QPaintEvent *e) Q_DECL_OVERRIDE;
    virtual void drawHead(QPainter *)=0;
    virtual void drawBody(QPainter *)=0;
    virtual void drawArm(QPainter *)=0;
    virtual void drawLeg(QPainter *)=0;
private:
#ifdef use_sharedPtr
    QSharedPointer<QPen> _pen;
#else
    QPen *_pen;
#endif
};

class DrawThinPerson final:public DrawIt
{
protected:
    void drawHead(QPainter *) override;
    void drawBody(QPainter *) override;
    void drawArm(QPainter *) override;
    void drawLeg(QPainter *) override;
};

class DrawFatPerson final:public DrawIt
{
protected:
    void drawHead(QPainter *) override;
    void drawBody(QPainter *) override;
    void drawArm(QPainter *) override;
    void drawLeg(QPainter *) override;
};

//下面是最重要的指挥者类
class PersonDirector
{
public:
    explicit PersonDirector(QString s)
    {
        if(s == "thin")
            _draw = new DrawThinPerson();
        else if(s=="fat")
            _draw = new DrawFatPerson();
        else
        {
            qDebug()<<"undefined input";
            throw 1;
        }
    }
//    ~PersonDirector()   //这个类就是为了返回其内建的一个DrawIt，因此不用析构掉，否则main中delete后就会窗口消失！！！
//    {
//        if(_draw != NULL)
//            delete _draw;
//        _draw = NULL;
//    }

    DrawIt* creatPersonDraw()
    {
        return _draw;
    }

private:
    DrawIt *_draw;
};

#endif // DRAWIT
