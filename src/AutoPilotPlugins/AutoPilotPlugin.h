/****************************************************************************
 *
 * (c) 2009-2024 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#pragma once

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QVariantList>

class Vehicle;
class FirmwarePlugin;
class VehicleComponent;

/// This is the base class for AutoPilot plugins
///
/// The AutoPilotPlugin class is an abstract base class which represent the methods and objects
/// which are specific to a certain AutoPilot. This is the only place where AutoPilot specific
/// code should reside in QGroundControl. The remainder of the QGroundControl source is
/// generic to a common mavlink implementation.

class AutoPilotPlugin : public QObject
{
    Q_OBJECT

public:
    AutoPilotPlugin(Vehicle* vehicle, QObject* parent);
    ~AutoPilotPlugin();

    // Vehicle Components which are available for firmware types
    enum KnownVehicleComponent {
        KnownRadioVehicleComponent,
        KnownFlightModesVehicleComponent,
        KnownSensorsVehicleComponent,
        KnownSafetyVehicleComponent,
        KnownPowerVehicleComponent,
        UnknownVehicleComponent // Firmware specific vehicle components
    };
    Q_ENUM(KnownVehicleComponent)

    Q_PROPERTY(QVariantList vehicleComponents   READ vehicleComponents  NOTIFY vehicleComponentsChanged)    ///< List of VehicleComponent objects
    Q_PROPERTY(bool         setupComplete       READ setupComplete      NOTIFY setupCompleteChanged)        ///< false: One or more vehicle components require setup

    /// Called when parameters are ready for the first time. Note that parameters may still be missing.
    /// Overrides must call base class.
    virtual void parametersReadyPreChecks(void);

    // Must be implemented by derived class
    virtual const QVariantList& vehicleComponents(void) = 0;

    /// Returns the name of the vehicle component which must complete setup prior to this one. Empty string for none.
    Q_INVOKABLE virtual QString prerequisiteSetup(VehicleComponent* component) const = 0;

    Q_INVOKABLE VehicleComponent* findKnownVehicleComponent(KnownVehicleComponent knownVehicleComponent);

    Q_INVOKABLE bool knownVehicleComponentAvailable(KnownVehicleComponent knownVehicleComponent) { return findKnownVehicleComponent(knownVehicleComponent) != nullptr; }

    // Property accessors
    bool setupComplete(void) const;

signals:
    void setupCompleteChanged       (void);
    void vehicleComponentsChanged   (void);

protected:
    Vehicle*        _vehicle;
    FirmwarePlugin* _firmwarePlugin;
    bool            _setupComplete;

private slots:
    void _recalcSetupComplete(void);
};
