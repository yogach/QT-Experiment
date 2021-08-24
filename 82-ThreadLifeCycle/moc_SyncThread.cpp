/****************************************************************************
** Meta object code from reading C++ file 'SyncThread.h'
**
** Created: Tue Aug 24 09:54:25 2021
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "SyncThread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SyncThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SyncThread[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_SyncThread[] = {
    "SyncThread\0"
};

const QMetaObject SyncThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_SyncThread,
      qt_meta_data_SyncThread, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SyncThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SyncThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SyncThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SyncThread))
        return static_cast<void*>(const_cast< SyncThread*>(this));
    return QThread::qt_metacast(_clname);
}

int SyncThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
