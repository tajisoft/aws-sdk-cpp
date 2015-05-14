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
#include <aws/s3/model/LifecycleConfiguration.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

#include <utility>

using namespace Aws::S3::Model;
using namespace Aws::Utils::Xml;
using namespace Aws::Utils;

LifecycleConfiguration::LifecycleConfiguration()
{
}

LifecycleConfiguration::LifecycleConfiguration(const XmlNode& xmlNode)
{
  *this = xmlNode;
}

LifecycleConfiguration& LifecycleConfiguration::operator =(const XmlNode& xmlNode)
{
  XmlNode resultNode = xmlNode;

  if(!resultNode.IsNull())
  {
    XmlNode ruleNode = resultNode.FirstChild("Rule");
    while(!ruleNode.IsNull())
    {
      m_rules.push_back(ruleNode);
      ruleNode = ruleNode.NextNode("Rule");
    }

  }

  return *this;
}

void LifecycleConfiguration::AddToNode(XmlNode& parentNode) const
{
  Aws::StringStream ss;
  for(const auto& item : m_rules)
  {
    XmlNode rulesNode = parentNode.CreateChildElement("Rule");
    item.AddToNode(rulesNode);
  }
}
