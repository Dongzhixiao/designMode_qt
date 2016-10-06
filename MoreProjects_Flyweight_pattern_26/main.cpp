#include "website.h"

int main()
{
    WebSiteFactory* f = new WebSiteFactory;

    WebSite* fx = f->GetWebSiteCategory("产品展示");
    fx->Use(User("小菜"));

    WebSite* fy = f->GetWebSiteCategory("产品展示");
    fy->Use(User("大鸟"));

    WebSite* fz = f->GetWebSiteCategory("产品展示");
    fz->Use(User("娇娇"));

    WebSite* fl = f->GetWebSiteCategory("博客");
    fl->Use(User("老顽童"));

    WebSite* fm = f->GetWebSiteCategory("博客");
    fm->Use(User("桃谷六仙"));

    WebSite* fn = f->GetWebSiteCategory("博客");
    fn->Use(User("南海鳄神"));

    qDebug()<<"网站分类总数："<<f->GetWebSiteCount();

    return 0;
}
