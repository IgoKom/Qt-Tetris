/****************************************************************************
** Meta object code from reading C++ file 'glass.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../glass.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'glass.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Glass_t {
    QByteArrayData data[9];
    char stringdata0[81];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Glass_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Glass_t qt_meta_stringdata_Glass = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Glass"
QT_MOC_LITERAL(1, 6, 15), // "signalGlassInit"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 7), // "setRows"
QT_MOC_LITERAL(4, 31, 4), // "rows"
QT_MOC_LITERAL(5, 36, 10), // "setColumns"
QT_MOC_LITERAL(6, 47, 7), // "columns"
QT_MOC_LITERAL(7, 55, 13), // "slotGlassInit"
QT_MOC_LITERAL(8, 69, 11) // "slotNewGame"

    },
    "Glass\0signalGlassInit\0\0setRows\0rows\0"
    "setColumns\0columns\0slotGlassInit\0"
    "slotNewGame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Glass[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       2,   48, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   40,    2, 0x0a /* Public */,
       5,    1,   43,    2, 0x0a /* Public */,
       7,    0,   46,    2, 0x0a /* Public */,
       8,    0,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt,    4,
    QMetaType::Void, QMetaType::UInt,    6,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       4, QMetaType::UInt, 0x00095103,
       6, QMetaType::UInt, 0x00095103,

       0        // eod
};

void Glass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Glass *_t = static_cast<Glass *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalGlassInit(); break;
        case 1: _t->setRows((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 2: _t->setColumns((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 3: _t->slotGlassInit(); break;
        case 4: _t->slotNewGame(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Glass::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Glass::signalGlassInit)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        Glass *_t = static_cast<Glass *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< uint*>(_v) = _t->rows(); break;
        case 1: *reinterpret_cast< uint*>(_v) = _t->columns(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        Glass *_t = static_cast<Glass *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setRows(*reinterpret_cast< uint*>(_v)); break;
        case 1: _t->setColumns(*reinterpret_cast< uint*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Glass::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Glass.data,
      qt_meta_data_Glass,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Glass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Glass::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Glass.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Glass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Glass::signalGlassInit()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
