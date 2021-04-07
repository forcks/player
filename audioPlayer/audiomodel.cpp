#include "audiomodel.h"
#include "audiowork.h"

AudioModel::AudioModel(QObject *parent)
    : QAbstractListModel(parent)
    ,mList(nullptr)
{
}

int AudioModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid() || !mList)
        return 0;

    return mList->items().size();
}

QVariant AudioModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !mList)
        return QVariant();

    const AudioItem item = mList->items().at(index.row());
    switch (role) {
        case AudioNameRole:
            return QVariant(item.nameAudio);
        case AudioPathRole:
            return QVariant(item.pathToAudio);
    }

    // FIXME: Implement me!
    return QVariant();
}

bool AudioModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!mList)
        return false;

    AudioItem item = mList->items().at(index.row());
    switch (role) {
        case AudioNameRole:
            item.nameAudio = value.toString();
        break;
        case AudioPathRole:
            item.pathToAudio = value.toString();
        break;
    }

    if (mList->setItemAt(index.row(),item)) {
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags AudioModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> AudioModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[AudioNameRole] = "audioName";
    names[AudioPathRole] = "audioPath";
    return names;
}

AudioWork *AudioModel::list() const
{
    return mList;
}

void AudioModel::setList(AudioWork *list)
{
    beginResetModel();
    if(mList)
        mList->disconnect(this);

    mList = list;

    if(mList){
        connect(mList,&AudioWork::preItemAppended,this,[=](){
            const int index = mList->items().size();
            beginInsertRows(QModelIndex(),index,index);
        });
        connect(mList,&AudioWork::postItemAppended,this,[=](){
            endInsertRows();
        });
        connect(mList,&AudioWork::preItemRemoved,this,[=](int index){
            beginRemoveRows(QModelIndex(),index,index);
        });
        connect(mList,&AudioWork::postItemAppended,this,[=](){
            endInsertRows();
        });
    }
    endResetModel();
}






