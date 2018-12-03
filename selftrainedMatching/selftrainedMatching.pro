TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QT += core
#!include( C:/Software/Luxor/hw_interface/src/stages/stage_opcua_festo/Festo-comm-lib/opc-ua-lib/common.pri ) {
#    message( "Failed to load common.pri!" )
#}
SOURCES += main.cpp \
           src/udp_func.cpp \
    src/processply.cpp
           C:/Software/Luxor/hw_interface/src/stages/stage_opcua_festo/Festo-comm-lib/src/festo_udp_func.cpp
HEADERS += include/udp_func.h \
           C:/Software/Luxor/hw_interface/src/stages/stage_opcua_festo/Festo-comm-lib/include/festo_udp_func.h\
           C:/Software/Luxor/hw_interface/src/stages/stage_opcua_festo/Festo-comm-lib/opc-ua-lib/include/udp_messages.h

INCLUDEPATH +=  C:/Software/Luxor/hw_interface/hw_interface_module/festo-comm-lib/FestoCommLib_lib/include\
                C:/Software/Luxor/hw_interface/src/stages/stage_opcua_festo/Festo-comm-lib/opc-ua-lib/include\
                $$(LUXOR_DEPENDENCIES)/curl/include\
                C:\Qt\5.9.2\msvc2013_64\include\QtCore
#LIBS += -L"$$(LUXOR_DEPENDENCIES)/Boost/lib"\
#        include/opc-ua-lib.lib

INCLUDEPATH += ./include

INCLUDEPATH += $$(LUXOR_DEPENDENCIES)/boost/include
INCLUDEPATH += $$(LUXOR_DEPENDENCIES)/glog/include

DEFINES += GLOG_NO_ABBREVIATED_SEVERITIES

LIBS += -L$$(LUXOR_DEPENDENCIES)/boost/lib

QMAKE_CFLAGS_RELEASE    +=/Zi /openmp /MP /Ot /Oi
QMAKE_CXXFLAGS_RELEASE  +=/Zi /openmp /MP /Ot /Oi
QMAKE_LFLAGS_RELEASE    +=/MAP /DEBUG /OPT:REF /OPT:ICF

CONFIG( debug, debug|release ) {
    LIBS += -L"$$(LUXOR_DEPENDENCIES)/glog/lib/debug"
    LIBS += -llibglogd
}

CONFIG(release, debug|release) {
    LIBS += -L"$$(LUXOR_DEPENDENCIES)/glog/lib/release"
    LIBS += -llibglog
}

Release:LIBS += -LC:/Software/Luxor/hw_interface/src/stages/stage_opcua_festo/Festo-comm-lib/libs/win_x64_release \
                                -lFestoCommLib
Debug:LIBS +=   -LC:/Software/Luxor/hw_interface/src/stages/stage_opcua_festo/Festo-comm-lib/libs/win_x64_debug \
                                -lFestoCommLib
#equals(TARGET, opc-ua-lib) {
#} else {
#    CONFIG( debug, debug|release ) {
#        LIBS += -L$$_PRO_FILE_PWD_/opc-ua-lib/libs/win_x64_debug
#    }

#    CONFIG( release, debug|release ) {
#        LIBS += -L$$_PRO_FILE_PWD_/opc-ua-lib/libs/win_x64_release
#    }

#    LIBS += -lopc-ua-lib
#}

