// Standard libraries
#ifndef INCLUDE_STL
	#include <cstdlib>
	#include <iostream>
	#include <fstream>
	#include <sstream>
	#include <cmath>
	#include <string>
	#include <vector>
	#include <algorithm>
	#include <thread>
	#include <stdexcept>
	#define INCLUDE_STL
#endif

// External libraries
#ifndef INCLUDE_EIGEN
	#include <Eigen/Dense>
	#define INCLUDE_EIGEN
#endif

class Node {
public:
	// Getters
	virtual double get_u() const;
	// virtual double get_v() const;

	// Setters
	virtual void set_u(const double &_u);
};

class Volume: public Node {
private:
	double u, v, p;

public:
	// Constructors
	Volume(const double &_u, const double &_v, const double &_p);

	// Getters
	double get_u() const;
	// double get_v() const;

	// Setters
	void set_u(const double &_u);
};

class Boundary: public Node {
private:
	const Node *volume;

public:
	// Constructors
	Boundary(const Node *_volume);

	// Getters
	double get_u() const;
	// double get_v() const;
};
