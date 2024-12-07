QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CreateAccountPage.cpp \
    DeviceOverview.cpp \
    EnterAccountPage.cpp \
    HealthMetrics.cpp \
    HomeScreenPage.cpp \
    LoginPage.cpp \
    User.cpp \
    endofscannotes.cpp \
    main.cpp \
    measuringpage.cpp

HEADERS += \
    CreateAccountPage.h \
    DeviceOverview.h \
    EnterAccountPage.h \
    HealthMetrics.h \
    HomeScreenPage.h \
    LoginPage.h \
    User.h \
    endofscannotes.h \
    measuringpage.h

FORMS += \
    CreateAccountPage.ui \
    EnterAccountPage.ui \
    HomeScreenPage.ui \
    LoginPage.ui \
    endofscannotes.ui \
    measuringpage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
