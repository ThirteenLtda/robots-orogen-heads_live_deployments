/* Generated from orogen/lib/orogen/templates/tasks/Task.cpp */

#include "IMUMotorDriverScheduler.hpp"

using namespace heads_live_deployments;

IMUMotorDriverScheduler::IMUMotorDriverScheduler(std::string const& name, TaskCore::TaskState initial_state)
    : IMUMotorDriverSchedulerBase(name, initial_state)
{
}

IMUMotorDriverScheduler::IMUMotorDriverScheduler(std::string const& name, RTT::ExecutionEngine* engine, TaskCore::TaskState initial_state)
    : IMUMotorDriverSchedulerBase(name, engine, initial_state)
{
}

IMUMotorDriverScheduler::~IMUMotorDriverScheduler()
{
}



/// The following lines are template definitions for the various state machine
// hooks defined by Orocos::RTT. See IMUMotorDriverScheduler.hpp for more detailed
// documentation about them.

bool IMUMotorDriverScheduler::configureHook()
{
    if (! IMUMotorDriverSchedulerBase::configureHook())
        return false;
    return true;
}
bool IMUMotorDriverScheduler::startHook()
{
    if (! IMUMotorDriverSchedulerBase::startHook())
        return false;
    return true;
}
void IMUMotorDriverScheduler::updateHook()
{
    IMUMotorDriverSchedulerBase::updateHook();
}
void IMUMotorDriverScheduler::errorHook()
{
    IMUMotorDriverSchedulerBase::errorHook();
}
void IMUMotorDriverScheduler::stopHook()
{
    IMUMotorDriverSchedulerBase::stopHook();
}
void IMUMotorDriverScheduler::cleanupHook()
{
    IMUMotorDriverSchedulerBase::cleanupHook();
}
