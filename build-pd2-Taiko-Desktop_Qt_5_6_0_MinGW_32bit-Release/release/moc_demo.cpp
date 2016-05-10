/****************************************************************************
** Meta object code from reading C++ file 'demo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../pd2-Taiko/demo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'demo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_demo_t {
    QByteArrayData data[11];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_demo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_demo_t qt_meta_stringdata_demo = {
    {
QT_MOC_LITERAL(0, 0, 4), // "demo"
QT_MOC_LITERAL(1, 5, 9), // "try_again"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 7), // "to_main"
QT_MOC_LITERAL(4, 24, 6), // "update"
QT_MOC_LITERAL(5, 31, 11), // "hideDonLeft"
QT_MOC_LITERAL(6, 43, 12), // "hideDonRight"
QT_MOC_LITERAL(7, 56, 13), // "hideKatsuLeft"
QT_MOC_LITERAL(8, 70, 14), // "hideKatsuRight"
QT_MOC_LITERAL(9, 85, 17), // "hideDongOrKatsuOk"
QT_MOC_LITERAL(10, 103, 23) // "change_baground_in_game"

    },
    "demo\0try_again\0\0to_main\0update\0"
    "hideDonLeft\0hideDonRight\0hideKatsuLeft\0"
    "hideKatsuRight\0hideDongOrKatsuOk\0"
    "change_baground_in_game"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_demo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    1,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void demo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        demo *_t = static_cast<demo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->try_again(); break;
        case 1: _t->to_main(); break;
        case 2: _t->update(); break;
        case 3: _t->hideDonLeft(); break;
        case 4: _t->hideDonRight(); break;
        case 5: _t->hideKatsuLeft(); break;
        case 6: _t->hideKatsuRight(); break;
        case 7: _t->hideDongOrKatsuOk(); break;
        case 8: _t->change_baground_in_game((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject demo::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_demo.data,
      qt_meta_data_demo,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *demo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *demo::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_demo.stringdata0))
        return static_cast<void*>(const_cast< demo*>(this));
    return QWidget::qt_metacast(_clname);
}

int demo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
