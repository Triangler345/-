QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bullet.cpp \
    dinosaur.cpp \
    enemy.cpp \
    food.cpp \
    food2.cpp \
    help.cpp \
    main.cpp \
    mainscene.cpp \
    map.cpp \
    pterosaur.cpp

HEADERS += \
    bullet.h \
    config.h \
    dinosaur.h \
    enemy.h \
    food.h \
    food2.h \
    help.h \
    mainscene.h \
    map.h \
    pterosaur.h

FORMS += \
    help.ui \
    mainscene.ui

TRANSLATIONS += \
    Dinosaur_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
