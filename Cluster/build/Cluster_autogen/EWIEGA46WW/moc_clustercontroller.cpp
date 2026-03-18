/****************************************************************************
** Meta object code from reading C++ file 'clustercontroller.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../clustercontroller.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clustercontroller.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN17ClusterControllerE_t {};
} // unnamed namespace

template <> constexpr inline auto ClusterController::qt_create_metaobjectdata<qt_meta_tag_ZN17ClusterControllerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ClusterController",
        "speedChanged",
        "",
        "rpmChanged",
        "fuelChanged",
        "gearChanged",
        "engineTempCChanged",
        "odometerKmChanged",
        "trip1KmChanged",
        "trip2KmChanged",
        "trip1HoursChanged",
        "trip2HoursChanged",
        "trip1AvgSpeedKphChanged",
        "trip2AvgSpeedKphChanged",
        "trip1EnergyKWhPerKmChanged",
        "trip2EnergyKWhPerKmChanged",
        "activeTripChanged",
        "indicatorsChanged",
        "setSpeed",
        "value",
        "setRpm",
        "setFuel",
        "setGear",
        "setEngineTempC",
        "setOdometerKm",
        "setTrip1Km",
        "v",
        "setTrip2Km",
        "setTrip1Hours",
        "setTrip2Hours",
        "setTrip1AvgSpeedKph",
        "setTrip2AvgSpeedKph",
        "setTrip1EnergyKWhPerKm",
        "setTrip2EnergyKWhPerKm",
        "setActiveTrip",
        "setLeftIndicator",
        "setRightIndicator",
        "setEngineWarning",
        "setAbsWarning",
        "setServiceWarning",
        "resetTrip",
        "index",
        "speed",
        "rpm",
        "fuel",
        "gear",
        "engineTempC",
        "odometerKm",
        "leftIndicator",
        "rightIndicator",
        "engineWarning",
        "absWarning",
        "serviceWarning",
        "trip1Km",
        "trip2Km",
        "trip1Hours",
        "trip2Hours",
        "trip1AvgSpeedKph",
        "trip2AvgSpeedKph",
        "trip1EnergyKWhPerKm",
        "trip2EnergyKWhPerKm",
        "activeTrip"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'speedChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'rpmChanged'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'fuelChanged'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'gearChanged'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'engineTempCChanged'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'odometerKmChanged'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'trip1KmChanged'
        QtMocHelpers::SignalData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'trip2KmChanged'
        QtMocHelpers::SignalData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'trip1HoursChanged'
        QtMocHelpers::SignalData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'trip2HoursChanged'
        QtMocHelpers::SignalData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'trip1AvgSpeedKphChanged'
        QtMocHelpers::SignalData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'trip2AvgSpeedKphChanged'
        QtMocHelpers::SignalData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'trip1EnergyKWhPerKmChanged'
        QtMocHelpers::SignalData<void()>(14, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'trip2EnergyKWhPerKmChanged'
        QtMocHelpers::SignalData<void()>(15, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'activeTripChanged'
        QtMocHelpers::SignalData<void()>(16, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'indicatorsChanged'
        QtMocHelpers::SignalData<void()>(17, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setSpeed'
        QtMocHelpers::SlotData<void(int)>(18, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 19 },
        }}),
        // Slot 'setRpm'
        QtMocHelpers::SlotData<void(int)>(20, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 19 },
        }}),
        // Slot 'setFuel'
        QtMocHelpers::SlotData<void(double)>(21, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 19 },
        }}),
        // Slot 'setGear'
        QtMocHelpers::SlotData<void(int)>(22, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 19 },
        }}),
        // Slot 'setEngineTempC'
        QtMocHelpers::SlotData<void(double)>(23, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 19 },
        }}),
        // Slot 'setOdometerKm'
        QtMocHelpers::SlotData<void(double)>(24, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 19 },
        }}),
        // Slot 'setTrip1Km'
        QtMocHelpers::SlotData<void(double)>(25, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 26 },
        }}),
        // Slot 'setTrip2Km'
        QtMocHelpers::SlotData<void(double)>(27, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 26 },
        }}),
        // Slot 'setTrip1Hours'
        QtMocHelpers::SlotData<void(double)>(28, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 26 },
        }}),
        // Slot 'setTrip2Hours'
        QtMocHelpers::SlotData<void(double)>(29, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 26 },
        }}),
        // Slot 'setTrip1AvgSpeedKph'
        QtMocHelpers::SlotData<void(double)>(30, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 26 },
        }}),
        // Slot 'setTrip2AvgSpeedKph'
        QtMocHelpers::SlotData<void(double)>(31, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 26 },
        }}),
        // Slot 'setTrip1EnergyKWhPerKm'
        QtMocHelpers::SlotData<void(double)>(32, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 26 },
        }}),
        // Slot 'setTrip2EnergyKWhPerKm'
        QtMocHelpers::SlotData<void(double)>(33, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 26 },
        }}),
        // Slot 'setActiveTrip'
        QtMocHelpers::SlotData<void(int)>(34, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 26 },
        }}),
        // Slot 'setLeftIndicator'
        QtMocHelpers::SlotData<void(bool)>(35, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 19 },
        }}),
        // Slot 'setRightIndicator'
        QtMocHelpers::SlotData<void(bool)>(36, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 19 },
        }}),
        // Slot 'setEngineWarning'
        QtMocHelpers::SlotData<void(bool)>(37, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 19 },
        }}),
        // Slot 'setAbsWarning'
        QtMocHelpers::SlotData<void(bool)>(38, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 19 },
        }}),
        // Slot 'setServiceWarning'
        QtMocHelpers::SlotData<void(bool)>(39, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 19 },
        }}),
        // Method 'resetTrip'
        QtMocHelpers::MethodData<void(int)>(40, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 41 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'speed'
        QtMocHelpers::PropertyData<int>(42, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'rpm'
        QtMocHelpers::PropertyData<int>(43, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'fuel'
        QtMocHelpers::PropertyData<double>(44, QMetaType::Double, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 2),
        // property 'gear'
        QtMocHelpers::PropertyData<int>(45, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 3),
        // property 'engineTempC'
        QtMocHelpers::PropertyData<double>(46, QMetaType::Double, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 4),
        // property 'odometerKm'
        QtMocHelpers::PropertyData<double>(47, QMetaType::Double, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 5),
        // property 'leftIndicator'
        QtMocHelpers::PropertyData<bool>(48, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 15),
        // property 'rightIndicator'
        QtMocHelpers::PropertyData<bool>(49, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 15),
        // property 'engineWarning'
        QtMocHelpers::PropertyData<bool>(50, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 15),
        // property 'absWarning'
        QtMocHelpers::PropertyData<bool>(51, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 15),
        // property 'serviceWarning'
        QtMocHelpers::PropertyData<bool>(52, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 15),
        // property 'trip1Km'
        QtMocHelpers::PropertyData<double>(53, QMetaType::Double, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 6),
        // property 'trip2Km'
        QtMocHelpers::PropertyData<double>(54, QMetaType::Double, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 7),
        // property 'trip1Hours'
        QtMocHelpers::PropertyData<double>(55, QMetaType::Double, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 8),
        // property 'trip2Hours'
        QtMocHelpers::PropertyData<double>(56, QMetaType::Double, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 9),
        // property 'trip1AvgSpeedKph'
        QtMocHelpers::PropertyData<double>(57, QMetaType::Double, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 10),
        // property 'trip2AvgSpeedKph'
        QtMocHelpers::PropertyData<double>(58, QMetaType::Double, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 11),
        // property 'trip1EnergyKWhPerKm'
        QtMocHelpers::PropertyData<double>(59, QMetaType::Double, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 12),
        // property 'trip2EnergyKWhPerKm'
        QtMocHelpers::PropertyData<double>(60, QMetaType::Double, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 13),
        // property 'activeTrip'
        QtMocHelpers::PropertyData<int>(61, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 14),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ClusterController, qt_meta_tag_ZN17ClusterControllerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject ClusterController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17ClusterControllerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17ClusterControllerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN17ClusterControllerE_t>.metaTypes,
    nullptr
} };

void ClusterController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ClusterController *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->speedChanged(); break;
        case 1: _t->rpmChanged(); break;
        case 2: _t->fuelChanged(); break;
        case 3: _t->gearChanged(); break;
        case 4: _t->engineTempCChanged(); break;
        case 5: _t->odometerKmChanged(); break;
        case 6: _t->trip1KmChanged(); break;
        case 7: _t->trip2KmChanged(); break;
        case 8: _t->trip1HoursChanged(); break;
        case 9: _t->trip2HoursChanged(); break;
        case 10: _t->trip1AvgSpeedKphChanged(); break;
        case 11: _t->trip2AvgSpeedKphChanged(); break;
        case 12: _t->trip1EnergyKWhPerKmChanged(); break;
        case 13: _t->trip2EnergyKWhPerKmChanged(); break;
        case 14: _t->activeTripChanged(); break;
        case 15: _t->indicatorsChanged(); break;
        case 16: _t->setSpeed((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 17: _t->setRpm((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 18: _t->setFuel((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 19: _t->setGear((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 20: _t->setEngineTempC((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 21: _t->setOdometerKm((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 22: _t->setTrip1Km((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 23: _t->setTrip2Km((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 24: _t->setTrip1Hours((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 25: _t->setTrip2Hours((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 26: _t->setTrip1AvgSpeedKph((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 27: _t->setTrip2AvgSpeedKph((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 28: _t->setTrip1EnergyKWhPerKm((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 29: _t->setTrip2EnergyKWhPerKm((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 30: _t->setActiveTrip((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 31: _t->setLeftIndicator((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 32: _t->setRightIndicator((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 33: _t->setEngineWarning((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 34: _t->setAbsWarning((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 35: _t->setServiceWarning((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 36: _t->resetTrip((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ClusterController::*)()>(_a, &ClusterController::speedChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClusterController::*)()>(_a, &ClusterController::rpmChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClusterController::*)()>(_a, &ClusterController::fuelChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClusterController::*)()>(_a, &ClusterController::gearChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClusterController::*)()>(_a, &ClusterController::engineTempCChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClusterController::*)()>(_a, &ClusterController::odometerKmChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClusterController::*)()>(_a, &ClusterController::trip1KmChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClusterController::*)()>(_a, &ClusterController::trip2KmChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClusterController::*)()>(_a, &ClusterController::trip1HoursChanged, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClusterController::*)()>(_a, &ClusterController::trip2HoursChanged, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClusterController::*)()>(_a, &ClusterController::trip1AvgSpeedKphChanged, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClusterController::*)()>(_a, &ClusterController::trip2AvgSpeedKphChanged, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClusterController::*)()>(_a, &ClusterController::trip1EnergyKWhPerKmChanged, 12))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClusterController::*)()>(_a, &ClusterController::trip2EnergyKWhPerKmChanged, 13))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClusterController::*)()>(_a, &ClusterController::activeTripChanged, 14))
            return;
        if (QtMocHelpers::indexOfMethod<void (ClusterController::*)()>(_a, &ClusterController::indicatorsChanged, 15))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<int*>(_v) = _t->speed(); break;
        case 1: *reinterpret_cast<int*>(_v) = _t->rpm(); break;
        case 2: *reinterpret_cast<double*>(_v) = _t->fuel(); break;
        case 3: *reinterpret_cast<int*>(_v) = _t->gear(); break;
        case 4: *reinterpret_cast<double*>(_v) = _t->engineTempC(); break;
        case 5: *reinterpret_cast<double*>(_v) = _t->odometerKm(); break;
        case 6: *reinterpret_cast<bool*>(_v) = _t->leftIndicator(); break;
        case 7: *reinterpret_cast<bool*>(_v) = _t->rightIndicator(); break;
        case 8: *reinterpret_cast<bool*>(_v) = _t->engineWarning(); break;
        case 9: *reinterpret_cast<bool*>(_v) = _t->absWarning(); break;
        case 10: *reinterpret_cast<bool*>(_v) = _t->serviceWarning(); break;
        case 11: *reinterpret_cast<double*>(_v) = _t->trip1Km(); break;
        case 12: *reinterpret_cast<double*>(_v) = _t->trip2Km(); break;
        case 13: *reinterpret_cast<double*>(_v) = _t->trip1Hours(); break;
        case 14: *reinterpret_cast<double*>(_v) = _t->trip2Hours(); break;
        case 15: *reinterpret_cast<double*>(_v) = _t->trip1AvgSpeedKph(); break;
        case 16: *reinterpret_cast<double*>(_v) = _t->trip2AvgSpeedKph(); break;
        case 17: *reinterpret_cast<double*>(_v) = _t->trip1EnergyKWhPerKm(); break;
        case 18: *reinterpret_cast<double*>(_v) = _t->trip2EnergyKWhPerKm(); break;
        case 19: *reinterpret_cast<int*>(_v) = _t->activeTrip(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSpeed(*reinterpret_cast<int*>(_v)); break;
        case 1: _t->setRpm(*reinterpret_cast<int*>(_v)); break;
        case 2: _t->setFuel(*reinterpret_cast<double*>(_v)); break;
        case 3: _t->setGear(*reinterpret_cast<int*>(_v)); break;
        case 4: _t->setEngineTempC(*reinterpret_cast<double*>(_v)); break;
        case 5: _t->setOdometerKm(*reinterpret_cast<double*>(_v)); break;
        case 6: _t->setLeftIndicator(*reinterpret_cast<bool*>(_v)); break;
        case 7: _t->setRightIndicator(*reinterpret_cast<bool*>(_v)); break;
        case 8: _t->setEngineWarning(*reinterpret_cast<bool*>(_v)); break;
        case 9: _t->setAbsWarning(*reinterpret_cast<bool*>(_v)); break;
        case 10: _t->setServiceWarning(*reinterpret_cast<bool*>(_v)); break;
        case 11: _t->setTrip1Km(*reinterpret_cast<double*>(_v)); break;
        case 12: _t->setTrip2Km(*reinterpret_cast<double*>(_v)); break;
        case 13: _t->setTrip1Hours(*reinterpret_cast<double*>(_v)); break;
        case 14: _t->setTrip2Hours(*reinterpret_cast<double*>(_v)); break;
        case 15: _t->setTrip1AvgSpeedKph(*reinterpret_cast<double*>(_v)); break;
        case 16: _t->setTrip2AvgSpeedKph(*reinterpret_cast<double*>(_v)); break;
        case 17: _t->setTrip1EnergyKWhPerKm(*reinterpret_cast<double*>(_v)); break;
        case 18: _t->setTrip2EnergyKWhPerKm(*reinterpret_cast<double*>(_v)); break;
        case 19: _t->setActiveTrip(*reinterpret_cast<int*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *ClusterController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClusterController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17ClusterControllerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ClusterController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 37)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 37;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 37)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 37;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void ClusterController::speedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ClusterController::rpmChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ClusterController::fuelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ClusterController::gearChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ClusterController::engineTempCChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void ClusterController::odometerKmChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void ClusterController::trip1KmChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void ClusterController::trip2KmChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void ClusterController::trip1HoursChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void ClusterController::trip2HoursChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void ClusterController::trip1AvgSpeedKphChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void ClusterController::trip2AvgSpeedKphChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void ClusterController::trip1EnergyKWhPerKmChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void ClusterController::trip2EnergyKWhPerKmChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void ClusterController::activeTripChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void ClusterController::indicatorsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}
QT_WARNING_POP
