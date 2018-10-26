/* Generated from orogen/lib/orogen/templates/tasks/Task.cpp */

#include "MotorDriverScheduler.hpp"
#include <base-logging/Logging.hpp>

using namespace heads_live_deployments;

MotorDriverScheduler::MotorDriverScheduler(std::string const& name, TaskCore::TaskState initial_state)
    : MotorDriverSchedulerBase(name, initial_state)
{
}

MotorDriverScheduler::MotorDriverScheduler(std::string const& name, RTT::ExecutionEngine* engine, TaskCore::TaskState initial_state)
    : MotorDriverSchedulerBase(name, engine, initial_state)
{
}

MotorDriverScheduler::~MotorDriverScheduler()
{
}



/// The following lines are template definitions for the various state machine
// hooks defined by Orocos::RTT. See MotorDriverScheduler.hpp for more detailed
// documentation about them.

bool MotorDriverScheduler::configureHook()
{
    if (! MotorDriverSchedulerBase::configureHook())
        return false;

    mJointsSample.resize(1);
    mExportedJoints.resize(3);
    return true;
}
bool MotorDriverScheduler::startHook()
{
    if (! MotorDriverSchedulerBase::startHook())
        return false;

    yaw_r_task   = getPeer("yaw_motor_r");
    pitch_r_task = getPeer("pitch_motor_r");
    roll_r_task  = getPeer("roll_motor_r");

    if (!yaw_r_task)
    {
        LOG_ERROR_S << "No yaw_motor_r peer" << std::endl;
        return false;
    }
    if (!pitch_r_task)
    {
        LOG_ERROR_S << "No pitch_motor_r peer" << std::endl;
        return false;
    }
    if (!roll_r_task)
    {
        LOG_ERROR_S << "No roll_motor_r peer" << std::endl;
        return false;
    }

    mReceivedJoints = RECEIVED_NONE;
    mPreviousSync = mLastSync = base::Time();
    return true;
}

bool MotorDriverScheduler::updateJoint(
    RTT::InputPort<base::samples::Joints>& port,
    base::JointState& joint,
    base::Time syncTime)
{
    if (!port.connected())
    {
        joint = base::JointState();
        return true;
    }
    while (port.read(mJointsSample, false) == RTT::NewData)
    {
        if (mJointsSample.time > syncTime)
        {
            joint = mJointsSample.elements[0];
            return true;
        }
    }
    return false;
}
void MotorDriverScheduler::updateHook()
{
    MotorDriverSchedulerBase::updateHook();

    yaw_r_task->update();
    pitch_r_task->update();
    roll_r_task->update();

    canbus::Message can_msg;

    // We ever only consider the latest message
    if (_sync_messages.read(can_msg) == RTT::NewData)
    {
        mPreviousSync = mLastSync;
        mLastSync = can_msg.time;
        mReceivedJoints = RECEIVED_NONE;
        if (!_yaw_joint.connected())
            mReceivedJoints |= RECEIVED_YAW;
        if (!_pitch_joint.connected())
            mReceivedJoints |= RECEIVED_PITCH;
        if (!_roll_joint.connected())
            mReceivedJoints |= RECEIVED_ROLL;
    }

    if (mPreviousSync.isNull())
        return;

    if (!(mReceivedJoints & RECEIVED_YAW))
    {
        if (updateJoint(_yaw_joint, mYawSample, mLastSync))
            mReceivedJoints |= RECEIVED_YAW;
    }

    if (!(mReceivedJoints & RECEIVED_PITCH))
    {
        if (updateJoint(_pitch_joint, mPitchSample, mLastSync))
            mReceivedJoints |= RECEIVED_PITCH;
    }

    if (!(mReceivedJoints & RECEIVED_ROLL))
    {
        if (updateJoint(_roll_joint, mRollSample, mLastSync))
            mReceivedJoints |= RECEIVED_ROLL;
    }

    if (mReceivedJoints == RECEIVED_ALL)
    {
        mReceivedJoints = RECEIVED_NONE;
        outputJointState();
    }
}

void MotorDriverScheduler::outputJointState()
{
    mExportedJoints.time = mPreviousSync;
    mExportedJoints.elements[0] = mYawSample;
    mExportedJoints.elements[1] = mPitchSample;
    mExportedJoints.elements[2] = mRollSample;
    _joint_samples.write(mExportedJoints);
}

void MotorDriverScheduler::errorHook()
{
    MotorDriverSchedulerBase::errorHook();
}
void MotorDriverScheduler::stopHook()
{
    MotorDriverSchedulerBase::stopHook();
}
void MotorDriverScheduler::cleanupHook()
{
    MotorDriverSchedulerBase::cleanupHook();
}
