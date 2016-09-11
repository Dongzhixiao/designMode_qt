#This is an example to show the factory method mode of design mode
#这个例子是实现一个计算器第二版，使用工厂方法模式：定义一个用于创建对象的接口，让子类决定实例化哪一个类。工厂方法使一个类的实例延迟到其子类！
#注意：它和简单工厂的区别是没有违背开放-封闭原则，简单工厂在工厂类里面通过逻辑实例话对应的类，违背了开放-封闭原则！
HEADERS += \
    sign.h \
    signfactory.h

SOURCES += \
    main.cpp
