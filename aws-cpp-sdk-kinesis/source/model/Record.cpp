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
#include <aws/kinesis/model/Record.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/utils/HashingUtils.h>

#include <utility>

using namespace Aws::Kinesis::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

Record::Record()
{
}

Record::Record(const JsonValue& jsonValue)
{
  *this = jsonValue;
}

Record& Record::operator =(const JsonValue& jsonValue)
{
  m_sequenceNumber = jsonValue.GetString("SequenceNumber");

  m_data = HashingUtils::Base64Decode(jsonValue.GetString("Data"));

  m_partitionKey = jsonValue.GetString("PartitionKey");

  return *this;
}

JsonValue Record::Jsonize() const
{
  JsonValue payload;

  payload.WithString("SequenceNumber", m_sequenceNumber);

  payload.WithString("Data", HashingUtils::Base64Encode(m_data));
  payload.WithString("PartitionKey", m_partitionKey);

  return std::move(payload);
}