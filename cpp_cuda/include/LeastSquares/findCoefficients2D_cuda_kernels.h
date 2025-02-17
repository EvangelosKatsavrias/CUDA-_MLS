//   CUDA_MLS Framework
//
//   Copyright 2017-2018 Evangelos D. Katsavrias, Luxembourg
//
//   This file is part of the CUDA_MLS Framework.
//
//   CUDA_MLS Framework is free software: you can redistribute it and/or modify
//   it under the terms of the GNU General Public License version 3 as published by
//   the Free Software Foundation.
//
//   CUDA_MLS Framework is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.
//
//   You should have received a copy of the GNU General Public License
//   along with CUDA_MLS Framework.  If not, see <https://www.gnu.org/licenses/>.
//
//   Contact Info:
//   Evangelos D. Katsavrias
//   email/skype: vageng@gmail.com
// -----------------------------------------------------------------------

#include"WeightingFunction.h"
/*
__constant__ int gpu_powers_x[40];
__constant__ int gpu_powers_y[40];

__constant__ double gpu_samplePoints_x[ 1980 ];
__constant__ double gpu_samplePoints_y[ 1980 ];
__constant__ double gpu_sampleValues_x[ 1980 ];
__constant__ double gpu_sampleValues_y[ 1980 ];
*/

template<class T>
__global__
void findCoefficientsLCS2D_cudaKernel_0deg2 ( int* powers_x, int* powers_y, T* stationaryPoints_x, T* stationaryPoints_y, T* samplePoints_x, T* samplePoints_y, T* sampleValues_x, T* sampleValues_y, size_t numOfStoredBlocks, WeightingFunction<T> weightingFunction, T* Sum_bbT, T* Sum_bf);

template<class T>
__global__
void findCoefficientsLCS2D_cudaKernel_0degConstantMemory2 ( T* stationaryPoints_x, T* stationaryPoints_y, size_t numOfStoredBlocks, size_t dataShift, WeightingFunction<T> weightingFunction, T* Sum_bbT, T* Sum_bf);



template<class T>
__global__
void findCoefficientsLCS2D_cudaKernel_0deg ( int* powers_x, int* powers_y, T* stationaryPoints_x, T* stationaryPoints_y, size_t numOfSamplePoints, T* samplePoints_x, T* samplePoints_y, T* sampleValues_x, T* sampleValues_y, WeightingFunction<T> weightingFunction, T* Sum_bbT, T* Sum_bfx, T* Sum_bfy);


template<class T>
__global__
void findCoefficientsLCS2D_cudaKernel2 ( int* powers_x, int* powers_y, T* stationaryPoints_x, T* stationaryPoints_y, T* samplePoints_x, T* samplePoints_y, T* sampleValues_x, T* sampleValues_y, size_t numOfStoredBlocks, WeightingFunction<T> weightingFunction, T* Sum_bbT, T* Sum_bf);

template<class T>
__global__
void findCoefficientsLCS2D_cudaKernelConstantMemory2 ( T* stationaryPoints_x, T* stationaryPoints_y, size_t numOfStoredBlocks, size_t dataShift, WeightingFunction<T> weightingFunction, T* Sum_bbT, T* Sum_bf);


template<class T>
__global__
void findCoefficientsLCS2D_cudaKernel ( int* powers_x, int* powers_y, T* stationaryPoints_x, T* stationaryPoints_y, size_t numOfSamplePoints, T* samplePoints_x, T* samplePoints_y, T* sampleValues_x, T* sampleValues_y, WeightingFunction<T> weightingFunction, T* Sum_bbT, T* Sum_bfx, T* Sum_bfy);


template<class T>
__global__
void findCoefficientsLCS2D_cudaKernel3 ( int* powers_x, int* powers_y, T* stationaryPoints_x, T* stationaryPoints_y, size_t numOfSamplePoints, T* samplePoints_x, T* samplePoints_y, T* sampleValues_x, T* sampleValues_y, WeightingFunction<T> weightingFunction, T* Sum_bbT, T* Sum_bfx, T* Sum_bfy);


template<class T>
__global__
void find_bTheta_LCS2D_cudaKernel ( int* powers_x, int* powers_y, T* stationaryPoints_x, T* stationaryPoints_y, size_t numOfSamplePoints, T* samplePoints_x, T* samplePoints_y, WeightingFunction<T> weightingFunction, T* bTheta, T* b_out);


template<class T>
__global__
void find_bTheta_bf_LCS2D_cudaKernel ( int* powers_x, int* powers_y, T* stationaryPoints_x, T* stationaryPoints_y, size_t numOfMonomials, size_t numOfSamplePoints, T* samplePoints_x, T* samplePoints_y, T* sampleValues_x, T* sampleValues_y, WeightingFunction<T> weightingFunction, T* bTheta, T* b_out, T* bfx_out, T* bfy_out);


template<class T>
__global__
void find_bTheta_bf_LCS2D_cudaKernel2 ( int* powers_x, int* powers_y, T* stationaryPoints_x, T* stationaryPoints_y, size_t numOfMonomials, size_t numOfSamplePoints, T* samplePoints_x, T* samplePoints_y, T* sampleValues_x, T* sampleValues_y, WeightingFunction<T> weightingFunction, T* bTheta, T* b_out, T* bfx_out, T* bfy_out);


template<class T, int tileWidth = 16>
__global__
void find_bbT_LCS2D_cudaKernel ( size_t numOfSamplePoints, size_t numOfMonomials, T* bTheta, T* b, T* bbT );


template<class T>
__global__
void find_bf_LCS2D_cudaKernel ( size_t numOfSamplePoints, T* sampleValues_x, T* sampleValues_y, size_t numOfMonomials, T* b, T* bfx_out, T* bfy_out );


template<class T>
__global__
void find_bf_LCS2D_cudaKernel2 ( size_t numOfSamplePoints, T* sampleValues_x, T* sampleValues_y, size_t numOfMonomials, T* b, T* bfx_out, T* bfy_out );



