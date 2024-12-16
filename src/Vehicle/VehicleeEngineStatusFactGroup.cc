/****************************************************************************
 *
 * (c) 2009-2020 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#include "VehicleEngineStatusFactGroup.h"
#include "Vehicle.h"

#include <QtMath>

const char* VehicleEngineStatusFactGroup::_engine_rpmFirstFactName  =     "rpm0";
const char* VehicleEngineStatusFactGroup::_engine_rpmSecondFactName =     "rpm1";
const char* VehicleEngineStatusFactGroup::_engine_rpmThirdFactName  =     "rpm2";
const char* VehicleEngineStatusFactGroup::_engine_rpmFourthFactName =     "rpm3";
const char* VehicleEngineStatusFactGroup::_engine_rpmFifthFactName  =     "rpm4";
const char* VehicleEngineStatusFactGroup::_engine_rpmSixthFactName  =     "rpm5";

const char* VehicleEngineStatusFactGroup::_engine_stateFirstFactName  =     "state0";
const char* VehicleEngineStatusFactGroup::_engine_stateSecondFactName =     "state1";
const char* VehicleEngineStatusFactGroup::_engine_stateThirdFactName  =     "state2";
const char* VehicleEngineStatusFactGroup::_engine_stateFourthFactName =     "state3";
const char* VehicleEngineStatusFactGroup::_engine_stateFifthFactName  =     "state4";
const char* VehicleEngineStatusFactGroup::_engine_stateSixthFactName  =     "state5";

const char* VehicleEngineStatusFactGroup::_vehicle_oilFactName      =     "oil";
const char* VehicleEngineStatusFactGroup::_pos_sensor_left_rollFactName  =     "servo_left_roll";
const char* VehicleEngineStatusFactGroup::_pos_sensor_right_rollFactName =     "servo_right_roll";
const char* VehicleEngineStatusFactGroup::_pos_sensor_left_pitchFactName  =     "servo_left_pitch";
const char* VehicleEngineStatusFactGroup::_pos_sensor_right_pitchFactName =     "servo_right_pitch";

VehicleEngineStatusFactGroup::VehicleEngineStatusFactGroup(QObject* parent)
    : FactGroup(1000, ":/json/Vehicle/EngineStatusFactGroup.json", parent)
    , _engine_rpmFirstFact    (0, _engine_rpmFirstFactName,      FactMetaData::valueTypeUint16)
    , _engine_rpmSecondFact   (0, _engine_rpmSecondFactName,     FactMetaData::valueTypeUint16)
    , _engine_rpmThirdFact    (0, _engine_rpmThirdFactName,      FactMetaData::valueTypeUint16)
    , _engine_rpmFourthFact   (0, _engine_rpmFourthFactName,     FactMetaData::valueTypeUint16)
    , _engine_rpmFifthFact    (0, _engine_rpmFifthFactName,      FactMetaData::valueTypeUint16)
    , _engine_rpmSixthFact    (0, _engine_rpmSixthFactName,      FactMetaData::valueTypeUint16)
    , _engine_stateFirstFact  (0, _engine_stateFirstFactName,    FactMetaData::valueTypeUint8)
    , _engine_stateSecondFact (0, _engine_stateSecondFactName,   FactMetaData::valueTypeUint8)
    , _engine_stateThirdFact  (0, _engine_stateThirdFactName,    FactMetaData::valueTypeUint8)
    , _engine_stateFourthFact (0, _engine_stateFourthFactName,   FactMetaData::valueTypeUint8)
    , _engine_stateFifthFact  (0, _engine_stateFifthFactName,    FactMetaData::valueTypeUint8)
    , _engine_stateSixthFact  (0, _engine_stateSixthFactName,    FactMetaData::valueTypeUint8)
    , _pos_sensor_left_rollFact     (0, _pos_sensor_left_rollFactName,       FactMetaData::valueTypeInt16)
    , _pos_sensor_right_rollFact    (0, _pos_sensor_right_rollFactName,      FactMetaData::valueTypeInt16)
    , _pos_sensor_left_pitchFact    (0, _pos_sensor_left_pitchFactName,      FactMetaData::valueTypeInt16)
    , _pos_sensor_right_pitchFact   (0, _pos_sensor_right_pitchFactName,     FactMetaData::valueTypeInt16)
    , _vehicle_oilFact        (0, _vehicle_oilFactName,          FactMetaData::valueTypeUint8)
{
    _addFact(&_engine_rpmFirstFact,     _engine_rpmFirstFactName);
    _addFact(&_engine_rpmSecondFact,    _engine_rpmSecondFactName);
    _addFact(&_engine_rpmThirdFact,     _engine_rpmThirdFactName);
    _addFact(&_engine_rpmFourthFact,    _engine_rpmFourthFactName);
    _addFact(&_engine_rpmFifthFact,     _engine_rpmFifthFactName);
    _addFact(&_engine_rpmSixthFact,     _engine_rpmSixthFactName);

    _addFact(&_engine_stateFirstFact,     _engine_stateFirstFactName);
    _addFact(&_engine_stateSecondFact,    _engine_stateSecondFactName);
    _addFact(&_engine_stateThirdFact,     _engine_stateThirdFactName);
    _addFact(&_engine_stateFourthFact,    _engine_stateFourthFactName);
    _addFact(&_engine_stateFifthFact,     _engine_stateFifthFactName);
    _addFact(&_engine_stateSixthFact,     _engine_stateSixthFactName);

    _addFact(&_pos_sensor_left_rollFact,    _pos_sensor_left_rollFactName);
    _addFact(&_pos_sensor_right_rollFact,   _pos_sensor_right_rollFactName);
    _addFact(&_pos_sensor_left_pitchFact,    _pos_sensor_left_pitchFactName);
    _addFact(&_pos_sensor_right_pitchFact,   _pos_sensor_right_pitchFactName);
    _addFact(&_vehicle_oilFact,        _vehicle_oilFactName);

    _engine_rpmFirstFact.setRawValue(qQNaN());
    _engine_rpmSecondFact.setRawValue(qQNaN());
    _engine_rpmThirdFact.setRawValue(qQNaN());
    _engine_rpmFourthFact.setRawValue(qQNaN());
    _engine_rpmFifthFact.setRawValue(qQNaN());
    _engine_rpmSixthFact.setRawValue(qQNaN());

    _engine_stateFirstFact.setRawValue(qQNaN());
    _engine_stateSecondFact.setRawValue(qQNaN());
    _engine_stateThirdFact.setRawValue(qQNaN());
    _engine_stateFourthFact.setRawValue(qQNaN());
    _engine_stateFifthFact.setRawValue(qQNaN());
    _engine_stateSixthFact.setRawValue(qQNaN());

    _pos_sensor_left_rollFact.setRawValue(qQNaN());
    _pos_sensor_right_rollFact.setRawValue(qQNaN());
    _pos_sensor_left_pitchFact.setRawValue(qQNaN());
    _pos_sensor_right_pitchFact.setRawValue(qQNaN());
    _vehicle_oilFact.setRawValue(qQNaN());
}

void VehicleEngineStatusFactGroup::handleMessage(Vehicle* /* vehicle */, mavlink_message_t& message)
{
    if(message.msgid != MAVLINK_MSG_ID_ENGINE_STATUS)
    {
        return;
    }
    mavlink_engine_status_t engine_status;
    mavlink_msg_engine_status_decode(&message, &engine_status);

    _engine_rpmFirstFact.setRawValue(engine_status.engine_rpm[0]);
    _engine_rpmSecondFact.setRawValue(engine_status.engine_rpm[1]);
    _engine_rpmThirdFact.setRawValue(engine_status.engine_rpm[2]);
    _engine_rpmFourthFact.setRawValue(engine_status.engine_rpm[3]);
    _engine_rpmFifthFact.setRawValue(engine_status.engine_rpm[4]);
    _engine_rpmSixthFact.setRawValue(engine_status.engine_rpm[5]);

    _engine_stateFirstFact.setRawValue(engine_status.engine_state[0]);
    _engine_stateSecondFact.setRawValue(engine_status.engine_state[1]);
    _engine_stateThirdFact.setRawValue(engine_status.engine_state[2]);
    _engine_stateFourthFact.setRawValue(engine_status.engine_state[3]);
    _engine_stateFifthFact.setRawValue(engine_status.engine_state[4]);
    _engine_stateSixthFact.setRawValue(engine_status.engine_state[5]);

    _pos_sensor_left_rollFact.setRawValue(engine_status.pos_sensor_left_roll);
    _pos_sensor_right_rollFact.setRawValue(engine_status.pos_sensor_right_roll);
    _pos_sensor_left_pitchFact.setRawValue(engine_status.pos_sensor_left_pitch);
    _pos_sensor_right_pitchFact.setRawValue(engine_status.pos_sensor_right_pitch);
    _vehicle_oilFact.setRawValue(engine_status.vehicle_oil);
    _setTelemetryAvailable(true);
}

