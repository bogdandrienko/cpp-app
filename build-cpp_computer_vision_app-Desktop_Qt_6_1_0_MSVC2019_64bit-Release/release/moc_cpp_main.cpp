/****************************************************************************
** Meta object code from reading C++ file 'cpp_main.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../cpp_computer_vision_app/cpp_main.h"
#include <QtGui/qtextcursor.h>
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
    const uint offsetsAndSize[22];
    char stringdata0[176];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainClass_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainClass_t qt_meta_stringdata_MainClass = {
    {
QT_MOC_LITERAL(0, 9), // "MainClass"
QT_MOC_LITERAL(10, 20), // "on_START_btn_clicked"
QT_MOC_LITERAL(31, 0), // ""
QT_MOC_LITERAL(32, 24), // "authentication_to_access"
QT_MOC_LITERAL(57, 14), // "QNetworkReply*"
QT_MOC_LITERAL(72, 15), // "QAuthenticator*"
QT_MOC_LITERAL(88, 14), // "qauthenticator"
QT_MOC_LITERAL(103, 13), // "write_to_file"
QT_MOC_LITERAL(117, 18), // "analyse_from_image"
QT_MOC_LITERAL(136, 19), // "on_STOP_btn_clicked"
QT_MOC_LITERAL(156, 19) // "on_QUIT_btn_clicked"

    },
    "MainClass\0on_START_btn_clicked\0\0"
    "authentication_to_access\0QNetworkReply*\0"
    "QAuthenticator*\0qauthenticator\0"
    "write_to_file\0analyse_from_image\0"
    "on_STOP_btn_clicked\0on_QUIT_btn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainClass[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x08,    0 /* Private */,
       3,    2,   51,    2, 0x08,    1 /* Private */,
       7,    0,   56,    2, 0x08,    4 /* Private */,
       8,    0,   57,    2, 0x08,    5 /* Private */,
       9,    0,   58,    2, 0x08,    6 /* Private */,
      10,    0,   59,    2, 0x08,    7 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 5,    2,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainClass *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_START_btn_clicked(); break;
        case 1: _t->authentication_to_access((*reinterpret_cast< QNetworkReply*(*)>(_a[1])),(*reinterpret_cast< QAuthenticator*(*)>(_a[2]))); break;
        case 2: _t->write_to_file(); break;
        case 3: _t->analyse_from_image(); break;
        case 4: _t->on_STOP_btn_clicked(); break;
        case 5: _t->on_QUIT_btn_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
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

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>, QtPrivate::TypeAndForceComplete<QAuthenticator *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


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
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
