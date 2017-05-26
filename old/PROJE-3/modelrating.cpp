#include "modelrating.h"

ModelRating::ModelRating(list<Rating*> * listData, QObject *parent)
    : QAbstractTableModel(parent)
{
    lists = new QList<Rating*>();
    list<Rating*>::iterator i;
    for (i = listData->begin(); i != listData->end(); i++) {
    lists->append(*i);
    }
}

QVariant ModelRating::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("Id");
            case 1:
                return QString("Rating");
            case 2:
                return QString("User Id");
            case 3:
                return QString("Movie Id");
            }
        }


    }

    return QVariant();
}

bool ModelRating::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (value != headerData(section, orientation, role)) {
        // FIXME: Implement me!
        emit headerDataChanged(orientation, section, section);
        return true;
    }
    return false;
}


int ModelRating::rowCount(const QModelIndex &parent) const
{
    return lists->size();
}

int ModelRating::columnCount(const QModelIndex &parent) const
{
        return 4;
}

QVariant ModelRating::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();


    int row = index.row();
    int col = index.column();

    switch(role){
      case Qt::DisplayRole:
        if (col == 0) {/*id*/
            return QString::number(lists->at(row)->RatingId);
        }
        else if (col == 1) {/*rating*/
            return QString::number(lists->at(row)->rating);
        }
        else if (col == 2) {/*user id*/
            return QString::number(lists->at(row)->user_id);
        }
        else if (col == 3) {/*movie id*/
            return QString::number(lists->at(row)->movie_id);
        }
    }
        return QVariant();
}

bool ModelRating::setData(const QModelIndex &index, const QVariant &value, int role)
{
    int row = index.row();
    int col = index.column();
    if (role == Qt::EditRole)
    {
        auto data = lists->at(row);
        if(col == 0)        data->RatingId =  value.toInt();
        else if(col == 1)   data->rating = value.toFloat();
        else if(col == 2)   data->user_id = value.toInt();
        else if(col == 3)   data->movie_id = value.toInt();
        }
    return true;
}

Qt::ItemFlags ModelRating::flags(const QModelIndex &index) const
{
    return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}
