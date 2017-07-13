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

// My libraries
#ifndef INCLUDE_VOLUME
	#include "volume.hpp"
	#define INCLUDE_VOLUME
#endif

const unsigned int N = 3;

int main(int argc, char** argv) {
	Eigen::MatrixXd u = Eigen::MatrixXd::Random(N, N);
	std::cout << u << std::endl;

	Eigen::MatrixXd v = Eigen::MatrixXd::Random(N, N);
	// std::cout << v << std::endl;

	Eigen::MatrixXd p = Eigen::MatrixXd::Random(N, N);
	// std::cout << p << std::endl;

	Eigen::Matrix<Node*, N+2, N+2> volumes;

	// Inner volumes
	for (unsigned int i = 1; i < N+1; i++) {		
		for (unsigned int j = 1; j < N+1; j++) {
			volumes(j, i) = new Volume(u(j-1, i-1), v(j-1, i-1), p(j-1, i-1));
		}
	}

	// Boundary volumes
	for (unsigned int i = 1; i < N+1; i++) {
		volumes(0, i) = new Boundary(volumes(N, i));
		volumes(i, 0) = new Boundary(volumes(i, N));
		volumes(N+1, i) = new Boundary(volumes(1, i));
		volumes(i, N+1) = new Boundary(volumes(i, 1));
	}

	// Corner volumes
	volumes(0, 0) = new Node();
	volumes(N+1, 0) = new Node();
	volumes(0, N+1) = new Node();
	volumes(N+1, N+1) = new Node();

	/* Test */

	for (unsigned int i = 0; i < N+2; i++) {
		for (unsigned int j = 0; j < N+2; j++) {
			std::cout << volumes(j, i)->get_u() << std::endl;
		}
		std::cout << std::endl;
	}

	std::cout << "SET U" << std::endl;
	volumes(1, 1)->set_u(100.0);

	for (unsigned int i = 0; i < N+2; i++) {
		for (unsigned int j = 0; j < N+2; j++) {
			std::cout << volumes(j, i)->get_u() << std::endl;
		}
		std::cout << std::endl;
	}

	return 0;
}
