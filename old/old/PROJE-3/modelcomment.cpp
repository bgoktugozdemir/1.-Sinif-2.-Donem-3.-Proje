#include "modelcomment.h"
#include <QDateTime>
#include <QDebug>

ModelComment::ModelComment(list<Comment*> * listData, QObject *parent)
    : QAbstractTableModel(parent)
{
    lists = new QList<Comment*>();
    list<Comment*>::iterator i;
    for (i = listData->begin(); i != listData->end(); i++) {
       lists->append(*i);
    }
}

QVariant ModelComment::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("Id");
            case 1:
                return QString("Time");
            case 2:
                return QString("Comment");
            case 3:
                return QString("Movie Id");
            case 4:
                return QString("User Id");
            }
        }
    }

    return QVariant();
}

bool ModelComment::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (value != headerData(section, orientation, role)) {
        // FIXME: Implement me!
        emit headerDataChanged(orientation, section, section);
        return true;
    }
    return false;
}


int ModelComment::rowCount(const QModelIndex &parent) const
{
    return lists->size();
}

int ModelComment::columnCount(const QModelIndex &parent) const
{
        return 5;

    // FIXME: Implement me!
}

QVariant ModelComment::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();


    int row = index.row();
    int col = index.column();

    switch(role){
      case Qt::DisplayRole:
        if (col == 0) {/*id*/
            return QString::number(lists->at(row)->CommentId);
        }
        else if (col == 1) {/*comment time*/
            return QDateTime::fromTime_t(lists->at(row)->CommentTime).toString();
        }
        else if (col == 2) {/*comment*/
            return QString::fromStdString(lists->at(row)->comment);
        }
        else if (col == 3) {/*movie id*/
            return QString::number(lists->at(row)->movie_id);
        }
        else if (col == 4) {/*user id*/
            return QString::number(lists->at(row)->user_id);
        }
    }

    // FIXME: Implement me!
    return QVariant();
}

bool ModelComment::setData(const QModelIndex &index, const QVariant &value, int role)
{
    int row = index.row();
    int col = index.column();
    if (role == Qt::EditRole)
    {
        auto data = lists->at(row);
        if(col == 0)        data->CommentId =  value.toInt();
        else if(col == 1)   data->CommentTime = value.toDateTime().toTime_t();
        else if(col == 2)   data->comment = value.toString().toStdString();
        else if(col == 3)   data->movie_id = value.toInt();
        else if(col == 4)   data->user_id = value.toInt();
        return true;
    }
    return false;
}

Qt::ItemFlags ModelComment::flags(const QModelIndex &index) const
{
     return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}
