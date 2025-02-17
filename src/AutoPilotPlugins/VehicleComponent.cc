/****************************************************************************
 *
 * (c) 2009-2024 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/


/// @file
///     @author Don Gagne <don@thegagnes.com>

#include "VehicleComponent.h"
#include "ParameterManager.h"
#include "Vehicle.h"

#include <QtQml/QQmlContext>
#include <QtQuick/QQuickItem>

VehicleComponent::VehicleComponent(Vehicle* vehicle, AutoPilotPlugin* autopilot, AutoPilotPlugin::KnownVehicleComponent KnownVehicleComponent, QObject* parent) 
    : QObject           (parent)
    , _vehicle          (vehicle)
    , _autopilot        (autopilot)
    , _KnownVehicleComponent  (KnownVehicleComponent)
{
    if (!vehicle || !autopilot) {
        qWarning() << "Internal error";
    }
}

VehicleComponent::~VehicleComponent()
{
    
}

void VehicleComponent::addSummaryQmlComponent(QQmlContext* context, QQuickItem* parent)
{
    if (context) {
        // FIXME: We own this object now, need to delete somewhere
        QQmlComponent component(context->engine(), QUrl::fromUserInput("qrc:/qml/VehicleComponentSummaryButton.qml"));
        if (component.status() == QQmlComponent::Error) {
            qWarning() << component.errors();
        } else {
            QQuickItem* item = qobject_cast<QQuickItem*>(component.create(context));
            if (item) {
                item->setParentItem(parent);
                item->setProperty("vehicleComponent", QVariant::fromValue(this));
            } else {
                qWarning() << "Internal error";
            }
        }
    } else {
        qWarning() << "Internal error";
    }
}

void VehicleComponent::setupTriggerSignals(void)
{
    // Watch for changed on trigger list params
    for (const QString &paramName: setupCompleteChangedTriggerList()) {
        if (_vehicle->parameterManager()->parameterExists(ParameterManager::defaultComponentId, paramName)) {
            Fact* fact = _vehicle->parameterManager()->getParameter(ParameterManager::defaultComponentId, paramName);
            connect(fact, &Fact::valueChanged, this, &VehicleComponent::_triggerUpdated);
        }
    }
}

void VehicleComponent::_triggerUpdated(QVariant /*value*/)
{
    emit setupCompleteChanged();
}
