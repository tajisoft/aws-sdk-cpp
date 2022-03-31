﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/pinpoint-sms-voice-v2/model/ReleasePhoneNumberRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::PinpointSMSVoiceV2::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

ReleasePhoneNumberRequest::ReleasePhoneNumberRequest() : 
    m_phoneNumberIdHasBeenSet(false)
{
}

Aws::String ReleasePhoneNumberRequest::SerializePayload() const
{
  JsonValue payload;

  if(m_phoneNumberIdHasBeenSet)
  {
   payload.WithString("PhoneNumberId", m_phoneNumberId);

  }

  return payload.View().WriteReadable();
}

Aws::Http::HeaderValueCollection ReleasePhoneNumberRequest::GetRequestSpecificHeaders() const
{
  Aws::Http::HeaderValueCollection headers;
  headers.insert(Aws::Http::HeaderValuePair("X-Amz-Target", "PinpointSMSVoiceV2.ReleasePhoneNumber"));
  return headers;

}




