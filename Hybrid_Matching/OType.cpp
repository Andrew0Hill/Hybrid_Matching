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

void OType::match(FeatureImage feat_image)
{
	// If this is the first object in the OType, we need to make a new ObjectInstance for the new FeatureImage,
	// since there are no descriptors to match against.
	if (objects.size() == 0) {
		// Allocate a new ID for the new ObjectInstance
		int new_oid = alloc_id();
		// Allocate a new ObjectInstance
		ObjectInstance new_obj = ObjectInstance(new_oid, feat_image);
		// Add the new ObjectInstance to the object list for this OType
		objects.push_back(new_obj);
		// Add the new FeatureImage to the image list for this OType
		images.push_back(feat_image);
		// Since the new ObjectInstance has no other descriptors,
		// set the ObjectInstance's descriptor set to the FeatureImage's
		// descriptor set. 
		descs = feat_image.descs;
		// Do the same for the FeatureImage's keypoint set.
		kps = feat_image.kps;
		// Update the descriptor map so that each descriptor in the array
		// points to the first FeatureImage in the list (this OType's only
		// FeatureImage).
		for (int i = 0; i < descs.size(); ++i){
			desc_map[i] = 0;
		}
		std::cout << "Added a new object of type: " << category_map[id] << " with ID: " << new_obj.id << std::endl;
		return;

	}

	// If this is not an empty OType, then match normally. 
	// Get the 2 nearest neighbors to each feature in the Query Set (feat_image.descs)
	std::vector<std::vector<cv::DMatch>> unfilt_matches;
	// unfilt_matches is passed by reference, and contains two closest matches for each descriptor.
	matcher.knnMatch(feat_image.descs, unfilt_matches, 2);
	// Vector to hold our filtered matches.
	std::vector<cv::DMatch> filt_matches;
	// Filter the matches with NNDR
	for (std::vector<std::vector<cv::DMatch>>::iterator it = unfilt_matches.begin(); it != unfilt_matches.end(); ++it) {
		if (it->at(0).distance < it->at(1).distance * NN_THRESH) {
			filt_matches.push_back(it->at(0));
		}
	}
	
	// Get the indicies into the Query and Training Sets for each match
	std::vector<std::tuple<int, int>> query_train_indices;
	for (std::vector<cv::DMatch>::iterator it = filt_matches.begin(); it != filt_matches.end(); ++it) {
		query_train_indices.push_back({ it->queryIdx, it->trainIdx });
	}

	// Get the Indices
	std::vector<int> match_imgs; 
	for (std::vector<std::tuple<int, int>>::iterator it = query_train_indices.begin(); it != query_train_indices.end(); ++it) {
		match_imgs.push_back(desc_map[std::get<1>(*it)]);
	}







}
