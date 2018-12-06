/* Generated from orogen/lib/orogen/templates/tasks/Task.cpp */

#include "MotorWriterDispatcher.hpp"

using namespace heads_live_deployments;

MotorWriterDispatcher::MotorWriterDispatcher(std::string const& name)
    : MotorWriterDispatcherBase(name)
{
}

MotorWriterDispatcher::MotorWriterDispatcher(std::string const& name, RTT::ExecutionEngine* engine)
    : MotorWriterDispatcherBase(name, engine)
{
}

MotorWriterDispatcher::~MotorWriterDispatcher()
{
}



/// The following lines are template definitions for the various state machine
// hooks defined by Orocos::RTT. See MotorWriterDispatcher.hpp for more detailed
// documentation about them.

bool MotorWriterDispatcher::configureHook()
{
    if (! MotorWriterDispatcherBase::configureHook())
        return false;
    
    joints.resize(3);
    yaw.resize(1);
    pitch.resize(1);
    roll.resize(1);
    return true;
}
bool MotorWriterDispatcher::startHook()
{
    if (! MotorWriterDispatcherBase::startHook())
        return false;
    return true;
}
void MotorWriterDispatcher::updateHook()
{
    while (_joints.read(joints, false) == RTT::NewData) {
        yaw.time = joints.time;
        yaw.elements[0] = joints.elements[0];
        pitch.time = joints.time;
        pitch.elements[0] = joints.elements[1];
        roll.time = joints.time;
        roll.elements[0] = joints.elements[2];

        _yaw.write(yaw);
        _pitch.write(pitch);
        _roll.write(roll);
    }

    // Call updateHook after the dispatch, it will schedule
    // the other tasks
    MotorWriterDispatcherBase::updateHook();
}
void MotorWriterDispatcher::errorHook()
{
    MotorWriterDispatcherBase::errorHook();
}
void MotorWriterDispatcher::stopHook()
{
    MotorWriterDispatcherBase::stopHook();
}
void MotorWriterDispatcher::cleanupHook()
{
    MotorWriterDispatcherBase::cleanupHook();
}
