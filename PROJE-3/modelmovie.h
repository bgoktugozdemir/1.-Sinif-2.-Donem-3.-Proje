#ifndef MODELMOVIE_H
#define MODELMOVIE_H
#include <QList>
#include <QAbstractTableModel>
#include "Movie.h"
using namespace std;
class ModelMovie : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit ModelMovie(list<Movie*> * listData,QObject *parent = 0);

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
    QList<Movie*> * lists;

private:
};

#endif // MODELMOVIE_H
