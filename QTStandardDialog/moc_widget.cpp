/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created: Wed Apr 14 11:43:05 2021
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "widget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Widget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x08,
      31,    7,    7,    7, 0x08,
      54,    7,    7,    7, 0x08,
      76,    7,    7,    7, 0x08,
      98,    7,    7,    7, 0x08,
     123,    7,    7,    7, 0x08,
     148,    7,    7,    7, 0x08,
     172,    7,    7,    7, 0x08,
     197,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Widget[] = {
    "Widget\0\0SimpleMsgBtn_Clicked()\0"
    "CustomMsgBtn_Clicked()\0OpenFileBtn_Clicked()\0"
    "SaveFileBtn_Clicked()\0ColorDialogBtn_Clicked()\0"
    "InputDialogBtn_Clicked()\0"
    "FontDialogBtn_Clicked()\0"
    "PrintDialogBtn_Clicked()\0"
    "ProgressDialogBtn_Clicked()\0"
};

const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget,
      qt_meta_data_Widget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Widget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Widget))
        return static_cast<void*>(const_cast< Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: SimpleMsgBtn_Clicked(); break;
        case 1: CustomMsgBtn_Clicked(); break;
        case 2: OpenFileBtn_Clicked(); break;
        case 3: SaveFileBtn_Clicked(); break;
        case 4: ColorDialogBtn_Clicked(); break;
        case 5: InputDialogBtn_Clicked(); break;
        case 6: FontDialogBtn_Clicked(); break;
        case 7: PrintDialogBtn_Clicked(); break;
        case 8: ProgressDialogBtn_Clicked(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
