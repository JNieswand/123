#include <iostream>
#include <stdlib.h>
#include "C:\Software\Luxor\hw_interface\src\stages\stage_opcua_festo\Festo-comm-lib\include\festo_udp_func.h"
//#include "C:\Qt\5.9.2\msvc2013_64\include\QtCore\qstring.h"
//#include <QString>
#include "processcontrol.h"
#include "mainwindow.h"
#include <QtWidgets>
#include <QApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>
using namespace std;

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(application);

    QApplication app(argc, argv);
    QCoreApplication::setOrganizationName("QtProject");
    QCoreApplication::setApplicationName("Application Example");
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);
    QCommandLineParser parser;
    parser.setApplicationDescription(QCoreApplication::applicationName());
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("file", "The file to open.");
    parser.process(app);

    MainWindow mainWin;
//    if (!parser.positionalArguments().isEmpty())
//        mainWin.loadFile(parser.positionalArguments().first());
    mainWin.show();
    return app.exec();
}
