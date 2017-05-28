#ifndef MODELUSER_H
#define MODELUSER_H
#include <QList>
#include <QAbstractTableModel>
#include "User.h"
using namespace std;
class ModelUser : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit ModelUser(list<User*> * listData,QObject *parent = 0);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole) override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;
    QList<User*> * lists;

private:
};

#endif // MODELUSER_H
