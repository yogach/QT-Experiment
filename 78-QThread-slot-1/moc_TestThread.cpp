/****************************************************************************
** Meta object code from reading C++ file 'TestThread.h'
**
** Created: Mon Aug 16 10:07:14 2021
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "TestThread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TestThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TestThread[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      25,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TestThread[] = {
    "TestThread\0\0testSignal()\0testSlot()\0"
};

const QMetaObject TestThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_TestThread,
      qt_meta_data_TestThread, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TestThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TestThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TestThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TestThread))
        return static_cast<void*>(const_cast< TestThread*>(this));
    return QThread::qt_metacast(_clname);
}

int TestThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: testSignal(); break;
        case 1: testSlot(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void TestThread::testSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
