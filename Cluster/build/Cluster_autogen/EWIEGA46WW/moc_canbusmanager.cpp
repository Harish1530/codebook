/****************************************************************************
** Meta object code from reading C++ file 'canbusmanager.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../canbusmanager.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'canbusmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN13CanBusManagerE_t {};
} // unnamed namespace

template <> constexpr inline auto CanBusManager::qt_create_metaobjectdata<qt_meta_tag_ZN13CanBusManagerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "CanBusManager",
        "started",
        "",
        "ok",
        "error",
        "stopped",
        "errorText",
        "text",
        "onFramesReceived",
        "start",
        "plugin",
        "interfaceName",
        "bitrate",
        "stop",
        "isRunning",
        "sendSpeedKph",
        "kph",
        "sendRpm",
        "rpm",
        "sendFuelFraction",
        "frac0to1",
        "sendTempC",
        "tempC",
        "sendOdometerKm",
        "km",
        "sendTrip1",
        "hours",
        "avgKph",
        "energyKWhPerKm",
        "sendTrip2",
        "setActiveTrip",
        "index"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'started'
        QtMocHelpers::SignalData<void(bool, const QString &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 3 }, { QMetaType::QString, 4 },
        }}),
        // Signal 'stopped'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'errorText'
        QtMocHelpers::SignalData<void(const QString &)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 7 },
        }}),
        // Slot 'onFramesReceived'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Method 'start'
        QtMocHelpers::MethodData<bool(const QString &, const QString &, int)>(9, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 10 }, { QMetaType::QString, 11 }, { QMetaType::Int, 12 },
        }}),
        // Method 'start'
        QtMocHelpers::MethodData<bool(const QString &, const QString &)>(9, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Bool, {{
            { QMetaType::QString, 10 }, { QMetaType::QString, 11 },
        }}),
        // Method 'stop'
        QtMocHelpers::MethodData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'isRunning'
        QtMocHelpers::MethodData<bool() const>(14, 2, QMC::AccessPublic, QMetaType::Bool),
        // Method 'sendSpeedKph'
        QtMocHelpers::MethodData<void(double)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 16 },
        }}),
        // Method 'sendRpm'
        QtMocHelpers::MethodData<void(double)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 18 },
        }}),
        // Method 'sendFuelFraction'
        QtMocHelpers::MethodData<void(double)>(19, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 20 },
        }}),
        // Method 'sendTempC'
        QtMocHelpers::MethodData<void(double)>(21, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 22 },
        }}),
        // Method 'sendOdometerKm'
        QtMocHelpers::MethodData<void(double)>(23, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 24 },
        }}),
        // Method 'sendTrip1'
        QtMocHelpers::MethodData<void(double, double, double, double)>(25, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 24 }, { QMetaType::Double, 26 }, { QMetaType::Double, 27 }, { QMetaType::Double, 28 },
        }}),
        // Method 'sendTrip2'
        QtMocHelpers::MethodData<void(double, double, double, double)>(29, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 24 }, { QMetaType::Double, 26 }, { QMetaType::Double, 27 }, { QMetaType::Double, 28 },
        }}),
        // Method 'setActiveTrip'
        QtMocHelpers::MethodData<void(int)>(30, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 31 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<CanBusManager, qt_meta_tag_ZN13CanBusManagerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject CanBusManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13CanBusManagerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13CanBusManagerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13CanBusManagerE_t>.metaTypes,
    nullptr
} };

void CanBusManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<CanBusManager *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->started((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 1: _t->stopped(); break;
        case 2: _t->errorText((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->onFramesReceived(); break;
        case 4: { bool _r = _t->start((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: { bool _r = _t->start((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->stop(); break;
        case 7: { bool _r = _t->isRunning();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->sendSpeedKph((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 9: _t->sendRpm((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 10: _t->sendFuelFraction((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 11: _t->sendTempC((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 12: _t->sendOdometerKm((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 13: _t->sendTrip1((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[4]))); break;
        case 14: _t->sendTrip2((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[4]))); break;
        case 15: _t->setActiveTrip((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (CanBusManager::*)(bool , const QString & )>(_a, &CanBusManager::started, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (CanBusManager::*)()>(_a, &CanBusManager::stopped, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (CanBusManager::*)(const QString & )>(_a, &CanBusManager::errorText, 2))
            return;
    }
}

const QMetaObject *CanBusManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CanBusManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13CanBusManagerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CanBusManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void CanBusManager::started(bool _t1, const QString & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}

// SIGNAL 1
void CanBusManager::stopped()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void CanBusManager::errorText(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}
QT_WARNING_POP
