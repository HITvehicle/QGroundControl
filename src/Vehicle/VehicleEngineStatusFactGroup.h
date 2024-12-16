/****************************************************************************
 *
 * (c) 2009-2020 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#pragma once

#include "FactGroup.h"
#include "QGCMAVLink.h"

class VehicleEngineStatusFactGroup : public FactGroup
{
    Q_OBJECT

public:
    VehicleEngineStatusFactGroup(QObject* parent = nullptr);

    Q_PROPERTY(Fact* engine_rpmFirst    READ engine_rpmFirst    CONSTANT)
    Q_PROPERTY(Fact* engine_rpmSecond   READ engine_rpmSecond   CONSTANT)
    Q_PROPERTY(Fact* engine_rpmThird    READ engine_rpmThird    CONSTANT)
    Q_PROPERTY(Fact* engine_rpmFourth   READ engine_rpmFourth   CONSTANT)
    Q_PROPERTY(Fact* engine_rpmFifth    READ engine_rpmFifth    CONSTANT)
    Q_PROPERTY(Fact* engine_rpmSixth    READ engine_rpmSixth    CONSTANT)

    Q_PROPERTY(Fact* engine_stateFirst    READ engine_stateFirst    CONSTANT)
    Q_PROPERTY(Fact* engine_stateSecond   READ engine_stateSecond   CONSTANT)
    Q_PROPERTY(Fact* engine_stateThird    READ engine_stateThird    CONSTANT)
    Q_PROPERTY(Fact* engine_stateFourth   READ engine_stateFourth   CONSTANT)
    Q_PROPERTY(Fact* engine_stateFifth    READ engine_stateFifth    CONSTANT)
    Q_PROPERTY(Fact* engine_stateSixth    READ engine_stateSixth    CONSTANT)

    Q_PROPERTY(Fact* pos_sensor_left_roll       READ pos_sensor_left_roll      CONSTANT)
    Q_PROPERTY(Fact* pos_sensor_right_roll      READ pos_sensor_right_roll     CONSTANT)
    Q_PROPERTY(Fact* pos_sensor_left_pitch      READ pos_sensor_left_pitch     CONSTANT)
    Q_PROPERTY(Fact* pos_sensor_right_pitch     READ pos_sensor_right_pitch    CONSTANT)
    Q_PROPERTY(Fact* vehicle_oil                READ vehicle_oil               CONSTANT)

    Fact* engine_rpmFirst ()  {return &_engine_rpmFirstFact;}
    Fact* engine_rpmSecond () {return &_engine_rpmSecondFact;}
    Fact* engine_rpmThird ()  {return &_engine_rpmThirdFact;}
    Fact* engine_rpmFourth () {return &_engine_rpmFourthFact;}
    Fact* engine_rpmFifth ()  {return &_engine_rpmFifthFact;}
    Fact* engine_rpmSixth ()  {return &_engine_rpmSixthFact;}

    Fact* engine_stateFirst ()  {return &_engine_stateFirstFact;}
    Fact* engine_stateSecond () {return &_engine_stateSecondFact;}
    Fact* engine_stateThird ()  {return &_engine_stateThirdFact;}
    Fact* engine_stateFourth () {return &_engine_stateFourthFact;}
    Fact* engine_stateFifth ()  {return &_engine_stateFifthFact;}
    Fact* engine_stateSixth ()  {return &_engine_stateSixthFact;}

    Fact* pos_sensor_left_roll ()    {return &_pos_sensor_left_rollFact;}
    Fact* pos_sensor_right_roll ()   {return &_pos_sensor_right_rollFact;}
    Fact* pos_sensor_left_pitch ()   {return &_pos_sensor_left_pitchFact;}
    Fact* pos_sensor_right_pitch ()  {return &_pos_sensor_right_pitchFact;}
    Fact* vehicle_oil ()       {return &_vehicle_oilFact;}

    void handleMessage(Vehicle* vehicle, mavlink_message_t& message) override;

    static const char* _engine_rpmFirstFactName;
    static const char* _engine_rpmSecondFactName;
    static const char* _engine_rpmThirdFactName;
    static const char* _engine_rpmFourthFactName;
    static const char* _engine_rpmFifthFactName;
    static const char* _engine_rpmSixthFactName;

    static const char* _engine_stateFirstFactName;
    static const char* _engine_stateSecondFactName;
    static const char* _engine_stateThirdFactName;
    static const char* _engine_stateFourthFactName;
    static const char* _engine_stateFifthFactName;
    static const char* _engine_stateSixthFactName;

    static const char* _pos_sensor_left_rollFactName;
    static const char* _pos_sensor_right_rollFactName;
    static const char* _pos_sensor_left_pitchFactName;
    static const char* _pos_sensor_right_pitchFactName;
    static const char* _vehicle_oilFactName;

private:
    Fact _engine_rpmFirstFact;
    Fact _engine_rpmSecondFact;
    Fact _engine_rpmThirdFact;
    Fact _engine_rpmFourthFact;
    Fact _engine_rpmFifthFact;
    Fact _engine_rpmSixthFact;

    Fact _engine_stateFirstFact;
    Fact _engine_stateSecondFact;
    Fact _engine_stateThirdFact;
    Fact _engine_stateFourthFact;
    Fact _engine_stateFifthFact;
    Fact _engine_stateSixthFact;

    Fact _pos_sensor_left_rollFact;
    Fact _pos_sensor_right_rollFact;
    Fact _pos_sensor_left_pitchFact;
    Fact _pos_sensor_right_pitchFact;
    Fact _vehicle_oilFact;
};

//class VehicleLocalPositionSetpointFactGroup : public FactGroup
//{
//    Q_OBJECT

//public:
//    VehicleLocalPositionSetpointFactGroup(QObject* parent = nullptr);

//    Q_PROPERTY(Fact* x     READ x    CONSTANT)
//    Q_PROPERTY(Fact* y     READ y    CONSTANT)
//    Q_PROPERTY(Fact* z     READ z    CONSTANT)
//    Q_PROPERTY(Fact* vx    READ vx   CONSTANT)
//    Q_PROPERTY(Fact* vy    READ vy   CONSTANT)
//    Q_PROPERTY(Fact* vz    READ vz   CONSTANT)

//    Fact* x    () { return &_xFact; }
//    Fact* y    () { return &_yFact; }
//    Fact* z    () { return &_zFact; }
//    Fact* vx   () { return &_vxFact; }
//    Fact* vy   () { return &_vyFact; }
//    Fact* vz   () { return &_vzFact; }

//    // Overrides from FactGroup
//    void handleMessage(Vehicle* vehicle, mavlink_message_t& message) override;

//    static const char* _xFactName;
//    static const char* _yFactName;
//    static const char* _zFactName;
//    static const char* _vxFactName;
//    static const char* _vyFactName;
//    static const char* _vzFactName;

//private:
//    Fact _xFact;
//    Fact _yFact;
//    Fact _zFact;
//    Fact _vxFact;
//    Fact _vyFact;
//    Fact _vzFact;
//};
