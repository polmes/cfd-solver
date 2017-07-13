// My libraries
#include "volume.hpp"

// Node::Node() {}

Volume::Volume(const double &_u, const double &_v, const double &_p): u(_u), v(_v), p(_p) {}

Boundary::Boundary(const Node *_volume): volume(_volume) {}

double Node::get_u() const {
	return 0;
}

double Volume::get_u() const {
	return this->u;
}

double Boundary::get_u() const {
	return this->volume->get_u();
}

void Node::set_u(const double &_u) {}

void Volume::set_u(const double &_u) {
	this->u = _u;
}
