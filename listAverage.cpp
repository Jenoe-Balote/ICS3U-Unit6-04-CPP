// Copyright (c) Jenoe Balote All rights reserved
//
// Created by: Jenoe Balote
// Created on: June 2021
// This program determines the average of a 2D list

#include <iostream>
#include <random>


template<int row, int column>
float CalculateAverage(float (&array)[row][column]) {
    // This function calculates the average

    int total = 0;
    float average = 0;

    for (int rowCounter = 0; rowCounter < row; rowCounter++) {
        for (
            int columnCounter = 0; columnCounter < column; columnCounter++
        ) {
            total += array[rowCounter][columnCounter];
        }
        average = total / (row * column);
    }
    return average;
}


main() {
    // this function generates the random numbers for the 2d array

    int randomNumber = 0;
    int total = 0;
    const int rows = 5;
    const int columns = 5;
    float array[rows][columns];
    float average;

    // intro
    std::cout << "Let's average out some lists!" << std::endl;
    std::cout << "\nGenerating numbers..." << std::endl;
    std::cout << "" << std::endl;

    // process and output
    for (int rowCounter = 0; rowCounter < rows; rowCounter++) {
        for (int columnCounter = 0; columnCounter < columns; columnCounter++) {
            std::random_device rseed;
            std::mt19937 rgen(rseed());  // mersenne_twister
            std::uniform_int_distribution<int> idist(1, 50);
            randomNumber = idist(rgen);
            array[rowCounter][columnCounter] = randomNumber;
            std::cout << randomNumber << " ";
        }
        std::cout << "\n";
    }
    // call function(s)
    average = CalculateAverage(array);
    std::cout << "\nThe average is around " << average << std::endl;
    std::cout << "\nThanks for participating!" << std::endl;
}
