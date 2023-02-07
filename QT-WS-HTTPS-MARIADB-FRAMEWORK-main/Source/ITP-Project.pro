QT -= gui

CONFIG += c++17 console
QT += network \
    widgets
QT += sql
CONFIG -= app_bundle

QT += websockets

SOURCES += \
        CAH/card.cpp \
        CAH/game.cpp \
        CAH/player.cpp \
        main.cpp \
        routes/httptestroute.cpp \
        routes/jsontestroute.cpp \
        socket/websocketserver.cpp \
        utils/csv_utils.cpp \
        utils/jsonutils.cpp \
        utils/mariadb.cpp \
        utils/ws_utils.cpp \
        ws/webserver.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    CAH/card.h \
    CAH/game.h \
    CAH/player.h \
    routes/httptestroute.h \
    routes/iroutehandler.h \
    routes/jsontestroute.h \
    socket/websocketserver.h \
    utils/csv_utils.h \
    utils/jsonutils.h \
    utils/mariadb.h \
    utils/ws_utils.h \
    ws/webserver.h
