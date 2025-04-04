/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include "Navigation2D_nwc_yarp.h"
#include <yarp/dev/INavigation2D.h>
#include <yarp/os/Log.h>
#include <yarp/os/LogComponent.h>
#include <yarp/os/LogStream.h>
#include <mutex>
#include <cmath>

 /*! \file Navigation2D_nwc_yarp_iLocalization2D.cpp */

using namespace yarp::dev;
using namespace yarp::dev::Nav2D;
using namespace yarp::os;
using namespace yarp::sig;

namespace {
    YARP_LOG_COMPONENT(NAVIGATION2D_NWC, "yarp.device.navigation2D_nwc_yarp")
}

//------------------------------------------------------------------------------------------------------------------------------

ReturnValue  Navigation2D_nwc_yarp::setInitialPose(const Map2DLocation& loc)
{
    std::lock_guard <std::mutex> lg(m_mutex);
    return m_loc_RPC.set_initial_pose1_RPC(loc);
}

ReturnValue Navigation2D_nwc_yarp::setInitialPose(const Map2DLocation& loc, const yarp::sig::Matrix& cov)
{
    if (cov.rows() != 3 || cov.cols() != 3)
    {
        yCError(NAVIGATION2D_NWC) << "Covariance matrix is expected to have size (3,3)";
        return ReturnValue::return_code::return_value_error_method_failed;
    }

    std::lock_guard <std::mutex> lg(m_mutex);
    return m_loc_RPC.set_initial_pose2_RPC(loc, cov);
}

ReturnValue  Navigation2D_nwc_yarp::getCurrentPosition(Map2DLocation& loc, yarp::sig::Matrix& cov)
{
    std::lock_guard <std::mutex> lg(m_mutex);
    auto ret = m_loc_RPC.get_current_position2_RPC();
    if (!ret.ret)
    {
        yCError(NAVIGATION2D_NWC, "Unable to get_current_position2_RPC");
        return ret.ret;
    }
    loc = ret.loc;
    cov = ret.cov;
    return ret.ret;
}

ReturnValue  Navigation2D_nwc_yarp::getEstimatedOdometry(yarp::dev::OdometryData& odom)
{
    std::lock_guard <std::mutex> lg(m_mutex);
    auto ret = m_loc_RPC.get_estimated_odometry_RPC();
    if (!ret.ret)
    {
        yCError(NAVIGATION2D_NWC, "Unable to get_estimated_odometry_RPC");
        return ret.ret;
    }
    odom = ret.odom;
    return ret.ret;
}

ReturnValue  Navigation2D_nwc_yarp::getCurrentPosition(Map2DLocation& loc)
{
    std::lock_guard <std::mutex> lg(m_mutex);
    auto ret = m_loc_RPC.get_current_position1_RPC();
    if (!ret.ret)
    {
        yCError(NAVIGATION2D_NWC, "Unable to get_current_position1_RPC");
        return ret.ret;
    }
    loc = ret.loc;
    return ret.ret;
}

ReturnValue  Navigation2D_nwc_yarp::getLocalizationStatus(yarp::dev::Nav2D::LocalizationStatusEnum& status)
{
    std::lock_guard <std::mutex> lg(m_mutex);
    auto ret = m_loc_RPC.get_localization_status_RPC();
    if (!ret.ret)
    {
        yCError(NAVIGATION2D_NWC, "Unable to get_localization_status_RPC");
        return ret.ret;
    }
    status = yarp::dev::Nav2D::LocalizationStatusEnum(ret.status);
    return ret.ret;
}

ReturnValue  Navigation2D_nwc_yarp::getEstimatedPoses(std::vector<Map2DLocation>& poses)
{
    std::lock_guard <std::mutex> lg(m_mutex);
    auto ret = m_loc_RPC.get_estimated_poses_RPC();
    if (!ret.ret)
    {
        yCError(NAVIGATION2D_NWC, "Unable to get_estimated_poses_RPC");
        return ret.ret;
    }
    poses = ret.poses;
    return ret.ret;
}

ReturnValue  Navigation2D_nwc_yarp::startLocalizationService()
{
    std::lock_guard <std::mutex> lg(m_mutex);
    return m_loc_RPC.start_localization_service_RPC();
}

ReturnValue  Navigation2D_nwc_yarp::stopLocalizationService()
{
    std::lock_guard <std::mutex> lg(m_mutex);
    return m_loc_RPC.stop_localization_service_RPC();
}
