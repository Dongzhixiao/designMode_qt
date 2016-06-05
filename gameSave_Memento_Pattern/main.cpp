#include "gamerole.h"
#include <QtDebug>

int main(int argc, char *argv[])
{
    //大战前
    GameRole *gr = new GameRole();
    gr->setAttack(100);gr->setDefense(100);gr->setVitality(100);
    qDebug()<<"初始";
    gr->stateDisplay();

    //保存进度
    RoleStateCaretaker *roleAdm = new RoleStateCaretaker();
    roleAdm->setRoleStateMemento(*gr->SaveState());

    //大战boss，损失严重
    gr->setAttack(50);gr->setDefense(50);gr->setVitality(50);
    qDebug()<<"大战后";
    gr->stateDisplay();

    //恢复之前状态
    gr->RecoveryState(roleAdm->getRoleStateMemento());
    qDebug()<<"读取存档后";
    gr->stateDisplay();
    return 0;
}
