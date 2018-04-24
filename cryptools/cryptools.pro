#-------------------------------------------------
#
# Project created by QtCreator 2018-03-29T13:17:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cryptools
TEMPLATE = app
LIBS += -L/usr/local/lib -lgmpxx -lgmp
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#win32:RC_ICONS += Icons/window_icon.ico

SOURCES += \
        main.cpp \
        root.cpp \
    buttons.cpp \
    window.cpp \
    titlebar.cpp \
    droplineedit.cpp \
    custombutton.cpp \
    corewidget.cpp \
    tools/tools.cpp \
    tools/vigeneregroupwidget.cpp \
    tools/caesargroupwidget.cpp \
    tools/basicpermutationgroupwidget.cpp \
    tools/rsa.cpp \
    tools/prime-generator.cpp \
    tools/primewidget.cpp

HEADERS += \
        root.h \
    buttons.h \
    window.h \
    titlebar.h \
    droplineedit.h \
    custombutton.h \
    corewidget.h \
    tools/tools.h \
    tools/vigeneregroupwidget.h \
    tools/caesargroupwidget.h \
    tools/basicpermutationgroupwidget.h \
    tools/prime-generator.h \
    tools/primewidget.h

RESOURCES += \
    ressources.qrc

DISTFILES += \
    tools/removed

FORMS += \
    tools/caesargroupwidget.ui \
    tools/basicpermutationgroupwidget.ui \
    tools/primewidget.ui

