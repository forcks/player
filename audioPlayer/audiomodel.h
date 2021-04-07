#ifndef AUDIOMODEL_H
#define AUDIOMODEL_H

#include <QAbstractListModel>

class AudioWork;

class AudioModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(AudioWork *list READ list WRITE setList)

public:
    explicit AudioModel(QObject *parent = nullptr);

    ///////////
    enum{
        AudioNameRole = Qt::UserRole,
        AudioPathRole
    };
    //////////////

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    ///////
    virtual QHash<int,QByteArray> roleNames() const override;
    ////////


    AudioWork *list() const;
    void setList(AudioWork *list);

private:
    AudioWork *mList;
};

#endif // AUDIOMODEL_H
