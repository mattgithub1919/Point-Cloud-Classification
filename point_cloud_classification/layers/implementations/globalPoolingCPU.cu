#include "common.h"
#include "../../utilities/kernels.h"
#include "../layer.h"
#include "../globalPoolingLayer.h"
#include <fstream>
#include <string>

#ifndef imax
#define imax(a,b) (((a)>(b))?(a):(b))
#endif

#define blockSize 128

namespace PointCloudClassification {
    using Common::PerformanceTimer;
    PerformanceTimer& timer()
    {
        static PerformanceTimer timer;
        return timer;
    }

	void genArray(int n, float *a) {
		srand(11);

		for (int i = 0; i < n; i++) {
			a[i] = ((2 *((rand() * 1.0 )/ RAND_MAX)) - 1) * 0.0002;
		}
	}

	class GlobalPoolingLayerCPU : public GlobalPoolingLayer {
		GlobalPoolingLayerCPU() {};

	public: 
		GlobalPoolingLayerCPU(int inputDim, int outputDim, int batchDim, bool lastLayer) {
			GlobalPoolingLayer(inputDim, outputDim, batchDim, lastLayer);
		}

		/*
			inputArg -> N x D (N - number of points per sample)
			outputArg -> 1 x D
			Takes maximum across all points
		*/
		void forward(float *inputArg, float *outputArg, bool test) {

		}

		void backward(float *incomingGradient, float *outgoingGradient, float learningRate) {


		}
	};
}
