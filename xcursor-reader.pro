QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

DEFINES += KS_STR_ENCODING_NONE

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    MainWindow.cpp \
    xcursor.cpp \
    kaitai/kaitaistream.cpp

HEADERS += \
    MainWindow.h \
    xcursor.h \
    kaitai/custom_decoder.h \
    kaitai/exceptions.h \
    kaitai/kaitaistream.h \
    kaitai/kaitaistruct.h

FORMS += \
    MainWindow.ui

OTHER_FILES += README.md

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
