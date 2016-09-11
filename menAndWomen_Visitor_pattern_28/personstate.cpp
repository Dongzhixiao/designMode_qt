#include "personstate.h"

void Success::getManConclusion(Man *concreteElementA)
{
    qDebug()<<concreteElementA->getName()<<getName()<<"时，背后多半有一个伟大的女人！";
}
void Success::getWomanConclusion(Woman *concreteElementB)
{
    qDebug()<<concreteElementB->getName()<<getName()<<"时，背后多半有一个不成功的男人！";
}
void Failing::getManConclusion(Man *concreteElementA)
{
    qDebug()<<concreteElementA->getName()<<getName()<<"时，闷头喝酒，谁也不用劝！";
}
void Failing::getWomanConclusion(Woman *concreteElementB)
{
    qDebug()<<concreteElementB->getName()<<getName()<<"时，泪眼汪汪，谁也劝不了！";
}
void Amativeness::getManConclusion(Man *concreteElementA)
{
    qDebug()<<concreteElementA->getName()<<getName()<<"时，凡事不懂也要装懂！";
}
void Amativeness::getWomanConclusion(Woman *concreteElementB)
{
    qDebug()<<concreteElementB->getName()<<getName()<<"时，遇事懂装作不懂！";
}
