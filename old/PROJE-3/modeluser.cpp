#include "modeluser.h"
#include <QDebug>
ModelUser::ModelUser(list<User*> * listData, QObject *parent)
    : QAbstractTableModel(parent)
{
    lists = new QList<User*>();
    list<User*>::iterator i;
    for (i = listData->begin(); i != listData->end(); i++) {
       lists->append(*i);
    }
}

QVariant ModelUser::headerData(int section, Qt::Orientation orientation, int role) const
{

    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("Id");
            case 1:
                return QString("User Type");
            case 2:
                return QString("Username");
            case 3:
                return QString("Password");
            case 4:
                return QString("E-Mail");
            }
        }


    }

    return QVariant();
}

bool ModelUser::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (value != headerData(section, orientation, role)) {
        // FIXME: Implement me!
        emit headerDataChanged(orientation, section, section);
        return true;
    }
    return false;
}


int ModelUser::rowCount(const QModelIndex &parent) const
{
    return lists->size();
}

int ModelUser::columnCount(const QModelIndex &parent) const
{
    return 5;
}

QVariant ModelUser::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();


    int row = index.row();
    int col = index.column();

    switch(role){
      case Qt::DisplayRole:
        if (col == 0) {/*id*/
            return QString::number(lists->at(row)->UserId);
        }
        else if (col == 1) {/*usertype*/
            return QString::fromStdString(lists->at(row)->UserType);
        }
        else if (col == 2) {/*username*/
            return QString::fromStdString(lists->at(row)->UserName);
        }
        else if (col == 3) {/*password*/
            return QString::fromStdString(lists->at(row)->UserPassword);
        }
        else if (col == 4) {/*email*/
            return QString::fromStdString(lists->at(row)->UserEmail);
        }
    }

    // FIXME: Implement me!
    return QVariant();
}

bool ModelUser::setData(const QModelIndex &index, const QVariant &value, int role)
{
    int row = index.row();
    int col = index.column();
    if (role == Qt::EditRole)
    {
        auto data = lists->at(row);
        if(col == 0)        data->UserId =  value.toInt();
        else if(col == 1)   data->UserType = value.toString().toStdString();
        else if(col == 2)   data->UserName = value.toString().toStdString();
        else if(col == 3)   data->UserPassword = value.toString().toStdString();
        else if(col == 4)   data->UserEmail = value.toString().toStdString();
    }
    return true;
}

Qt::ItemFlags ModelUser::flags(const QModelIndex &index) const
{

    return Qt::ItemIsEditable | QAbstractTableModel::flags(index);

}
