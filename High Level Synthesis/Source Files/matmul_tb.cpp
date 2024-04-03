#include <stdio.h>
#include <iostream>
#include "matmul.hpp"

int main() {

float input_img[n_inputs] = {140, 80, 1, 100, 1, 0,	0, 0, 12, 0, 0, 4, 2}; // 1
int pred = nn_inference(input_img);
std::cout << std::endl;
std::cout << "NN Prediction: " << pred << std::endl;
std::cout << std::endl;


float input_img1[n_inputs] = {100, 140,	1,	73,	1,	0,	0,	0,	32,	0,	1,	4,	2}; // 3
int pred1 = nn_inference(input_img1);
std::cout << std::endl;
std::cout << "NN Prediction: " << pred1 << std::endl;
std::cout << std::endl;


float input_img2[n_inputs] = {198, 156,	0,	170,	0,	0,	1,	0,	16,	1,	0,	1,	1}; // 4
int pred2 = nn_inference(input_img2);
std::cout << std::endl;
std::cout << "NN Prediction: " << pred2 << std::endl;
std::cout << std::endl;

return 0;
}
