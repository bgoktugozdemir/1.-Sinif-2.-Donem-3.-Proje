#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "modelmovie.h"
#include "modelcomment.h"
#include "modelrating.h"
#include <QMessageBox>
#include <QString>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Customize(Database * database, Background * background)
{
    this->database = database;
    this->background = background;
}

void MainWindow::on_btnSave_clicked()
{
    QMessageBox box;
    if(database->SaveFiles()) {
        box.setText("Saved succesfully");
    } else {
        box.setText("Error");
    }
    box.exec();


}

void MainWindow::on_btnAdd_clicked()
{

         if (tableName == "Comment") { database->Comments.push_back (new Comment());    on_btnComment_clicked(); }
    else if (tableName == "Movie")   { database->Movies.push_back       (new Movie());  on_btnMovie_clicked();}
    else if (tableName == "Rating")  { database->Ratings.push_back (new Rating());    }
    else if (tableName == "Studio")  { database->Studios.push_back   (new Studio());  }
    else if (tableName == "User")    { database->Users.push_back    (new User());     }
}

void MainWindow::on_btnMovie_clicked()
{
    tableName="Movie";
    ui->listTable->setModel(new ModelMovie(&database->Movies,0));

}

void MainWindow::on_btnComment_clicked()
{
    tableName="Comment";
    ui->listTable->setModel(new ModelComment(&database->Comments,0));
}

void MainWindow::on_btnRating_clicked()
{
    tableName="Rating";
    ui->listTable->setModel(new ModelRating(&database->Ratings,0));
}
