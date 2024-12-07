QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CreateAccountPage.cpp \
    DeleteProfilesPage.cpp \
    DeviceOverview.cpp \
    EnterAccountPage.cpp \
    HomeScreenPage.cpp \
    LoginPage.cpp \
    User.cpp \
    main.cpp

HEADERS += \
    CreateAccountPage.h \
    DeleteProfilesPage.h \
    DeviceOverview.h \
    EnterAccountPage.h \
    HomeScreenPage.h \
    LoginPage.h \
    User.h

FORMS += \
    CreateAccountPage.ui \
    DeleteProfilesPage.ui \
    EnterAccountPage.ui \
    HomeScreenPage.ui \
    LoginPage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
