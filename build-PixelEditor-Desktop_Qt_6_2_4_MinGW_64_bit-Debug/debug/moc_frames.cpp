/****************************************************************************
** Meta object code from reading C++ file 'frames.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../PixelEditor/frames.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frames.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Frames_t {
    const uint offsetsAndSize[40];
    char stringdata0[202];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Frames_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Frames_t qt_meta_stringdata_Frames = {
    {
QT_MOC_LITERAL(0, 6), // "Frames"
QT_MOC_LITERAL(7, 12), // "displayFrame"
QT_MOC_LITERAL(20, 0), // ""
QT_MOC_LITERAL(21, 7), // "QImage*"
QT_MOC_LITERAL(29, 5), // "frame"
QT_MOC_LITERAL(35, 14), // "widthAndHeight"
QT_MOC_LITERAL(50, 5), // "width"
QT_MOC_LITERAL(56, 6), // "height"
QT_MOC_LITERAL(63, 8), // "addFrame"
QT_MOC_LITERAL(72, 17), // "addFrameWithFrame"
QT_MOC_LITERAL(90, 11), // "deleteFrame"
QT_MOC_LITERAL(102, 11), // "updateFrame"
QT_MOC_LITERAL(114, 5), // "color"
QT_MOC_LITERAL(120, 3), // "row"
QT_MOC_LITERAL(124, 6), // "column"
QT_MOC_LITERAL(131, 11), // "changeFrame"
QT_MOC_LITERAL(143, 8), // "upOrDown"
QT_MOC_LITERAL(152, 13), // "playAllFrames"
QT_MOC_LITERAL(166, 17), // "setWidthAndHeight"
QT_MOC_LITERAL(184, 17) // "getWidthAndHeight"

    },
    "Frames\0displayFrame\0\0QImage*\0frame\0"
    "widthAndHeight\0width\0height\0addFrame\0"
    "addFrameWithFrame\0deleteFrame\0updateFrame\0"
    "color\0row\0column\0changeFrame\0upOrDown\0"
    "playAllFrames\0setWidthAndHeight\0"
    "getWidthAndHeight"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Frames[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   74,    2, 0x06,    1 /* Public */,
       5,    2,   77,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    0,   82,    2, 0x0a,    6 /* Public */,
       9,    1,   83,    2, 0x0a,    7 /* Public */,
      10,    0,   86,    2, 0x0a,    9 /* Public */,
      11,    3,   87,    2, 0x0a,   10 /* Public */,
      15,    1,   94,    2, 0x0a,   14 /* Public */,
      17,    0,   97,    2, 0x0a,   16 /* Public */,
      18,    2,   98,    2, 0x0a,   17 /* Public */,
      19,    0,  103,    2, 0x0a,   20 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QImage,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QColor, QMetaType::Int, QMetaType::Int,   12,   13,   14,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void,

       0        // eod
};

void Frames::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Frames *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->displayFrame((*reinterpret_cast< std::add_pointer_t<QImage*>>(_a[1]))); break;
        case 1: _t->widthAndHeight((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 2: _t->addFrame(); break;
        case 3: _t->addFrameWithFrame((*reinterpret_cast< std::add_pointer_t<QImage>>(_a[1]))); break;
        case 4: _t->deleteFrame(); break;
        case 5: _t->updateFrame((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 6: _t->changeFrame((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 7: _t->playAllFrames(); break;
        case 8: _t->setWidthAndHeight((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 9: _t->getWidthAndHeight(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Frames::*)(QImage * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Frames::displayFrame)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Frames::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Frames::widthAndHeight)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Frames::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Frames.offsetsAndSize,
    qt_meta_data_Frames,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Frames_t
, QtPrivate::TypeAndForceComplete<Frames, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QImage *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QImage, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QColor, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Frames::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Frames::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Frames.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Frames::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Frames::displayFrame(QImage * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Frames::widthAndHeight(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
