/****************************************************************************
** Meta object code from reading C++ file 'website.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../website/website.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'website.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_website[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x08,
      31,    8,    8,    8, 0x08,
      53,    8,    8,    8, 0x08,
      75,    8,    8,    8, 0x08,
      92,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_website[] = {
    "website\0\0on_kepler60_clicked()\0"
    "on_kepler30_clicked()\0on_kepler29_clicked()\0"
    "on_rem_clicked()\0on_bologna_clicked()\0"
};

void website::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        website *_t = static_cast<website *>(_o);
        switch (_id) {
        case 0: _t->on_kepler60_clicked(); break;
        case 1: _t->on_kepler30_clicked(); break;
        case 2: _t->on_kepler29_clicked(); break;
        case 3: _t->on_rem_clicked(); break;
        case 4: _t->on_bologna_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData website::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject website::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_website,
      qt_meta_data_website, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &website::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *website::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *website::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_website))
        return static_cast<void*>(const_cast< website*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int website::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
