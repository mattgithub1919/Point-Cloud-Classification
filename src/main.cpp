/**
 * @file      main.cpp
 * @brief     Point Cloud Classification
 * @authors   Kushagra Goel, Saket Karve, Disha Jindal
 * @date      2019
 * @copyright University of Pennsylvania
 */

#include <cstdio>
#include <point_cloud_classification/network.h>
#include <point_cloud_classification/common.h>
#include "testing_helpers.hpp"
#include "point_cloud_classification/graph/graph.h"
#include "point_cloud_classification/utilities/matrix.h"
#include "point_cloud_classification/utilities/utils.h"
#include "point_cloud_classification/utilities/parameters.cpp"
#include "point_cloud_classification/hidden_layers/fullyConnectedLayerCPU.cu"

#include "point_cloud_classification/tests/test.h"

#include <fstream>
#include <string>
#include <Windows.h>
#include <vector>
#include <sstream>
#include <iostream>
#include <math.h>

using namespace std;
using namespace PointCloudClassification;

int main(int argc, char* argv[]) {

	// Read data from file and store it as a vector of float pointers (length of vector -> number of samples | each sample -> 1024 x 3 floats)
	
	//vector<float*> samples; //Data from file will be stored here

	// Construct graph for each example and store a vector of L (Laplacians) and AX for each sample
	vector<float*> laplacians;
	vector<float*> transformed_inputs;
	int l1_features = 3;

	/*for (int i = 0; i < PointCloudClassification::num_points; i++) {
		float* current_sample = samples[i];
		Graph::Graph g (current_sample, num_points, l1_features, num_neighbours);

		float* A = g.get_A();
		MatrixCPU* m = new MatrixCPU();
		float* AX = (float*)malloc(num_points * l1_features * sizeof(float));
		m->multiply(A, current_sample, num_points, num_points, l1_features, AX);
		transformed_inputs.push_back(AX);

		float* L = g.get_Lnorm();
		laplacians.push_back(L);
	}*/

	// Tests
	cout << "Testing Matrix Multiplication ..." << endl;
	Tests::testMatrixMultiplication();

	cout << "Testing Fully Connected Layer ..." << endl;
	Tests::testFCLayer();

	cout << "Testing RELU Activation Layer ..." << endl;
	Tests::testRELULayer();

	cout << "Testing Softmax Activation Layer ..." << endl;
	Tests::testSoftmaxLayer();

	cout << "Testing Sigmoid Activation Layer ..." << endl;
	Tests::testSigmoidLayer();

	cout << "Testing Cross Entropy Layer ..." << endl;
	Tests::testCrossEntropyLoss();

	//Build the network
	

	// Train 
	int number_of_batches = ceil(num_points / batch_size);

}
