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
#include <aws/s3/model/ObjectIdentifier.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

#include <utility>

using namespace Aws::S3::Model;
using namespace Aws::Utils::Xml;
using namespace Aws::Utils;

ObjectIdentifier::ObjectIdentifier() : 
    m_versionIdHasBeenSet(false)
{
}

ObjectIdentifier::ObjectIdentifier(const XmlNode& xmlNode) : 
    m_versionIdHasBeenSet(false)
{
  *this = xmlNode;
}

ObjectIdentifier& ObjectIdentifier::operator =(const XmlNode& xmlNode)
{
  XmlNode resultNode = xmlNode;

  if(!resultNode.IsNull())
  {
    XmlNode keyNode = resultNode.FirstChild("Key");
    m_key = StringUtils::Trim(keyNode.GetText().c_str());
    XmlNode versionIdNode = resultNode.FirstChild("VersionId");
    if(!versionIdNode.IsNull())
    {
      m_versionId = StringUtils::Trim(versionIdNode.GetText().c_str());
      m_versionIdHasBeenSet = true;
    }
  }

  return *this;
}

void ObjectIdentifier::AddToNode(XmlNode& parentNode) const
{
  Aws::StringStream ss;
  XmlNode keyNode = parentNode.CreateChildElement("Key");
  keyNode.SetText(m_key);
  if(m_versionIdHasBeenSet)
  {
   XmlNode versionIdNode = parentNode.CreateChildElement("VersionId");
   versionIdNode.SetText(m_versionId);
  }

}
