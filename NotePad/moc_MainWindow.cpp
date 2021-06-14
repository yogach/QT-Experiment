/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created: Mon Jun 14 12:04:56 2021
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MainWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      24,   11,   11,   11, 0x08,
      37,   11,   11,   11, 0x08,
      50,   11,   11,   11, 0x08,
      65,   11,   11,   11, 0x08,
      79,   11,   11,   11, 0x08,
      92,   11,   11,   11, 0x08,
     118,  108,   11,   11, 0x08,
     140,  108,   11,   11, 0x08,
     162,  108,   11,   11, 0x08,
     184,   11,   11,   11, 0x08,
     210,   11,   11,   11, 0x08,
     225,   11,   11,   11, 0x08,
     238,   11,   11,   11, 0x08,
     254,   11,   11,   11, 0x08,
     267,   11,   11,   11, 0x08,
     282,   11,   11,   11, 0x08,
     297,   11,   11,   11, 0x08,
     313,   11,   11,   11, 0x08,
     331,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0onFileNew()\0onFileOpen()\0"
    "onFileSave()\0onFileSaveAs()\0onFilePrint()\0"
    "onFileExit()\0onTextChanged()\0available\0"
    "onCopyAvailable(bool)\0onRedoAvailable(bool)\0"
    "onUndoAvailable(bool)\0onCursorPositionChanged()\0"
    "onEditDelete()\0onEditFind()\0onEditReplace()\0"
    "onEditGoto()\0onFormatFont()\0onFormatWrap()\0"
    "onViewToolBar()\0onViewStatusBar()\0"
    "onHelpAbout()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onFileNew(); break;
        case 1: onFileOpen(); break;
        case 2: onFileSave(); break;
        case 3: onFileSaveAs(); break;
        case 4: onFilePrint(); break;
        case 5: onFileExit(); break;
        case 6: onTextChanged(); break;
        case 7: onCopyAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: onRedoAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: onUndoAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: onCursorPositionChanged(); break;
        case 11: onEditDelete(); break;
        case 12: onEditFind(); break;
        case 13: onEditReplace(); break;
        case 14: onEditGoto(); break;
        case 15: onFormatFont(); break;
        case 16: onFormatWrap(); break;
        case 17: onViewToolBar(); break;
        case 18: onViewStatusBar(); break;
        case 19: onHelpAbout(); break;
        default: ;
        }
        _id -= 20;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
