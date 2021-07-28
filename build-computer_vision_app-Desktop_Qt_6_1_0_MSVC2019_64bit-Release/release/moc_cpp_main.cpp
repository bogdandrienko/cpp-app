/****************************************************************************
** Meta object code from reading C++ file 'cpp_main.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../computer_vision_app/cpp_main.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cpp_main.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainClass_t {
    const uint offsetsAndSize[34];
    char stringdata0[341];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainClass_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainClass_t qt_meta_stringdata_MainClass = {
    {
QT_MOC_LITERAL(0, 9), // "MainClass"
QT_MOC_LITERAL(10, 20), // "on_START_btn_clicked"
QT_MOC_LITERAL(31, 0), // ""
QT_MOC_LITERAL(32, 19), // "on_STOP_btn_clicked"
QT_MOC_LITERAL(52, 19), // "on_QUIT_btn_clicked"
QT_MOC_LITERAL(72, 29), // "on_CamShot_pushButton_clicked"
QT_MOC_LITERAL(102, 36), // "on_ExportSettings_pushButton_..."
QT_MOC_LITERAL(139, 36), // "on_ImportSettings_pushButton_..."
QT_MOC_LITERAL(176, 10), // "AutoImport"
QT_MOC_LITERAL(187, 8), // "AutoPlay"
QT_MOC_LITERAL(196, 12), // "startAnalyse"
QT_MOC_LITERAL(209, 33), // "std::map<std::string,std::str..."
QT_MOC_LITERAL(243, 14), // "AllSettingsMap"
QT_MOC_LITERAL(258, 46), // "std::vector<std::map<std::str..."
QT_MOC_LITERAL(305, 17), // "AllSettingsVector"
QT_MOC_LITERAL(323, 14), // "Ui::MainClass*"
QT_MOC_LITERAL(338, 2) // "ui"

    },
    "MainClass\0on_START_btn_clicked\0\0"
    "on_STOP_btn_clicked\0on_QUIT_btn_clicked\0"
    "on_CamShot_pushButton_clicked\0"
    "on_ExportSettings_pushButton_clicked\0"
    "on_ImportSettings_pushButton_clicked\0"
    "AutoImport\0AutoPlay\0startAnalyse\0"
    "std::map<std::string,std::string>\0"
    "AllSettingsMap\0"
    "std::vector<std::map<std::string,std::string>>\0"
    "AllSettingsVector\0Ui::MainClass*\0ui"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainClass[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x08,    0 /* Private */,
       3,    0,   69,    2, 0x08,    1 /* Private */,
       4,    0,   70,    2, 0x08,    2 /* Private */,
       5,    0,   71,    2, 0x08,    3 /* Private */,
       6,    0,   72,    2, 0x08,    4 /* Private */,
       7,    0,   73,    2, 0x08,    5 /* Private */,
       8,    0,   74,    2, 0x08,    6 /* Private */,
       9,    0,   75,    2, 0x08,    7 /* Private */,
      10,    3,   76,    2, 0x08,    8 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11, 0x80000000 | 13, 0x80000000 | 15,   12,   14,   16,

       0        // eod
};

void MainClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainClass *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_START_btn_clicked(); break;
        case 1: _t->on_STOP_btn_clicked(); break;
        case 2: _t->on_QUIT_btn_clicked(); break;
        case 3: _t->on_CamShot_pushButton_clicked(); break;
        case 4: _t->on_ExportSettings_pushButton_clicked(); break;
        case 5: _t->on_ImportSettings_pushButton_clicked(); break;
        case 6: _t->AutoImport(); break;
        case 7: _t->AutoPlay(); break;
        case 8: _t->startAnalyse((*reinterpret_cast< std::map<std::string,std::string>(*)>(_a[1])),(*reinterpret_cast< std::vector<std::map<std::string,std::string>>(*)>(_a[2])),(*reinterpret_cast< Ui::MainClass*(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject MainClass::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainClass.offsetsAndSize,
    qt_meta_data_MainClass,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainClass_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::map<std::string,std::string>, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<std::map<std::string,std::string>>, std::false_type>, QtPrivate::TypeAndForceComplete<Ui::MainClass *, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainClass::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainClass.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
struct qt_meta_stringdata_SyncThreadClass_t {
    const uint offsetsAndSize[2];
    char stringdata0[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_SyncThreadClass_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_SyncThreadClass_t qt_meta_stringdata_SyncThreadClass = {
    {
QT_MOC_LITERAL(0, 15) // "SyncThreadClass"

    },
    "SyncThreadClass"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SyncThreadClass[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void SyncThreadClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject SyncThreadClass::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SyncThreadClass.offsetsAndSize,
    qt_meta_data_SyncThreadClass,
    qt_static_metacall,
    nullptr,
    nullptr,
    nullptr
} };


const QMetaObject *SyncThreadClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SyncThreadClass::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SyncThreadClass.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SyncThreadClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_AsyncThreadClass_t {
    const uint offsetsAndSize[6];
    char stringdata0[33];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_AsyncThreadClass_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_AsyncThreadClass_t qt_meta_stringdata_AsyncThreadClass = {
    {
QT_MOC_LITERAL(0, 16), // "AsyncThreadClass"
QT_MOC_LITERAL(17, 14), // "finishDownload"
QT_MOC_LITERAL(32, 0) // ""

    },
    "AsyncThreadClass\0finishDownload\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AsyncThreadClass[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   20,    2, 0x08,    0 /* Private */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void AsyncThreadClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AsyncThreadClass *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->finishDownload(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject AsyncThreadClass::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_AsyncThreadClass.offsetsAndSize,
    qt_meta_data_AsyncThreadClass,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_AsyncThreadClass_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *AsyncThreadClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AsyncThreadClass::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AsyncThreadClass.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AsyncThreadClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
