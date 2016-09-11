#建造者模式，将一个复杂对象的构建和它的表示分离，使得同样的构建过程可以创建不同的表示
#其是当创建复杂对象的算法应该独立于该对象的组成部分以及它们的装配方式时适用的模式！！
CONFIG += c++11
QT += widgets
HEADERS += \
    drawit.h

SOURCES += \
    main.cpp \
    drawit.cpp
