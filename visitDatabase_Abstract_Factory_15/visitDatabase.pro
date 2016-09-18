#抽象工厂模式:提供一个创建一系列相关或相互依赖对象的接口，而无需指定它们具体的类
#此例子也可以用简单工厂模+反射+读取配置文件来完成，这样更加简洁！！！
QT += core

CONFIG += c++11
HEADERS += \
    user.h \
    dataaccess.h

SOURCES += \
    main.cpp
