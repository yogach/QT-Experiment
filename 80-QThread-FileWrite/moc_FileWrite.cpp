/****************************************************************************
** Meta object code from reading C++ file 'FileWrite.h'
**
** Created: Mon Aug 23 10:10:40 2021
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "FileWrite.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FileWrite.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FileWrite[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   11,   10,   10, 0x05,
      33,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      43,   11,   10,   10, 0x09,
      62,   10,   10,   10, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_FileWrite[] = {
    "FileWrite\0\0text\0doWrite(QString)\0"
    "doClose()\0writeSlot(QString)\0closeSlot()\0"
};

const QMetaObject FileWrite::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FileWrite,
      qt_meta_data_FileWrite, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FileWrite::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FileWrite::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FileWrite::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FileWrite))
        return static_cast<void*>(const_cast< FileWrite*>(this));
    return QObject::qt_metacast(_clname);
}

int FileWrite::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: doWrite((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: doClose(); break;
        case 2: writeSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: closeSlot(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void FileWrite::doWrite(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FileWrite::doClose()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
