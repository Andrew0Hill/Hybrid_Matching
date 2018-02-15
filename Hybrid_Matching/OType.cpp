#include "OType.h"


OType::OType(int tid)
{
	id = tid;
	a_id = 0;
}

OType::~OType()
{
}

void OType::add_new_obj(FeatureImage feat_image)
{
	// Get current positions of indices for these arrays. 
	// TODO: Messy, clean this up later. boost::unordered_map maybe?
	int desc_ind = descs.size();
	int img_ind = images.size();

	// Create new ObjectInstance with the FeatureImage
	ObjectInstance new_obj = ObjectInstance(alloc_id(), feat_image);

	// Add it to the vector of ObjectInstance
	objects.push_back(new_obj);
	// Add the FeatureImage to the list of FeatureImages for this OType.
	images.push_back(feat_image);
	// Insert descriptors from this FeatureImage into the list for this OType.
	descs.insert(descs.end(), feat_image.descs.begin(), feat_image.descs.end());
	// Do the same for keypoints.
	kps.insert(kps.end(), feat_image.kps.begin(), feat_image.kps.end());

	// Update the descriptor map.
	for (int i = desc_ind; i < descs.size(); ++i) {
		desc_map[i] = img_ind;
	}

	std::cout << "    Added new Object of type: " << category_map[id] << " with ID: " << new_obj.id << std::endl;

}
