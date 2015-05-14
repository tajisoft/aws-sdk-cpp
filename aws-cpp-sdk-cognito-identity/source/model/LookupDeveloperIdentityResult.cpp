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
#include <aws/cognito-identity/model/LookupDeveloperIdentityResult.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>

#include <utility>

using namespace Aws::CognitoIdentity::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;
using namespace Aws;

LookupDeveloperIdentityResult::LookupDeveloperIdentityResult()
{
}

LookupDeveloperIdentityResult::LookupDeveloperIdentityResult(const AmazonWebServiceResult<JsonValue>& result)
{
  *this = result;
}

LookupDeveloperIdentityResult& LookupDeveloperIdentityResult::operator =(const AmazonWebServiceResult<JsonValue>& result)
{
  const JsonValue& jsonValue = result.GetPayload();
  if(jsonValue.ValueExists("IdentityId"))
  {
    m_identityId = jsonValue.GetString("IdentityId");

  }

  if(jsonValue.ValueExists("DeveloperUserIdentifierList"))
  {
    Array<JsonValue> developerUserIdentifierListJsonList = jsonValue.GetArray("DeveloperUserIdentifierList");
    for(unsigned developerUserIdentifierListIndex = 0; developerUserIdentifierListIndex < developerUserIdentifierListJsonList.GetLength(); ++developerUserIdentifierListIndex)
    {
      m_developerUserIdentifierList.push_back(developerUserIdentifierListJsonList[developerUserIdentifierListIndex].AsString());
    }
  }

  if(jsonValue.ValueExists("NextToken"))
  {
    m_nextToken = jsonValue.GetString("NextToken");

  }



  return *this;
}
