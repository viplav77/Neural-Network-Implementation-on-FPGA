#include "matmul.hpp"

/* Layer 1 matrix multiplication */
void hwmm_layer1(float input[n_inputs], const float weights[n_inputs][n_layer1], float output[1][n_layer1]) {
    for (int j = 0; j < n_layer1; ++j) {
        float sum = 0;
        for (int k = 0; k < n_inputs; ++k){
            sum += input[k] * weights[k][j];
        }
        output[0][j] = sum;
    }
}

/* Layer 2 matrix multiplication */
void hwmm_layer2(float input[1][n_layer1], const float weights[n_layer1][n_layer2], float output[1][n_layer2]) {
    for (int j = 0; j < n_layer2; ++j) {
        float sum = 0;
        for (int k = 0; k < n_layer1; ++k){
            sum += input[0][k] * weights[k][j];
        }
        output[0][j] = sum;
    }
}

/* Layer 3 matrix multiplication */
void hwmm_layer3(float input[1][n_layer2], const float weights[n_layer2][n_layer3], float output[1][n_layer3]) {
    for (int j = 0; j < n_layer3; ++j) {
        float sum = 0;
        for (int k = 0; k < n_layer2; ++k){
            sum += input[0][k] * weights[k][j];
        }
        output[0][j] = sum;
    }
}

/* ReLU layer 1 activation function */
void hw_act_layer1(float input[1][n_layer1], float output[1][n_layer1]){
    for (int i = 0; i < n_layer1; i++){
        if (input[0][i] < 0.0)
            output[0][i] = 0.0;
        else
            output[0][i] = input[0][i];
    }
}

/* ReLU layer 2 activation function */
void hw_act_layer2(float input[1][n_layer2], float output[1][n_layer2]){
    for (int i = 0; i < n_layer2; i++){
        if (input[0][i] < 0.0)
            output[0][i] = 0.0;
        else
            output[0][i] = input[0][i];
    }
}

/* Softmax layer 3 activation function */
void hw_act_layer3(float input[1][n_layer3], int &pred){
    int max_idx = -1;
    float max_val = -999.9;
    for (int i = 0; i < n_layer3; i++){
        if (input[0][i] > max_val){
            max_idx = i;
            max_val = input[0][i];
        }
    }
    pred = max_idx;
}

/* Connect NN Layers */
int nn_inference(float input_img[n_inputs]){
    float temp_output[1][n_layer1] = {1};
    float temp_output2[1][n_layer2] = {1};
    float temp_output3[1][n_layer3] = {1};
    int prediction = -1;

    hwmm_layer1(input_img, weights::layer1_weights, temp_output);
    hw_act_layer1(temp_output, temp_output);
    hwmm_layer2(temp_output, weights::layer2_weights, temp_output2);
    hw_act_layer2(temp_output2, temp_output2);
    hwmm_layer3(temp_output2, weights::layer3_weights, temp_output3);
    hw_act_layer3(temp_output3, prediction);

    return prediction;
}
