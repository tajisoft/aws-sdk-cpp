/*
* Copyright 2010-2015 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/
#include <aws/s3/model/Payer.h>
#include <aws/core/utils/HashingUtils.h>

using namespace Aws::Utils;

static const int Requester_HASH = HashingUtils::HashString("Requester");
static const int BucketOwner_HASH = HashingUtils::HashString("BucketOwner");

namespace Aws
{
namespace S3
{
namespace Model
{
namespace PayerMapper
{
Payer GetPayerForName(const Aws::String& name)
{
  int hashCode = HashingUtils::HashString(name.c_str());

  if (hashCode == Requester_HASH)
  {
    return Payer::Requester;
  }
  else if (hashCode == BucketOwner_HASH)
  {
    return Payer::BucketOwner;
  }

  return Payer::Requester;
}

Aws::String GetNameForPayer(Payer value)
{
  switch(value)
  {
  case Payer::Requester:
    return "Requester";
  case Payer::BucketOwner:
    return "BucketOwner";
  default:
    return "Requester";
  }
}

} // namespace PayerMapper
} // namespace Model
} // namespace S3
} // namespace Aws
