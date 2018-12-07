/****************************************************************************
** Meta object code from reading C++ file 'cameratablewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tableview/cameratablewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cameratablewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CameraTableWidget_t {
    QByteArrayData data[16];
    char stringdata0[250];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CameraTableWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CameraTableWidget_t qt_meta_stringdata_CameraTableWidget = {
    {
QT_MOC_LITERAL(0, 0, 17), // "CameraTableWidget"
QT_MOC_LITERAL(1, 18, 16), // "TableItemClicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(4, 54, 16), // "TableCellClicked"
QT_MOC_LITERAL(5, 71, 3), // "row"
QT_MOC_LITERAL(6, 75, 3), // "col"
QT_MOC_LITERAL(7, 79, 16), // "TableCellPressed"
QT_MOC_LITERAL(8, 96, 16), // "TableCellChanged"
QT_MOC_LITERAL(9, 113, 25), // "OnRepositionButtonClicked"
QT_MOC_LITERAL(10, 139, 19), // "RefreshSensorConfig"
QT_MOC_LITERAL(11, 159, 18), // "QList<SensorInfo>&"
QT_MOC_LITERAL(12, 178, 11), // "sensor_list"
QT_MOC_LITERAL(13, 190, 20), // "OnPackagePathClicked"
QT_MOC_LITERAL(14, 211, 16), // "OnConnectClicked"
QT_MOC_LITERAL(15, 228, 21) // "OnTableContentChanged"

    },
    "CameraTableWidget\0TableItemClicked\0\0"
    "QTableWidgetItem*\0TableCellClicked\0"
    "row\0col\0TableCellPressed\0TableCellChanged\0"
    "OnRepositionButtonClicked\0RefreshSensorConfig\0"
    "QList<SensorInfo>&\0sensor_list\0"
    "OnPackagePathClicked\0OnConnectClicked\0"
    "OnTableContentChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CameraTableWidget[] = {

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
       1,    1,   59,    2, 0x0a /* Public */,
       4,    2,   62,    2, 0x0a /* Public */,
       7,    2,   67,    2, 0x0a /* Public */,
       8,    2,   72,    2, 0x0a /* Public */,
       9,    0,   77,    2, 0x0a /* Public */,
      10,    1,   78,    2, 0x0a /* Public */,
      13,    0,   81,    2, 0x0a /* Public */,
      14,    0,   82,    2, 0x0a /* Public */,
      15,    0,   83,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CameraTableWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CameraTableWidget *_t = static_cast<CameraTableWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->TableItemClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 1: _t->TableCellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->TableCellPressed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->TableCellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->OnRepositionButtonClicked(); break;
        case 5: _t->RefreshSensorConfig((*reinterpret_cast< QList<SensorInfo>(*)>(_a[1]))); break;
        case 6: _t->OnPackagePathClicked(); break;
        case 7: _t->OnConnectClicked(); break;
        case 8: _t->OnTableContentChanged(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CameraTableWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CameraTableWidget.data,
      qt_meta_data_CameraTableWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CameraTableWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CameraTableWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CameraTableWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CameraTableWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
