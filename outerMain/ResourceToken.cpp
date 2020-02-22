#include "Random.h"
#include "ResourceToken.h"

ResourceToken::ResourceToken() : ResourceToken(randomType()) {}

ResourceToken::ResourceType ResourceToken::randomType() {
	return static_cast<ResourceToken::ResourceType>(Random::next(0, 3)); // TODO can bound be obtained programmatically?
}

ResourceToken::ResourceToken(ResourceType type) {
	this->type = new ResourceType(type);
}

ResourceToken::ResourceToken(ResourceToken& other) {
	type = new ResourceType(*other.type);
}

ResourceToken::~ResourceToken() {
	delete type;
}

int ResourceToken::getType() const {
	return static_cast<int>(*type);
}

void ResourceToken::display() const {
	// TODO
}