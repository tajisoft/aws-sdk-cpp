﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/pinpoint-sms-voice-v2/PinpointSMSVoiceV2_EXPORTS.h>
#include <aws/core/Region.h>
#include <aws/core/utils/memory/stl/AWSString.h>

namespace Aws
{

namespace PinpointSMSVoiceV2
{
namespace PinpointSMSVoiceV2Endpoint
{
AWS_PINPOINTSMSVOICEV2_API Aws::String ForRegion(const Aws::String& regionName, bool useDualStack = false);
} // namespace PinpointSMSVoiceV2Endpoint
} // namespace PinpointSMSVoiceV2
} // namespace Aws
