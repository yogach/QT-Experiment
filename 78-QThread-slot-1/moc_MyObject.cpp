/****************************************************************************
** Meta object code from reading C++ file 'MyObject.h'
**
** Created: Mon Aug 16 10:07:14 2021
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MyObject.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyObject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyObject[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x09,
      23,    9,    9,    9, 0x09,
      37,    9,    9,    9, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_MyObject[] = {
    "MyObject\0\0getStarted()\0getFinished()\0"
    "getTerminated()\0"
};

const QMetaObject MyObject::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MyObject,
      qt_meta_data_MyObject, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyObject::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyObject::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyObject))
        return static_cast<void*>(const_cast< MyObject*>(this));
    return QObject::qt_metacast(_clname);
}

int MyObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: getStarted(); break;
        case 1: getFinished(); break;
        case 2: getTerminated(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
