/****************************************************************************
** Meta object code from reading C++ file 'cborrowandreturn.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../LibraryClient/cborrowandreturn.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cborrowandreturn.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CBorrowAndReturn_t {
    QByteArrayData data[7];
    char stringdata0[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CBorrowAndReturn_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CBorrowAndReturn_t qt_meta_stringdata_CBorrowAndReturn = {
    {
QT_MOC_LITERAL(0, 0, 16), // "CBorrowAndReturn"
QT_MOC_LITERAL(1, 17, 16), // "TurnToPageBorrow"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 16), // "TurnToPageReturn"
QT_MOC_LITERAL(4, 52, 9), // "FreshPage"
QT_MOC_LITERAL(5, 62, 14), // "ChangeLineEdit"
QT_MOC_LITERAL(6, 77, 15) // "ClickedButtonOk"

    },
    "CBorrowAndReturn\0TurnToPageBorrow\0\0"
    "TurnToPageReturn\0FreshPage\0ChangeLineEdit\0"
    "ClickedButtonOk"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CBorrowAndReturn[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    1,   42,    2, 0x0a /* Public */,
       6,    0,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void CBorrowAndReturn::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CBorrowAndReturn *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->TurnToPageBorrow(); break;
        case 1: _t->TurnToPageReturn(); break;
        case 2: _t->FreshPage(); break;
        case 3: _t->ChangeLineEdit((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->ClickedButtonOk(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CBorrowAndReturn::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_CBorrowAndReturn.data,
    qt_meta_data_CBorrowAndReturn,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CBorrowAndReturn::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CBorrowAndReturn::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CBorrowAndReturn.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CBorrowAndReturn::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
