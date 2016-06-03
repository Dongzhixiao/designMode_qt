#include "drawit.h"
#include <QPen>
#include <QPainter>

DrawIt::DrawIt(QWidget *paretn)
{
    _pen = new QPen(QColor(255,0,0,255));
}
DrawIt::~DrawIt()
{
    if(_pen != NULL)
    {
        delete _pen;
        _pen = NULL;
    }
}
void DrawIt::setPen(QPen *p)
{
    if(_pen != NULL)
        delete _pen;
    _pen = p;
}

void DrawIt::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setPen(*_pen);
    painter.setBrush(QBrush(Qt::SolidPattern));
    drawArm(&painter);
    drawBody(&painter);
    drawHead(&painter);
    drawLeg(&painter);
}


void DrawThinPerson::drawHead(QPainter *p)
{
    p->drawEllipse(50,20,30,30);
}
void DrawThinPerson::drawBody(QPainter *p)
{
    p->drawRect(60,50,10,50);
}
void DrawThinPerson::drawArm(QPainter *p)
{
    p->drawLine(60,50,40,100);
    p->drawLine(70,50,90,100);
}
void DrawThinPerson::drawLeg(QPainter *p)
{
    p->drawLine(60,100,45,150);
    p->drawLine(70,100,85,150);
}


void DrawFatPerson::drawHead(QPainter *p)
{
    p->drawEllipse(50,20,30,30);
}
void DrawFatPerson::drawBody(QPainter *p)
{
    p->drawEllipse(45,50,40,50);
}
void DrawFatPerson::drawArm(QPainter *p)
{
    p->drawLine(50,50,30,100);
    p->drawLine(80,50,100,100);
}
void DrawFatPerson::drawLeg(QPainter *p)
{
    p->drawLine(60,100,45,150);
    p->drawLine(70,100,85,150);
}
