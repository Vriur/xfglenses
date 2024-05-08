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
    src/gui/sources/modelscell.cpp \
    src/gui/sources/modelsdialog.cpp \
    src/gui/sources/obipdialog.cpp \
    src/gui/sources/trackdialog.cpp \
    src/models/sources/barkanamodel.cpp \
    src/models/sources/changrefsdalmodel.cpp \
    src/models/sources/devancoulermodel.cpp \
    src/models/sources/elliptichubblemodel.cpp \
    src/models/sources/elliptickingmodel.cpp \
    src/models/sources/ellipticmodel.cpp \
    src/models/sources/ellipticnismodel.cpp \
    src/models/sources/ellipticplummermodel.cpp \
    src/models/sources/ellipticsismodel.cpp \
    src/models/sources/hubblemodel.cpp \
    src/models/sources/kassiolakovnermodel.cpp \
    src/models/sources/kingmodel.cpp \
    src/models/sources/modelparameter.cpp \
    src/models/sources/multipolemodel.cpp \
    src/models/sources/nfwmodel.cpp \
    src/models/sources/nismodel.cpp \
    src/models/sources/rotationlensmodel.cpp \
    src/models/sources/secondordermodel.cpp \
    src/models/sources/sismodel.cpp \
    src/models/sources/spiralmodel.cpp \
    src/models/sources/transparentspheremodel.cpp \
    src/models/sources/truncatedkingmodel.cpp \
    src/models/sources/uniformringmodel.cpp

HEADERS += \
    src/gui/headers/causticdialog.h \
    src/gui/headers/customslider.h \
    src/gui/headers/fittingdialog.h \
    src/gui/headers/helpdialog.h \
    src/gui/headers/imagefiledialog.h \
    src/gui/headers/lightcurvedialog.h \
    src/gui/headers/mainwindow.h \
    src/gui/headers/modelscell.h \
    src/gui/headers/modelsdialog.h \
    src/gui/headers/obipdialog.h \
    src/gui/headers/trackdialog.h \
    src/models/headers/barkanamodel.h \
    src/models/headers/changrefsdalmodel.h \
    src/models/headers/devancoulermodel.h \
    src/models/headers/elliptichubblemodel.h \
    src/models/headers/elliptickingmodel.h \
    src/models/headers/ellipticmodel.h \
    src/models/headers/ellipticnismodel.h \
    src/models/headers/ellipticplummermodel.h \
    src/models/headers/ellipticsismodel.h \
    src/models/headers/hubblemodel.h \
    src/models/headers/kassiolakovnermodel.h \
    src/models/headers/kingmodel.h \
    src/models/headers/modelparameter.h \
    src/models/headers/model.h \
    src/models/headers/multipolemodel.h \
    src/models/headers/nfwmodel.h \
    src/models/headers/nismodel.h \
    src/models/headers/rotationlensmodel.h \
    src/models/headers/secondordermodel.h \
    src/models/headers/sismodel.h \
    src/models/headers/spiralmodel.h \
    src/models/headers/transparentspheremodel.h \
    src/models/headers/truncatedkingmodel.h \
    src/models/headers/uniformringmodel.h

FORMS += \
    src/gui/forms/causticdialog.ui \
    src/gui/forms/customslider.ui \
    src/gui/forms/fittingdialog.ui \
    src/gui/forms/helpdialog.ui \
    src/gui/forms/imagefiledialog.ui \
    src/gui/forms/lightcurvedialog.ui \
    src/gui/forms/mainwindow.ui \
    src/gui/forms/modelscell.ui \
    src/gui/forms/modelsdialog.ui \
    src/gui/forms/obipdialog.ui \
    src/gui/forms/trackdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
