#ifndef heads_live_deployments_TYPES_HPP
#define heads_live_deployments_TYPES_HPP

/* If you need to define types specific to your oroGen components, define them
 * here. Required headers must be included explicitly
 *
 * However, it is common that you will only import types from your library, in
 * which case you do not need this file
 */

#include <base/Time.hpp>

namespace heads_live_deployments {
    struct SkippedSync
    {
        base::Time sync_time;
        base::Time received_at;
        base::Time ready_at;
    };
    struct MotorSyncStats
    {
        base::Time time;
        base::Time last_sync;
        base::Time last_output_sample;
        int64_t lost_sync_periods = 0;
        int64_t skipped_sync = 0;
        int8_t received_joints = 0;
    };
}

#endif

