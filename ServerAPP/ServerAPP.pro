QT       += core gui sql
QT = core
QT += network
LIBS += -lws2_32
CONFIG += c++17 cmdline
QT       += core gui
QT       += core gui network
QT += widgets
QT       += core gui sql
QT       += core network sql
QT       += widgets
QT += network
LIBS += -lws2_32
QT_DEBUG_PLUGINS = 1
MYSQL_LIBS=-lmysqld
LIBS += -lws2_32
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
        maineq.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    maineq.h

win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/'../../../../../Program Files/MySQL/MySQL Connector C 6.1/lib/' -llibmysql
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/'../../../../../Program Files/MySQL/MySQL Connector C 6.1/lib/' -llibmysqld
