#观察者模式，也叫做发步-订阅模式：定义了一种一对多的依赖关系，让多个观察者对象同时监听某一个主题对象，
#这个主题对象在状态发生变化时，会通知所有观察者对象，使它们能够自动更新自己

#注意：本节使用了前项声明，两个内互相调用的时候，需要前项声明，且声明内只能使用另一个类的指针或引用，
#同时如果里面有方法需要调用另一个类的方法时，必须放在cpp文件，且要包含另一个类的头文件！
#还要注意：override操作符在同文件中可以有，但是cpp中不需要声明了！
#还要注意：在C++中，构造函数不会自动继承，子类要重写构造函数！！

CONFIG += c++11
HEADERS += \
    observer.h \
    subject.h

SOURCES += \
    main.cpp \
    subject.cpp
