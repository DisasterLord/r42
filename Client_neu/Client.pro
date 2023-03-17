QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Client.cpp \
    Views/view_finalscore.cpp \
    Views/view_menuwindow.cpp \
    Views/view_multiplayer.cpp \
    main.cpp \

HEADERS += \
    Views/Client.h \
    Views/view_finalscore.h \
    Views/view_menuwindow.h \
    Views/view_multiplayer.h \

FORMS += \
    Views/view_finalscore.ui \
    Views/view_menuwindow.ui \
    Views/view_multiplayer.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
