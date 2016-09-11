#This is an example to show the strategy pattern of design mode
#策略模式：它定义了算法家族，分别封装起来，让他们之间可以相互替换，此模式让算法的变化，不好影响到使用算法的客户
HEADERS += \
    cashsuper.h \
    cashcontext.h \
    shopprice.h

SOURCES += \
    main.cpp \
    shopprice.cpp

QT += widgets

FORMS += \
    shopprice.ui
