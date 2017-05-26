#include "modelmovie.h"
#include <QDebug>
ModelMovie::ModelMovie(list<Movie*> * listData, QObject *parent)
    : QAbstractTableModel(parent)
{
    lists = new QList<Movie*>();
    list<Movie*>::iterator i;
    for (i = listData->begin(); i != listData->end(); i++) {
       lists->append(*i);
    }
}

QVariant ModelMovie::headerData(int section, Qt::Orientation orientation, int role) const
{

    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("Id");
            case 1:
                return QString("Title");
            case 2:
                return QString("Genre");
            case 3:
                return QString("Release Year");
            case 4:
                return QString("Langueage");
            case 5:
                return QString("Rating");
            case 6:
                return QString("Censorship");
            case 7:
                return QString("Story");
            case 8:
                return QString("Budget");
            case 9:
                return QString("Studio Id");
            }
        }


    }

    return QVariant();
}

bool ModelMovie::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (value != headerData(section, orientation, role)) {
        // FIXME: Implement me!
        emit headerDataChanged(orientation, section, section);
        return true;
    }
    return false;
}


int ModelMovie::rowCount(const QModelIndex &parent) const
{
    //if (parent.isValid())
        return lists->size();

    // FIXME: Implement me!
}

int ModelMovie::columnCount(const QModelIndex &parent) const
{
    //if (parent.isValid())
        return 10;

    // FIXME: Implement me!
}

QVariant ModelMovie::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();


    int row = index.row();
    int col = index.column();

    switch(role){
      case Qt::DisplayRole:
        if (col == 0) {/*id*/
            return QString::number(lists->at(row)->MovieId);
        }
        else if (col == 1) {/*movie title*/
            return QString::fromStdString(lists->at(row)->MovieTitle);
        }
        else if (col == 2) {/*movie genre*/
            return QString::fromStdString(lists->at(row)->MovieGenre);
        }
        else if (col == 3) {/*movie release year*/
            return QString::fromStdString(lists->at(row)->MovieReleaseYear);
        }
        else if (col == 4) {/*movie language*/
            return QString::fromStdString(lists->at(row)->MovieLanguage);
        }
        else if (col == 5) {/*movie rating*/
            return QString::number(lists->at(row)->MovieRating);
        }
        else if (col == 6) {/*movie censorship*/
            return QString::fromStdString(lists->at(row)->MovieCensorship);
        }
        else if (col == 7) {/*movie story*/
            return QString::fromStdString(lists->at(row)->MovieStory);
        }
        else if (col == 8) {/*movie budget*/
            return QString::number(lists->at(row)->MovieBudget);
        }
        else if (col == 9) {/*movie studioid*/
            return QString::number(lists->at(row)->studio_id);
        }
        //QDateTime::fromTime_t(degiskenAdi lists-> falan filan).toString()

    }

    // FIXME: Implement me!
    return QVariant();
}

bool ModelMovie::setData(const QModelIndex &index, const QVariant &value, int role)
{
    int row = index.row();
    int col = index.column();
    if (role == Qt::EditRole)
    {
        auto data = lists->at(row);
        if(col == 0)        data->MovieId =  value.toInt();
        else if(col == 1)   data->MovieTitle = value.toString().toStdString();
        else if(col == 2)   data->MovieGenre = value.toString().toStdString();
        else if(col == 3)   data->MovieReleaseYear = value.toString().toStdString();
        else if(col == 4)   data->MovieLanguage = value.toString().toStdString();
        else if(col == 5)   data->MovieRating = value.toDouble();
        else if(col == 6)   data->MovieCensorship = value.toString().toStdString();
        else if(col == 7)   data->MovieStory = value.toString().toStdString();
        else if(col == 8)   data->MovieBudget = value.toUInt();
        else if(col == 9)   data->studio_id = value.toInt();
       // else if(col == 1)   data->MovieTitle =  value.toDateTime().toTime_t();
       // else if(col == 2)   data->created_by_id =  value.toInt();
       // else if(col == 3)   data->is_group =  value.toBool();
       // else if(col == 4)   data->status =  value.toString().toStdString();
    }
    return true;
}

/*Qt::ItemFlags ModelMovie::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable; // FIXME: Implement me!
}*/


Qt::ItemFlags ModelMovie::flags(const QModelIndex &index) const
{

    return Qt::ItemIsEditable | QAbstractTableModel::flags(index);

}
