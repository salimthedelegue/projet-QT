
QT+= core gui
QT+= core gui charts
QT += printsupport
QT +=  multimedia multimediawidgets

QT += sql
TARGET = application
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connexion.cpp \
    main.cpp \
    mainwindow.cpp \
    parking.cpp \
    statistic.cpp \
    vehicule.cpp

HEADERS += \
    connexion.h \
    mainwindow.h \
    parking.h \
    statistic.h \
    vehicule.h

FORMS += \
    mainwindow.ui \
    statistic.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
