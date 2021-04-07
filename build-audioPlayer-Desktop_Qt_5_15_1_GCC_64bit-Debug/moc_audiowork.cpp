/****************************************************************************
** Meta object code from reading C++ file 'audiowork.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../audioPlayer/audiowork.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'audiowork.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AudioWork_t {
    QByteArrayData data[25];
    char stringdata0[296];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AudioWork_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AudioWork_t qt_meta_stringdata_AudioWork = {
    {
QT_MOC_LITERAL(0, 0, 9), // "AudioWork"
QT_MOC_LITERAL(1, 10, 15), // "preItemAppended"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 16), // "postItemAppended"
QT_MOC_LITERAL(4, 44, 14), // "preItemRemoved"
QT_MOC_LITERAL(5, 59, 5), // "index"
QT_MOC_LITERAL(6, 65, 15), // "postItemRemoved"
QT_MOC_LITERAL(7, 81, 15), // "changeNameAudio"
QT_MOC_LITERAL(8, 97, 9), // "nameAudio"
QT_MOC_LITERAL(9, 107, 19), // "changePositionMusic"
QT_MOC_LITERAL(10, 127, 8), // "position"
QT_MOC_LITERAL(11, 136, 25), // "changeDurationAudioSlider"
QT_MOC_LITERAL(12, 162, 3), // "max"
QT_MOC_LITERAL(13, 166, 9), // "showAudio"
QT_MOC_LITERAL(14, 176, 4), // "path"
QT_MOC_LITERAL(15, 181, 9), // "playAudio"
QT_MOC_LITERAL(16, 191, 11), // "pathToAudio"
QT_MOC_LITERAL(17, 203, 5), // "pause"
QT_MOC_LITERAL(18, 209, 4), // "next"
QT_MOC_LITERAL(19, 214, 8), // "previous"
QT_MOC_LITERAL(20, 223, 10), // "editVolume"
QT_MOC_LITERAL(21, 234, 6), // "volume"
QT_MOC_LITERAL(22, 241, 24), // "savePathToFolderForAudio"
QT_MOC_LITERAL(23, 266, 4), // "Path"
QT_MOC_LITERAL(24, 271, 24) // "signalTimerPositionMusic"

    },
    "AudioWork\0preItemAppended\0\0postItemAppended\0"
    "preItemRemoved\0index\0postItemRemoved\0"
    "changeNameAudio\0nameAudio\0changePositionMusic\0"
    "position\0changeDurationAudioSlider\0"
    "max\0showAudio\0path\0playAudio\0pathToAudio\0"
    "pause\0next\0previous\0editVolume\0volume\0"
    "savePathToFolderForAudio\0Path\0"
    "signalTimerPositionMusic"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AudioWork[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    0,   90,    2, 0x06 /* Public */,
       4,    1,   91,    2, 0x06 /* Public */,
       6,    0,   94,    2, 0x06 /* Public */,
       7,    1,   95,    2, 0x06 /* Public */,
       9,    1,   98,    2, 0x06 /* Public */,
      11,    1,  101,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    1,  104,    2, 0x0a /* Public */,
      15,    1,  107,    2, 0x0a /* Public */,
      17,    0,  110,    2, 0x0a /* Public */,
      18,    0,  111,    2, 0x0a /* Public */,
      19,    0,  112,    2, 0x0a /* Public */,
      20,    1,  113,    2, 0x0a /* Public */,
      22,    1,  116,    2, 0x0a /* Public */,
      24,    0,  119,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   12,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void,

       0        // eod
};

void AudioWork::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AudioWork *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->preItemAppended(); break;
        case 1: _t->postItemAppended(); break;
        case 2: _t->preItemRemoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->postItemRemoved(); break;
        case 4: _t->changeNameAudio((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->changePositionMusic((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->changeDurationAudioSlider((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->showAudio((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->playAudio((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->pause(); break;
        case 10: _t->next(); break;
        case 11: _t->previous(); break;
        case 12: _t->editVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->savePathToFolderForAudio((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->signalTimerPositionMusic(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AudioWork::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AudioWork::preItemAppended)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AudioWork::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AudioWork::postItemAppended)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AudioWork::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AudioWork::preItemRemoved)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (AudioWork::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AudioWork::postItemRemoved)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (AudioWork::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AudioWork::changeNameAudio)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (AudioWork::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AudioWork::changePositionMusic)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (AudioWork::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AudioWork::changeDurationAudioSlider)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AudioWork::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_AudioWork.data,
    qt_meta_data_AudioWork,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AudioWork::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AudioWork::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AudioWork.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AudioWork::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void AudioWork::preItemAppended()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AudioWork::postItemAppended()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void AudioWork::preItemRemoved(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void AudioWork::postItemRemoved()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void AudioWork::changeNameAudio(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void AudioWork::changePositionMusic(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void AudioWork::changeDurationAudioSlider(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
