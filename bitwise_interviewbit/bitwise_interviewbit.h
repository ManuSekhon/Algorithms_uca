/**
 * Solutions to interviewbit problems of bitwise programming section
 */

#ifndef BITWISE_INTERVIEWBIT_H
#define BITWISE_INTERVIEWBIT_H

/**
 * Given an array of N integers, find the pair of integers in the array 
 * which have minimum XOR value. Report the minimum XOR value.
 */
int findMinXor (int *array, int size);

/** 
 * Write a function that takes an unsigned integer and returns the number
 * of 1 bits it has.
 */
int numSetBits (unsigned int A);

/**
 * Reverse bits of an 32 bit unsigned integer
 */
unsigned int reverse (unsigned int A);

/**
 * Divide two integers without using multiplication, division and mod 
 * operator. Return the floor of the result of the division.
 */
int divide (int dividend, int divisor);

/**
 * Given an array of integers, every element appears twice except for one.
 * Find that single one.
 */
int singleNumber (const int *array, int size);

/**
 * You are given an array of N positive integers, A1, A2 ,…, AN. Find sum 
 * of f(Ai, Aj) for all pairs (i, j) such that 1 ≤ i, j ≤ N. Return the 
 * answer modulo 109+7.
 */
int cntBits (int *A, int size);

#endif