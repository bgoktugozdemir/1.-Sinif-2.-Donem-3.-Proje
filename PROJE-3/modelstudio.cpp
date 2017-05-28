#include "modelstudio.h"
#include <QDebug>

ModelStudio::ModelStudio(list<Studio*> * listData, QObject *parent)
    : QAbstractTableModel(parent)
{
    lists = new QList<Studio*>();
    list<Studio*>::iterator i;
    for (i = listData->begin(); i != listData->end(); i++) {
       lists->append(*i);
    }
}

QVariant ModelStudio::headerData(int section, Qt::Orientation orientation, int role) const
{

    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("Id");
            case 1:
                return QString("Name");
            case 2:
                return QString("Info");
            }
        }


    }

    return QVariant();
}

bool ModelStudio::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (value != headerData(section, orientation, role)) {
        // FIXME: Implement me!
        emit headerDataChanged(orientation, section, section);
        return true;
    }
    return false;
}


int ModelStudio::rowCount(const QModelIndex &parent) const
{
    return lists->size();
}

int ModelStudio::columnCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant ModelStudio::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();


    int row = index.row();
    int col = index.column();

    switch(role){
      case Qt::DisplayRole:
        if (col == 0) {/*id*/
            return QString::number(lists->at(row)->StudioId);
        }
        else if (col == 1) {/*name*/
            return QString::fromStdString(lists->at(row)->StudioName);
        }
        else if (col == 2) {/*info*/
            return QString::fromStdString(lists->at(row)->StudioInfo);
        }
    }

    return QVariant();
}

bool ModelStudio::setData(const QModelIndex &index, const QVariant &value, int role)
{
    int row = index.row();
    int col = index.column();
    if (role == Qt::EditRole)
    {
        auto data = lists->at(row);
        if(col == 0)        data->StudioId =  value.toInt();
        else if(col == 1)   data->StudioName = value.toString().toStdString();
        else if(col == 2)   data->StudioInfo = value.toString().toStdString();

    }
    return true;
}

Qt::ItemFlags ModelStudio::flags(const QModelIndex &index) const
{

    return Qt::ItemIsEditable | QAbstractTableModel::flags(index);

}
