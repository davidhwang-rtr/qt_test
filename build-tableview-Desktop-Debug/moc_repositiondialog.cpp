/****************************************************************************
** Meta object code from reading C++ file 'repositiondialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tableview/inc/repositiondialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'repositiondialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RepositionDialog_t {
    QByteArrayData data[15];
    char stringdata0[189];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RepositionDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RepositionDialog_t qt_meta_stringdata_RepositionDialog = {
    {
QT_MOC_LITERAL(0, 0, 16), // "RepositionDialog"
QT_MOC_LITERAL(1, 17, 7), // "skipped"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 9), // "continued"
QT_MOC_LITERAL(4, 36, 9), // "cancelled"
QT_MOC_LITERAL(5, 46, 12), // "findFiducial"
QT_MOC_LITERAL(6, 59, 12), // "on_Cancelled"
QT_MOC_LITERAL(7, 72, 10), // "on_Skipped"
QT_MOC_LITERAL(8, 83, 12), // "on_Continued"
QT_MOC_LITERAL(9, 96, 20), // "on_received_fiducial"
QT_MOC_LITERAL(10, 117, 12), // "ErrorMessage"
QT_MOC_LITERAL(11, 130, 3), // "msg"
QT_MOC_LITERAL(12, 134, 18), // "on_received_status"
QT_MOC_LITERAL(13, 153, 6), // "status"
QT_MOC_LITERAL(14, 160, 28) // "on_pushButton_accept_clicked"

    },
    "RepositionDialog\0skipped\0\0continued\0"
    "cancelled\0findFiducial\0on_Cancelled\0"
    "on_Skipped\0on_Continued\0on_received_fiducial\0"
    "ErrorMessage\0msg\0on_received_status\0"
    "status\0on_pushButton_accept_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RepositionDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    0,   66,    2, 0x06 /* Public */,
       5,    0,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   68,    2, 0x0a /* Public */,
       7,    0,   69,    2, 0x0a /* Public */,
       8,    0,   70,    2, 0x0a /* Public */,
       9,    1,   71,    2, 0x0a /* Public */,
      12,    1,   74,    2, 0x0a /* Public */,
      14,    0,   77,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void,

       0        // eod
};

void RepositionDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RepositionDialog *_t = static_cast<RepositionDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->skipped(); break;
        case 1: _t->continued(); break;
        case 2: _t->cancelled(); break;
        case 3: _t->findFiducial(); break;
        case 4: _t->on_Cancelled(); break;
        case 5: _t->on_Skipped(); break;
        case 6: _t->on_Continued(); break;
        case 7: _t->on_received_fiducial((*reinterpret_cast< ErrorMessage(*)>(_a[1]))); break;
        case 8: _t->on_received_status((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_pushButton_accept_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RepositionDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RepositionDialog::skipped)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (RepositionDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RepositionDialog::continued)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (RepositionDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RepositionDialog::cancelled)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (RepositionDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RepositionDialog::findFiducial)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject RepositionDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_RepositionDialog.data,
      qt_meta_data_RepositionDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RepositionDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RepositionDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RepositionDialog.stringdata0))
        return static_cast<void*>(const_cast< RepositionDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int RepositionDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void RepositionDialog::skipped()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void RepositionDialog::continued()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void RepositionDialog::cancelled()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void RepositionDialog::findFiducial()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
