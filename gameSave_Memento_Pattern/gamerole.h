#ifndef GAMEROLE
#define GAMEROLE
#include <QtDebug>

//角色状态存储箱
class RoleStateMemento
{
public:
    //RoleStateMemento()=default;
    RoleStateMemento(int vit,int atk,int def):_vit(vit),_atk(atk),_def(def){}
    //RoleStateMemento(const RoleStateMemento&)=delete;
    int getVitality(){return _vit;}
    void setVitality(int vit){_vit=vit;}
    int getAttack(){return _atk;}
    void setAttack(int atk){_atk=atk;}
    int getDefense(){return _def;}
    void setDefense(int def){_def=def;}
private:
    int _vit;
    int _atk;
    int _def;
};
//游戏角色
class GameRole
{
public:
    int getVitality(){return _vit;}
    void setVitality(int vit){_vit=vit;}
    int getAttack(){return _atk;}
    void setAttack(int atk){_atk=atk;}
    int getDefense(){return _def;}
    void setDefense(int def){_def=def;}
    RoleStateMemento *SaveState(){return new RoleStateMemento(_vit,_atk,_def);}
    void RecoveryState(RoleStateMemento me){_vit=me.getVitality();_atk=me.getAttack();_def=me.getDefense();}
    void stateDisplay()
    {
        qDebug()<<"角色当前状态：";
        qDebug()<<"体力："<<_vit;
        qDebug()<<"攻击力："<<_atk;
        qDebug()<<"防御力："<<_def;
    }
private:
    int _vit;
    int _atk;
    int _def;
};
//角色状态管理者
class RoleStateCaretaker
{
public:
    RoleStateCaretaker(int vit=0,int atk=0,int def=0):_meto(RoleStateMemento(vit,atk,def)){}
    void setRoleStateMemento(RoleStateMemento meto){_meto=meto;}
    RoleStateMemento getRoleStateMemento(){return _meto;}
private:
    RoleStateMemento _meto;
};

#endif // GAMEROLE

