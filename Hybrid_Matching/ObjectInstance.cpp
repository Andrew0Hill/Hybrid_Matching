#include "ObjectInstance.h"


ObjectInstance::ObjectInstance(int oid, FeatureImage feat_image)
{
	feat_image.parent = this;
}

ObjectInstance::~ObjectInstance()
{
}
