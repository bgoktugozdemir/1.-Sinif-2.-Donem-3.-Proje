#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Background.h"
#include "Database.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void Customize(Database * database, Background * background);
    QStringList tableNames;
    Ui::MainWindow *ui;
private slots:

    void on_btnMovie_clicked();

    void on_btnSave_clicked();

    void on_btnAdd_clicked();

    void on_btnComment_clicked();

    void on_btnRating_clicked();

    void on_btnDelete_clicked();

    void on_btnStudio_clicked();

    void on_btnUser_clicked();

    void on_ver_clicked();

private:

    Database * database;
    Background * background;
    QString tableName;
};

#endif // MAINWINDOW_H
