﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/pinpoint-sms-voice-v2/model/SetVoiceMessageSpendLimitOverrideRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::PinpointSMSVoiceV2::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

SetVoiceMessageSpendLimitOverrideRequest::SetVoiceMessageSpendLimitOverrideRequest() : 
    m_monthlyLimit(0),
    m_monthlyLimitHasBeenSet(false)
{
}

Aws::String SetVoiceMessageSpendLimitOverrideRequest::SerializePayload() const
{
  JsonValue payload;

  if(m_monthlyLimitHasBeenSet)
  {
   payload.WithInt64("MonthlyLimit", m_monthlyLimit);

  }

  return payload.View().WriteReadable();
}

Aws::Http::HeaderValueCollection SetVoiceMessageSpendLimitOverrideRequest::GetRequestSpecificHeaders() const
{
  Aws::Http::HeaderValueCollection headers;
  headers.insert(Aws::Http::HeaderValuePair("X-Amz-Target", "PinpointSMSVoiceV2.SetVoiceMessageSpendLimitOverride"));
  return headers;

}




