/* Generated from orogen/lib/orogen/templates/tasks/Task.cpp */

#include "SyncMotorDriverScheduler.hpp"
#include <base-logging/Logging.hpp>

using namespace heads_live_deployments;

SyncMotorDriverScheduler::SyncMotorDriverScheduler(std::string const& name, TaskCore::TaskState initial_state)
    : SyncMotorDriverSchedulerBase(name, initial_state)
{
}

SyncMotorDriverScheduler::SyncMotorDriverScheduler(std::string const& name, RTT::ExecutionEngine* engine, TaskCore::TaskState initial_state)
    : SyncMotorDriverSchedulerBase(name, engine, initial_state)
{
}

SyncMotorDriverScheduler::~SyncMotorDriverScheduler()
{
}



/// The following lines are template definitions for the various state machine
// hooks defined by Orocos::RTT. See SyncMotorDriverScheduler.hpp for more detailed
// documentation about them.

bool SyncMotorDriverScheduler::configureHook()
{
    if (! SyncMotorDriverSchedulerBase::configureHook())
        return false;

    return true;
}
bool SyncMotorDriverScheduler::startHook()
{
    if (! SyncMotorDriverSchedulerBase::startHook())
        return false;
    return true;
}
void SyncMotorDriverScheduler::updateHook()
{
    SyncMotorDriverSchedulerBase::updateHook();
}
void SyncMotorDriverScheduler::errorHook()
{
    SyncMotorDriverSchedulerBase::errorHook();
}
void SyncMotorDriverScheduler::stopHook()
{
    SyncMotorDriverSchedulerBase::stopHook();
}
void SyncMotorDriverScheduler::cleanupHook()
{
    SyncMotorDriverSchedulerBase::cleanupHook();
}
