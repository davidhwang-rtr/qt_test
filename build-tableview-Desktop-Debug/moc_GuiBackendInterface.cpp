/****************************************************************************
** Meta object code from reading C++ file 'GuiBackendInterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tableview/inc/GuiBackendInterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GuiBackendInterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GuiBackendInterface_t {
    QByteArrayData data[17];
    char stringdata0[267];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GuiBackendInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GuiBackendInterface_t qt_meta_stringdata_GuiBackendInterface = {
    {
QT_MOC_LITERAL(0, 0, 19), // "GuiBackendInterface"
QT_MOC_LITERAL(1, 20, 9), // "sendFrame"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 20), // "WorkerThreadFinished"
QT_MOC_LITERAL(4, 52, 24), // "backgroundThreadFinished"
QT_MOC_LITERAL(5, 77, 19), // "InitialPoseFinished"
QT_MOC_LITERAL(6, 97, 12), // "ErrorMessage"
QT_MOC_LITERAL(7, 110, 17), // "InitialPoseStatus"
QT_MOC_LITERAL(8, 128, 25), // "CalibrationProgressUpdate"
QT_MOC_LITERAL(9, 154, 10), // "curr_index"
QT_MOC_LITERAL(10, 165, 11), // "ExitHandler"
QT_MOC_LITERAL(11, 177, 20), // "SetFiducialSelection"
QT_MOC_LITERAL(12, 198, 5), // "index"
QT_MOC_LITERAL(13, 204, 16), // "JoinWorkerThread"
QT_MOC_LITERAL(14, 221, 17), // "SetRobotSelection"
QT_MOC_LITERAL(15, 239, 14), // "SetPackagePath"
QT_MOC_LITERAL(16, 254, 12) // "SetIPAddress"

    },
    "GuiBackendInterface\0sendFrame\0\0"
    "WorkerThreadFinished\0backgroundThreadFinished\0"
    "InitialPoseFinished\0ErrorMessage\0"
    "InitialPoseStatus\0CalibrationProgressUpdate\0"
    "curr_index\0ExitHandler\0SetFiducialSelection\0"
    "index\0JoinWorkerThread\0SetRobotSelection\0"
    "SetPackagePath\0SetIPAddress"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GuiBackendInterface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       3,    0,   77,    2, 0x06 /* Public */,
       4,    0,   78,    2, 0x06 /* Public */,
       5,    1,   79,    2, 0x06 /* Public */,
       7,    1,   82,    2, 0x06 /* Public */,
       8,    1,   85,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   88,    2, 0x0a /* Public */,
      11,    1,   89,    2, 0x0a /* Public */,
      13,    0,   92,    2, 0x0a /* Public */,
      14,    1,   93,    2, 0x0a /* Public */,
      15,    1,   96,    2, 0x0a /* Public */,
      16,    1,   99,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPixmap,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void GuiBackendInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GuiBackendInterface *_t = static_cast<GuiBackendInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendFrame((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        case 1: _t->WorkerThreadFinished(); break;
        case 2: _t->backgroundThreadFinished(); break;
        case 3: _t->InitialPoseFinished((*reinterpret_cast< ErrorMessage(*)>(_a[1]))); break;
        case 4: _t->InitialPoseStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->CalibrationProgressUpdate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->ExitHandler(); break;
        case 7: _t->SetFiducialSelection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->JoinWorkerThread(); break;
        case 9: _t->SetRobotSelection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->SetPackagePath((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->SetIPAddress((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GuiBackendInterface::*_t)(QPixmap );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GuiBackendInterface::sendFrame)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (GuiBackendInterface::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GuiBackendInterface::WorkerThreadFinished)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (GuiBackendInterface::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GuiBackendInterface::backgroundThreadFinished)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (GuiBackendInterface::*_t)(ErrorMessage );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GuiBackendInterface::InitialPoseFinished)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (GuiBackendInterface::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GuiBackendInterface::InitialPoseStatus)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (GuiBackendInterface::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GuiBackendInterface::CalibrationProgressUpdate)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject GuiBackendInterface::staticMetaObject = {
    { &BackendInterface::staticMetaObject, qt_meta_stringdata_GuiBackendInterface.data,
      qt_meta_data_GuiBackendInterface,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GuiBackendInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GuiBackendInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GuiBackendInterface.stringdata0))
        return static_cast<void*>(const_cast< GuiBackendInterface*>(this));
    return BackendInterface::qt_metacast(_clname);
}

int GuiBackendInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BackendInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void GuiBackendInterface::sendFrame(QPixmap _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GuiBackendInterface::WorkerThreadFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void GuiBackendInterface::backgroundThreadFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void GuiBackendInterface::InitialPoseFinished(ErrorMessage _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void GuiBackendInterface::InitialPoseStatus(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void GuiBackendInterface::CalibrationProgressUpdate(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
