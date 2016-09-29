#桥接模式：将抽象部分与它的实现部分分离，使它们都可以独立地变化

SOURCES += \
    main.cpp
	
HEADERS += \
    mobile.h
	
#合成/聚合复用原则，尽量使用合成/聚合，尽量不要使用类继承
#合成和聚合都是关联的特殊种类
#聚合表示一种弱的‘拥有’关系，体现的是A对象可以包含B对象，但B对象不是A对象的一部分
#合成则是一种强的‘拥有’关系，体现了严格的部分和整体的关系，部分和整体的生命周期一样
#比如：大雁有两个翅膀，翅膀与大雁就是部分和整体的关系，并且它们的生命周期是相同的，于是大雁和翅膀就是合成关系
#而大雁是群居动物，所以每只大雁都属于一个雁群，一个雁群可以有多只大雁，所以大雁和雁群是聚合关系
#合成/聚合复用原则的好处是，优先使用对象的合成/聚合将有助于你保持每个类被封装，并被集中在单个任务上
#这样类和类继承层次会保持较小规模，并且不太可能增长为不可控制的庞然大物
