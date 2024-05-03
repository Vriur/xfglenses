QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    src/gui/sources/causticdialog.cpp \
    src/gui/sources/customslider.cpp \
    src/gui/sources/fittingdialog.cpp \
    src/gui/sources/helpdialog.cpp \
    src/gui/sources/imagefiledialog.cpp \
    src/gui/sources/lightcurvedialog.cpp \
    src/gui/sources/mainwindow.cpp \
    src/gui/sources/modelsdialog.cpp \
    src/gui/sources/modelsoption.cpp \
    src/gui/sources/obipdialog.cpp \
    src/gui/sources/trackdialog.cpp

HEADERS += \
    src/gui/headers/causticdialog.h \
    src/gui/headers/customslider.h \
    src/gui/headers/fittingdialog.h \
    src/gui/headers/helpdialog.h \
    src/gui/headers/imagefiledialog.h \
    src/gui/headers/lightcurvedialog.h \
    src/gui/headers/mainwindow.h \
    src/gui/headers/modelsdialog.h \
    src/gui/headers/modelsoption.h \
    src/gui/headers/obipdialog.h \
    src/gui/headers/trackdialog.h

FORMS += \
    src/gui/forms/causticdialog.ui \
    src/gui/forms/customslider.ui \
    src/gui/forms/fittingdialog.ui \
    src/gui/forms/helpdialog.ui \
    src/gui/forms/imagefiledialog.ui \
    src/gui/forms/lightcurvedialog.ui \
    src/gui/forms/mainwindow.ui \
    src/gui/forms/modelsdialog.ui \
    src/gui/forms/modelsoption.ui \
    src/gui/forms/obipdialog.ui \
    src/gui/forms/trackdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
