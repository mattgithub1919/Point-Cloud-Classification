set(SOURCE_FILES
	"layer.h"
	"loss.h"
	"fullyConnectedLayer.h"
	"graphConvolutionLayer.h"
	"globalPoolingLayer.h"
	"RELUActivationLayer.h"
	"sigmoidActivationLayer.h"
	"softmaxActivationLayer.h"
	"crossEntropyLoss.h"
	"dropoutLayer.h"
        "fullyConnectedLayerCPU.cu"
	"fullyConnectedLayerGPU.cu"
	"globalPoolingCPU.cu"
	"globalPoolingGPU.cu"
	"graphConvolutionLayerCPU.cu"
	"graphConvolutionLayerGPU.cu"
	"RELUActivationLayerCPU.cu"
	"sigmoidActivationLayerCPU.cu"
	"softmaxActivationLayerCPU.cu"
	"RELUActivationLayerGPU.cu"
	"sigmoidActivationLayerGPU.cu"
	"softmaxActivationLayerGPU.cu"
	"crossEntropyLossCPU.cu"
	"crossEntropyLossGPU.cu"
	"dropoutLayerCPU.cu"
	"dropoutLayerGPU.cu"
)

cuda_add_library(hidden_layers
    ${SOURCE_FILES}
    OPTIONS -arch=sm_61
    )
