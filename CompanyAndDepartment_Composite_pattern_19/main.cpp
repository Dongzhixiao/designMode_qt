#include "company.h"

int main(int argc, char* argv[])
{
    Q_UNUSED(argc); Q_UNUSED(argv);

    ConcreteCompany root("北京总公司");
    root.Add(new HRDepartment("总公司人力资源部"));
    root.Add(new FinanceDepartment("总公司财务部"));

    ConcreteCompany *comp = new ConcreteCompany("上海华东分公司");
    comp->Add(new HRDepartment("华东分公司人力资源部"));
    comp->Add(new FinanceDepartment("华东分公司财务部"));
    root.Add(comp);

    ConcreteCompany *comp1 = new ConcreteCompany("南京办事处");
    comp1->Add(new HRDepartment("南京办事处人力资源部"));
    comp1->Add(new FinanceDepartment("南京办事处公司财务部"));
    root.Add(comp1);

    ConcreteCompany *comp2 = new ConcreteCompany("杭州办事处");
    comp2->Add(new HRDepartment("杭州办事处人力资源部"));
    comp2->Add(new FinanceDepartment("杭州办事处公司财务部"));
    root.Add(comp2);

    qDebug()<<"结构图：";
    root.Display(1);
    qDebug()<<"职责：";
    root.LineOfDuty();

    return 0;
}
