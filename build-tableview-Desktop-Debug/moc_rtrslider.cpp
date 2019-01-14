/****************************************************************************
** Meta object code from reading C++ file 'rtrslider.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../rapidplan/src/components/rtr-ui/inc/rtr-ui/rtrslider.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rtrslider.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RTRSlider_t {
    QByteArrayData data[13];
    char stringdata0[199];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RTRSlider_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RTRSlider_t qt_meta_stringdata_RTRSlider = {
    {
QT_MOC_LITERAL(0, 0, 9), // "RTRSlider"
QT_MOC_LITERAL(1, 10, 12), // "valueChanged"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 8), // "QString&"
QT_MOC_LITERAL(4, 33, 9), // "fieldName"
QT_MOC_LITERAL(5, 43, 8), // "newValue"
QT_MOC_LITERAL(6, 52, 27), // "on_lineEdit_editingFinished"
QT_MOC_LITERAL(7, 80, 32), // "on_horizontalSlider_valueChanged"
QT_MOC_LITERAL(8, 113, 5), // "value"
QT_MOC_LITERAL(9, 119, 20), // "on_coarseNeg_pressed"
QT_MOC_LITERAL(10, 140, 20), // "on_coarsePos_pressed"
QT_MOC_LITERAL(11, 161, 18), // "on_fineNeg_pressed"
QT_MOC_LITERAL(12, 180, 18) // "on_finePos_pressed"

    },
    "RTRSlider\0valueChanged\0\0QString&\0"
    "fieldName\0newValue\0on_lineEdit_editingFinished\0"
    "on_horizontalSlider_valueChanged\0value\0"
    "on_coarseNeg_pressed\0on_coarsePos_pressed\0"
    "on_fineNeg_pressed\0on_finePos_pressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RTRSlider[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   54,    2, 0x08 /* Private */,
       7,    1,   55,    2, 0x08 /* Private */,
       9,    0,   58,    2, 0x08 /* Private */,
      10,    0,   59,    2, 0x08 /* Private */,
      11,    0,   60,    2, 0x08 /* Private */,
      12,    0,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Float,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RTRSlider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RTRSlider *_t = static_cast<RTRSlider *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 1: _t->on_lineEdit_editingFinished(); break;
        case 2: _t->on_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_coarseNeg_pressed(); break;
        case 4: _t->on_coarsePos_pressed(); break;
        case 5: _t->on_fineNeg_pressed(); break;
        case 6: _t->on_finePos_pressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RTRSlider::*_t)(QString & , float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RTRSlider::valueChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject RTRSlider::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RTRSlider.data,
      qt_meta_data_RTRSlider,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RTRSlider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RTRSlider::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RTRSlider.stringdata0))
        return static_cast<void*>(const_cast< RTRSlider*>(this));
    return QWidget::qt_metacast(_clname);
}

int RTRSlider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void RTRSlider::valueChanged(QString & _t1, float _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
