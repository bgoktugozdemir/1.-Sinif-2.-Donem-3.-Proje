#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "Database.h"
#include "Background.h"
#include "Interface.h"

int main(int argc, char *argv[])
{
    Database database;
    database.FillLists();
    Background background(&database);
    QApplication a(argc, argv);
    MainWindow w;
    w.Customize(&database,&background);
    w.show();
    return a.exec();
}
