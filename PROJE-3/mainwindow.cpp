#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "modelmovie.h"
#include "modelcomment.h"
#include "modelrating.h"
#include "modelstudio.h"
#include "modeluser.h"
#include <QMessageBox>
#include <QString>
#include <windows.h>
#include <QTimer>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listTable->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->listTable->setSelectionBehavior(QAbstractItemView::SelectRows);
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

         if (tableName == "Comment") { database->Comments.push_back (new Comment());  on_btnComment_clicked(); }
    else if (tableName == "Movie")   { database->Movies.push_back   (new Movie());    on_btnMovie_clicked();   }
    else if (tableName == "Rating")  { database->Ratings.push_back  (new Rating());   on_btnRating_clicked();  }
    else if (tableName == "Studio")  { database->Studios.push_back  (new Studio());   on_btnStudio_clicked();  }
    else if (tableName == "User")    { database->Users.push_back    (new User());     on_btnUser_clicked();    }
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


void MainWindow::on_btnStudio_clicked()
{
    tableName="Studio";
    ui->listTable->setModel(new ModelStudio(&database->Studios,0));
}

void MainWindow::on_btnUser_clicked()
{
    tableName="User";
    ui->listTable->setModel(new ModelUser(&database->Users,0));
}

void MainWindow::on_btnDelete_clicked()
{

    QItemSelectionModel *select = ui->listTable->selectionModel();

    if(!select || !select->hasSelection())
        return;

    auto item = select->selectedRows().at(0);
    int selectedRow = item.row();

         if (tableName == "Comment") {  database->Comments.remove   (((ModelComment*)   item.model())->lists->at(selectedRow));          on_btnComment_clicked();  }
    else if (tableName == "Movie")   {  database->Movies.remove     (((ModelMovie*)     item.model())->lists->at(selectedRow));          on_btnMovie_clicked();    }
    else if (tableName == "Rating")  {  database->Ratings.remove    (((ModelRating*)    item.model())->lists->at(selectedRow));          on_btnRating_clicked();   }
    else if (tableName == "Studio")  {  database->Studios.remove    (((ModelStudio*)    item.model())->lists->at(selectedRow));          on_btnStudio_clicked();   }
    else if (tableName == "User")    {  database->Users.remove      (((ModelUser*)      item.model())->lists->at(selectedRow));          on_btnUser_clicked();     }
}

void MainWindow::on_ver_clicked()
{
    QMessageBox popup;
    popup.setText("Updates");
    popup.exec();
}
