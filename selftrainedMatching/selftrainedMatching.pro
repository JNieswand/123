TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
QT += core
QT  += core gui
QT += widgets
win32:RC_ICONS += "C:\Users\dbutov\Desktop\Jacob_Demo_selftrained\selftrainedMatching\include\icons\HD_Vision_Logo_matching.ico"
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
DEFINES += QT_ENABLED
#!include( C:/Software/Luxor/hw_interface/src/stages/stage_opcua_festo/Festo-comm-lib/opc-ua-lib/common.pri ) {
#    message( "Failed to load common.pri!" )
#}


SOURCES += main.cpp \
           src/udp_func.cpp \
           src/processply.cpp \
           src/processcontrol.cpp \
           C:/Software/Luxor/hw_interface/src/stages/stage_opcua_festo/Festo-comm-lib/src/festo_udp_func.cpp \
           mainwindow.cpp

HEADERS += include/udp_func.h \
           include/processply.h \
           C:/Software/Luxor/hw_interface/src/stages/stage_opcua_festo/Festo-comm-lib/include/festo_udp_func.h \
           C:/Software/Luxor/hw_interface/src/stages/stage_opcua_festo/Festo-comm-lib/opc-ua-lib/include/udp_messages.h \
            src/processcontrol.h \
            mainwindow.h

INCLUDEPATH +=  C:/Software/Luxor/hw_interface/src/stages/stage_opcua_festo/Festo-comm-lib/include \
                C:/Software/Luxor/hw_interface/src/stages/stage_opcua_festo/Festo-comm-lib/opc-ua-lib/include \
                $$(LUXOR_DEPENDENCIES)/curl/include \
                C:/Qt/5.9.2/msvc2013_64/include/QtCore \
                C:/Qt/5.9.2/msvc2013_64/include/QtWidgets \
                $$(LUXOR_DEPENDENCIES)/PCL/include \
                $$(LUXOR_DEPENDENCIES)/curl/include \
                $$(LUXOR_DEPENDENCIES)/Eigen/include/eigen3 \
                $$(LUXOR_DEPENDENCIES)/boost/include \
                $$(LUXOR_DEPENDENCIES)/glog/include \
                $$(LUXOR_DEPENDENCIES)/ceres/include \
                $$(LUXOR_DEPENDENCIES)/FLANN/include


INCLUDEPATH += ./include
INCLUDEPATH += ./src
INCLUDEPATH += C:/Qt/5.9.2/msvc2013_64/include

DEFINES += GLOG_NO_ABBREVIATED_SEVERITIES

LIBS += -L$$(LUXOR_DEPENDENCIES)/boost/lib
LIBS += -L"$$(LUXOR_DEPENDENCIES)/PCL/lib" \
        -L"$$(LUXOR_DEPENDENCIES)/ceres/lib" \
        -L"$$(LUXOR_DEPENDENCIES)/FLANN/lib" \
        -LC:/Qt/5.9.2/msvc2013_64/lib

QMAKE_CFLAGS_RELEASE    +=/Zi /openmp /MP /Ot /Oi
QMAKE_CXXFLAGS_RELEASE  +=/Zi /openmp /MP /Ot /Oi
QMAKE_LFLAGS_RELEASE    +=/MAP /DEBUG /OPT:REF /OPT:ICF

CONFIG( debug, debug|release ) {
    LIBS += -L"$$(LUXOR_DEPENDENCIES)/glog/lib/debug"
    LIBS += -llibglogd
    LIBS += -L"$$(LUXOR_DEPENDENCIES)/libQGLViewer/lib/debug"
    LIBS += -L"$$(LUXOR_DEPENDENCIES)/HDF5/lib/debug"
    LIBS += -L"$$(LUXOR_DEPENDENCIES)/VTK\debug\bin"
    LIBS += -L"$$(LUXOR_DEPENDENCIES)/clif/lib/debug"
    LIBS += -lpcl_common_debug \
            -lpcl_features_debug \
            -lpcl_filters_debug \
            -lpcl_io_ply_debug \
            -lpcl_io_debug \
            -lpcl_kdtree_debug \
            -lpcl_keypoints_debug \
            -lpcl_ml_debug \
            -lpcl_octree_debug \
            -lpcl_surface_debug \
            -lpcl_recognition_debug \
            -lpcl_registration_debug \
            -lpcl_sample_consensus_debug \
            -lpcl_search_debug \
            -lpcl_segmentation_debug \
            -lpcl_tracking_debug \
            -lpcl_visualization_debug \
            -lhdf5_D \
            -lhdf5_cpp_D \
            -lhdf5_hl_D \
            -lhdf5_hl_cpp_D \
            -lhdf5_tools_D \
            -lzlib_D \
            -lszip_D \
            -llibglogd \
            -lceres-debug \
            -lclifd
}

CONFIG(release, debug|release) {
    LIBS += -L"$$(LUXOR_DEPENDENCIES)/glog/lib/release"
    LIBS += -llibglog
    LIBS += -L"$$(LUXOR_DEPENDENCIES)/libQGLViewer/lib/release"
    LIBS += -L"$$(LUXOR_DEPENDENCIES)/HDF5/lib/release"
    LIBS += -L"$$(LUXOR_DEPENDENCIES)/VTK\release\bin"
    LIBS += -L"$$(LUXOR_DEPENDENCIES)/clif/lib/release"
    LIBS += -lpcl_common_release \
            -lpcl_features_release \
            -lpcl_filters_release \
            -lpcl_io_ply_release \
            -lpcl_io_release \
            -lpcl_kdtree_release \
            -lpcl_keypoints_release \
            -lpcl_ml_release \
            -lpcl_octree_release \
            -lpcl_surface_release \
            -lpcl_recognition_release \
            -lpcl_registration_release \
            -lpcl_sample_consensus_release \
            -lpcl_search_release \
            -lpcl_segmentation_release \
            -lpcl_tracking_release \
            -lpcl_visualization_release \
            -lhdf5 \
            -lhdf5_cpp \
            -lhdf5_hl \
            -lhdf5_hl_cpp \
            -lhdf5_tools \
            -lzlib\
            -lszip \
            -llibglog \
            -lceres \
            -lclif
}



RESOURCES = include/application.qrc
Release:LIBS += -LC:/Software/Luxor/hw_interface/src/stages/stage_opcua_festo/Festo-comm-lib/libs/win_x64_release \
                                -lFestoCommLib
Debug:LIBS +=   -LC:/Software/Luxor/hw_interface/src/stages/stage_opcua_festo/Festo-comm-lib/libs/win_x64_debug \
                                -lFestoCommLib

