QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AbstractImage.cpp \
    gamelogic.cpp \
    heavypoint.cpp \
    heavypointbuilder.cpp \
    image.cpp \
    iobjectbuilder.cpp \
    itemsettingsdialog.cpp \
    main.cpp \
    objectdirector.cpp \
    objectitem.cpp \
    planetbuilder.cpp \
    proxyimage.cpp \
    scene.cpp \
    widget.cpp

HEADERS += \
    AbstractImage.h \
    StorageVariable.h \
    gamelogic.h \
    heavypoint.h \
    heavypointbuilder.h \
    image.h \
    iobjectbuilder.h \
    itemsettingsdialog.h \
    objectdirector.h \
    objectitem.h \
    planetbuilder.h \
    proxyimage.h \
    scene.h \
    widget.h

FORMS += \
    itemsettingsdialog.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    gravitygame_model.qmodel
