/****************************************************************************
** Meta object code from reading C++ file 'cameratablewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tableview/inc/cameratablewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cameratablewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CameraTableWidget_t {
    QByteArrayData data[27];
    char stringdata0[441];
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
QT_MOC_LITERAL(13, 190, 24), // "OnCalibrationModeChanged"
QT_MOC_LITERAL(14, 215, 5), // "index"
QT_MOC_LITERAL(15, 221, 17), // "SetRobotSelection"
QT_MOC_LITERAL(16, 239, 14), // "SetPackagePath"
QT_MOC_LITERAL(17, 254, 5), // "input"
QT_MOC_LITERAL(18, 260, 12), // "SetIPAddress"
QT_MOC_LITERAL(19, 273, 20), // "OnPackagePathClicked"
QT_MOC_LITERAL(20, 294, 16), // "OnConnectClicked"
QT_MOC_LITERAL(21, 311, 21), // "OnTableContentChanged"
QT_MOC_LITERAL(22, 333, 25), // "OnNewProfileButtonClicked"
QT_MOC_LITERAL(23, 359, 18), // "RepositionAccepted"
QT_MOC_LITERAL(24, 378, 18), // "RepositionRejected"
QT_MOC_LITERAL(25, 397, 21), // "CreateProfileAccepted"
QT_MOC_LITERAL(26, 419, 21) // "CreateProfileRejected"

    },
    "CameraTableWidget\0TableItemClicked\0\0"
    "QTableWidgetItem*\0TableCellClicked\0"
    "row\0col\0TableCellPressed\0TableCellChanged\0"
    "OnRepositionButtonClicked\0RefreshSensorConfig\0"
    "QList<SensorInfo>&\0sensor_list\0"
    "OnCalibrationModeChanged\0index\0"
    "SetRobotSelection\0SetPackagePath\0input\0"
    "SetIPAddress\0OnPackagePathClicked\0"
    "OnConnectClicked\0OnTableContentChanged\0"
    "OnNewProfileButtonClicked\0RepositionAccepted\0"
    "RepositionRejected\0CreateProfileAccepted\0"
    "CreateProfileRejected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CameraTableWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  104,    2, 0x0a /* Public */,
       4,    2,  107,    2, 0x0a /* Public */,
       7,    2,  112,    2, 0x0a /* Public */,
       8,    2,  117,    2, 0x0a /* Public */,
       9,    0,  122,    2, 0x0a /* Public */,
      10,    1,  123,    2, 0x0a /* Public */,
      13,    1,  126,    2, 0x0a /* Public */,
      15,    1,  129,    2, 0x0a /* Public */,
      16,    1,  132,    2, 0x0a /* Public */,
      18,    1,  135,    2, 0x0a /* Public */,
      19,    0,  138,    2, 0x0a /* Public */,
      20,    0,  139,    2, 0x0a /* Public */,
      21,    0,  140,    2, 0x0a /* Public */,
      22,    0,  141,    2, 0x0a /* Public */,
      23,    0,  142,    2, 0x08 /* Private */,
      24,    0,  143,    2, 0x08 /* Private */,
      25,    0,  144,    2, 0x08 /* Private */,
      26,    0,  145,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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
        case 6: _t->OnCalibrationModeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->SetRobotSelection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->SetPackagePath((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->SetIPAddress((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->OnPackagePathClicked(); break;
        case 11: _t->OnConnectClicked(); break;
        case 12: _t->OnTableContentChanged(); break;
        case 13: _t->OnNewProfileButtonClicked(); break;
        case 14: _t->RepositionAccepted(); break;
        case 15: _t->RepositionRejected(); break;
        case 16: _t->CreateProfileAccepted(); break;
        case 17: _t->CreateProfileRejected(); break;
        default: ;
        }
    }
}

const QMetaObject CameraTableWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CameraTableWidget.data,
      qt_meta_data_CameraTableWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CameraTableWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CameraTableWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CameraTableWidget.stringdata0))
        return static_cast<void*>(const_cast< CameraTableWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int CameraTableWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
