/****************************************************************************
** Meta object code from reading C++ file 'bank_bridge.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../include/bank_bridge.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bank_bridge.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BankBridge_t {
    const uint offsetsAndSize[58];
    char stringdata0[368];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_BankBridge_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_BankBridge_t qt_meta_stringdata_BankBridge = {
    {
QT_MOC_LITERAL(0, 10), // "BankBridge"
QT_MOC_LITERAL(11, 14), // "accountCreated"
QT_MOC_LITERAL(26, 0), // ""
QT_MOC_LITERAL(27, 9), // "accountId"
QT_MOC_LITERAL(37, 14), // "accountDeleted"
QT_MOC_LITERAL(52, 14), // "balanceChanged"
QT_MOC_LITERAL(67, 10), // "newBalance"
QT_MOC_LITERAL(78, 5), // "error"
QT_MOC_LITERAL(84, 7), // "message"
QT_MOC_LITERAL(92, 15), // "accountsUpdated"
QT_MOC_LITERAL(108, 16), // "detailsRetrieved"
QT_MOC_LITERAL(125, 7), // "details"
QT_MOC_LITERAL(133, 23), // "personAccountsRetrieved"
QT_MOC_LITERAL(157, 12), // "accountsList"
QT_MOC_LITERAL(170, 20), // "allAccountsRetrieved"
QT_MOC_LITERAL(191, 13), // "createAccount"
QT_MOC_LITERAL(205, 10), // "personName"
QT_MOC_LITERAL(216, 6), // "cardId"
QT_MOC_LITERAL(223, 14), // "initialBalance"
QT_MOC_LITERAL(238, 13), // "deleteAccount"
QT_MOC_LITERAL(252, 7), // "deposit"
QT_MOC_LITERAL(260, 6), // "amount"
QT_MOC_LITERAL(267, 8), // "withdraw"
QT_MOC_LITERAL(276, 10), // "getAccount"
QT_MOC_LITERAL(287, 14), // "getAllAccounts"
QT_MOC_LITERAL(302, 8), // "saveData"
QT_MOC_LITERAL(311, 17), // "getAccountDetails"
QT_MOC_LITERAL(329, 17), // "getPersonAccounts"
QT_MOC_LITERAL(347, 20) // "getAllAccountDetails"

    },
    "BankBridge\0accountCreated\0\0accountId\0"
    "accountDeleted\0balanceChanged\0newBalance\0"
    "error\0message\0accountsUpdated\0"
    "detailsRetrieved\0details\0"
    "personAccountsRetrieved\0accountsList\0"
    "allAccountsRetrieved\0createAccount\0"
    "personName\0cardId\0initialBalance\0"
    "deleteAccount\0deposit\0amount\0withdraw\0"
    "getAccount\0getAllAccounts\0saveData\0"
    "getAccountDetails\0getPersonAccounts\0"
    "getAllAccountDetails"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BankBridge[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  128,    2, 0x06,    1 /* Public */,
       4,    1,  131,    2, 0x06,    3 /* Public */,
       5,    2,  134,    2, 0x06,    5 /* Public */,
       7,    1,  139,    2, 0x06,    8 /* Public */,
       9,    0,  142,    2, 0x06,   10 /* Public */,
      10,    1,  143,    2, 0x06,   11 /* Public */,
      12,    1,  146,    2, 0x06,   13 /* Public */,
      14,    1,  149,    2, 0x06,   15 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      15,    3,  152,    2, 0x0a,   17 /* Public */,
      15,    2,  159,    2, 0x2a,   21 /* Public | MethodCloned */,
      19,    1,  164,    2, 0x0a,   24 /* Public */,
      20,    2,  167,    2, 0x0a,   26 /* Public */,
      22,    2,  172,    2, 0x0a,   29 /* Public */,
      23,    1,  177,    2, 0x0a,   32 /* Public */,
      24,    0,  180,    2, 0x0a,   34 /* Public */,
      25,    0,  181,    2, 0x0a,   35 /* Public */,
      26,    1,  182,    2, 0x0a,   36 /* Public */,
      27,    1,  185,    2, 0x0a,   38 /* Public */,
      28,    0,  188,    2, 0x0a,   40 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Double,    3,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonObject,   11,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString,   13,

 // slots: parameters
    QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Double,   16,   17,   18,
    QMetaType::Int, QMetaType::QString, QMetaType::QString,   16,   17,
    QMetaType::Bool, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Double,    3,   21,
    QMetaType::Void, QMetaType::Int, QMetaType::Double,    3,   21,
    QMetaType::QJsonObject, QMetaType::Int,    3,
    QMetaType::QJsonArray,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void,

       0        // eod
};

void BankBridge::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BankBridge *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->accountCreated((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->accountDeleted((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->balanceChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2]))); break;
        case 3: _t->error((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->accountsUpdated(); break;
        case 5: _t->detailsRetrieved((*reinterpret_cast< std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 6: _t->personAccountsRetrieved((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->allAccountsRetrieved((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: { int _r = _t->createAccount((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 9: { int _r = _t->createAccount((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 10: { bool _r = _t->deleteAccount((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->deposit((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2]))); break;
        case 12: _t->withdraw((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2]))); break;
        case 13: { QJsonObject _r = _t->getAccount((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QJsonObject*>(_a[0]) = std::move(_r); }  break;
        case 14: { QJsonArray _r = _t->getAllAccounts();
            if (_a[0]) *reinterpret_cast< QJsonArray*>(_a[0]) = std::move(_r); }  break;
        case 15: _t->saveData(); break;
        case 16: _t->getAccountDetails((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 17: _t->getPersonAccounts((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 18: _t->getAllAccountDetails(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BankBridge::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BankBridge::accountCreated)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BankBridge::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BankBridge::accountDeleted)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BankBridge::*)(int , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BankBridge::balanceChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (BankBridge::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BankBridge::error)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (BankBridge::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BankBridge::accountsUpdated)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (BankBridge::*)(const QJsonObject & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BankBridge::detailsRetrieved)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (BankBridge::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BankBridge::personAccountsRetrieved)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (BankBridge::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BankBridge::allAccountsRetrieved)) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject BankBridge::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_BankBridge.offsetsAndSize,
    qt_meta_data_BankBridge,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_BankBridge_t
, QtPrivate::TypeAndForceComplete<BankBridge, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QJsonObject &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<QJsonObject, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QJsonArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *BankBridge::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BankBridge::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BankBridge.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BankBridge::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void BankBridge::accountCreated(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BankBridge::accountDeleted(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BankBridge::balanceChanged(int _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void BankBridge::error(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void BankBridge::accountsUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void BankBridge::detailsRetrieved(const QJsonObject & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void BankBridge::personAccountsRetrieved(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void BankBridge::allAccountsRetrieved(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
