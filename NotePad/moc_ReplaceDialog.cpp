/****************************************************************************
** Meta object code from reading C++ file 'ReplaceDialog.h'
**
** Created: Thu Jun 10 10:04:46 2021
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ReplaceDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ReplaceDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ReplaceDialog[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x09,
      34,   14,   14,   14, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_ReplaceDialog[] = {
    "ReplaceDialog\0\0onReplaceClicked()\0"
    "onReplaceAllClicked()\0"
};

const QMetaObject ReplaceDialog::staticMetaObject = {
    { &FindDialog::staticMetaObject, qt_meta_stringdata_ReplaceDialog,
      qt_meta_data_ReplaceDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ReplaceDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ReplaceDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ReplaceDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ReplaceDialog))
        return static_cast<void*>(const_cast< ReplaceDialog*>(this));
    return FindDialog::qt_metacast(_clname);
}

int ReplaceDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = FindDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onReplaceClicked(); break;
        case 1: onReplaceAllClicked(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
