#include <iostream>
#include <vector>

using namespace std;

class ConvLayer {
private:
    int inputChannels;
    int outputChannels;
    int kernelHeight;
    int kernelWidth;
    int stride;
    int padding;
    //Dimanesions:
    //[outputChannels]
    //[inputChannels]
    //[kernelHeight]
    //[kernelWidth]
    vector<vector<vector<vector<float>>>> weights;
    vector<float> biases;

    void initialize_weights() 
    {
        weights.resize(outputChannels, 
                        vector<vector<vector<float>>>(inputChannels, 
                        vector<vector<float>>(kernelHeight, 
                        vector<float>(kernelWidth, 0.0f))));
        biases.resize(outputChannels, 0.0f);
    }

    float apply_kernel(const vector<vector<float>>& input,
                       const vector<vector<float>>& kernel,
                       int start_x, int start_y)
    {
        float sum = 0.0f;
        for (int i = 0; i < kernelHeight; ++i) {
            for (int ii = 0; ii < kernelWidth; ++ii) {
                sum += input[start_y + i][start_x + ii] * kernel[i][ii]; 
            }
        }
        return sum;
    }

public:
    ConvLayer(int inChannels, int outChannels, int kHeight, int kWidth, int s, int p)
    : inputChannels(inChannels), outputChannels(outChannels),
      kernelHeight(kHeight), kernelWidth(kWidth), stride(s), padding(p)
    {
        initialize_weights();
    }

    void setWeights(const vector<vector<vector<vector<float>>>>& new_weights){
        weights = new_weights;
    }

    void setBiases(const vector<float>& new_biases) {
        biases = new_biases;
    }

    vector<vector<vector<float>>> forward(const vector<vector<vector<float>>>& input) {
        int input_height = input[0].size();
        int input_width = input[0][0].size();

        int output_height = (input_height - kernelHeight + 2 * padding) / stride + 1;
        int output_width = (input_width - kernelWidth + 2 * padding) / stride + 1;

        // Apply padding to input
        vector<vector<vector<float>>> padded_input = input;
        if (padding > 0) {
            padded_input = vector<vector<vector<float>>>(inputChannels,
                            vector<vector<float>>(input_height + 2 * padding,
                            vector<float>(input_width + 2 * padding, 0.0f)));
            
        } 
    }


};

int main(){

    return 0;
}