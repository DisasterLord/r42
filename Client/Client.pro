QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Views/view_finalscore.cpp \
    Views/view_multiplayer.cpp \
    Views/view_waitinginqueue.cpp \
    main.cpp \
    menuwindow.cpp

HEADERS += \
    Views/view_finalscore.h \
    Views/view_multiplayer.h \
    Views/view_waitinginqueue.h \
    menuwindow.h

FORMS += \
    Views/view_finalscore.ui \
    Views/view_multiplayer.ui \
    Views/view_waitinginqueue.ui \
    menuwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
