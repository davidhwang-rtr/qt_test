#-------------------------------------------------
#
# Project created by QtCreator 2018-11-28T10:52:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tableview
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

INCLUDEPATH += ./inc  \
  /home/david/project/rapidplan/src/components/rtr-ui/inc/rtr-ui  \
  /home/david/project/rapidplan/src/components/ \
  /home/david/project/rapidplan/src/components/rtr-math/inc/  \
  /home/david/project/rapidplan/src/components/rtr-control/inc/ \
  /home/david/project/rapidplan/src/components/rtr-utils/inc/ \
  /home/david/project/rapidplan/src/components/rtr-core/inc/  \
  /home/david/project/rapidplan/src/components/rtr-geometry/inc/  \
  /home/david/project/rapidplan/src/components/rtr-rendering/inc/ \
  /home/david/project/rapidplan/src/components/rtr-occupancy/inc/  \
  /home/david/project/rapidplan/src/components/rtr_perc_calibration/inc/



SOURCES += \
    src/buttonlabel.cpp \
    src/configrobotsensor.cpp \
    src/createprofiledialog.cpp \
    src/mainwindow.cpp \
    src/openrobotdialog.cpp \
    src/repositiondialog.cpp \
    src/homewidget.cpp \
    src/main.cpp \
    src/cameratablewidget.cpp \
    src/GuiBackendInterface.cpp \
    src/backendInterface.cpp \
    ../../rapidplan/src/components/rtr-ui/src/rtrslider.cpp \
    src/flashingled.cpp


HEADERS += \
    inc/buttonlabel.h \
    inc/configrobotsensor.h \
    inc/mainwindow.h \
    inc/repositiondialog.h \
    inc/createprofiledialog.h \
    inc/openrobotdialog.h \
    inc/cameratablewidget.h \
    inc/homewidget.h \
    inc/errormessage.h \
    inc/defines.h \
    inc/GuiBackendInterface.h \
    inc/backendInterface.h \
    ../../rapidplan/src/components/rtr-ui/inc/rtr-ui/rtrslider.hpp \
    inc/flashingled.h

FORMS += \
    src/mainwindow.ui \
    src/repositiondialog.ui \
    src/widget.ui \
    src/createprofiledialog.ui \
    src/openrobotdialog.ui \
    src/homepage.ui \
    ../../rapidplan/src/components/rtr-ui/src/rtrslider.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ../resource/resources.qrc
