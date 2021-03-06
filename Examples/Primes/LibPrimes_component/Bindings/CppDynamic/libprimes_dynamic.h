/*++

Copyright (C) 2018 Automatic Component Toolkit Developers

All rights reserved.

This file has been generated by the Automatic Component Toolkit (ACT) version 1.3.1.

Abstract: This is an autogenerated plain C Header file in order to allow an easy
 use of Prime Numbers Interface

Interface version: 1.3.0

*/

#ifndef __LIBPRIMES_DYNAMICHEADER
#define __LIBPRIMES_DYNAMICHEADER

#include "libprimes_types.h"


/*************************************************************************************************************************
 Class definition for Calculator
**************************************************************************************************************************/

/**
* Returns the current value of this Calculator
*
* @param[in] pCalculator - Calculator instance.
* @param[out] pValue - The current value of this Calculator
* @return error code or 0 (success)
*/
typedef LibPrimesResult (*PLibPrimesCalculator_GetValuePtr) (LibPrimes_Calculator pCalculator, LibPrimes_uint64 * pValue);

/**
* Sets the value to be factorized
*
* @param[in] pCalculator - Calculator instance.
* @param[in] nValue - The value to be factorized
* @return error code or 0 (success)
*/
typedef LibPrimesResult (*PLibPrimesCalculator_SetValuePtr) (LibPrimes_Calculator pCalculator, LibPrimes_uint64 nValue);

/**
* Sets the progress callback function
*
* @param[in] pCalculator - Calculator instance.
* @param[in] pProgressCallback - The progress callback
* @return error code or 0 (success)
*/
typedef LibPrimesResult (*PLibPrimesCalculator_SetProgressCallbackPtr) (LibPrimes_Calculator pCalculator, LibPrimesProgressCallback pProgressCallback);

/**
* Performs the specific calculation of this Calculator
*
* @param[in] pCalculator - Calculator instance.
* @return error code or 0 (success)
*/
typedef LibPrimesResult (*PLibPrimesCalculator_CalculatePtr) (LibPrimes_Calculator pCalculator);

/*************************************************************************************************************************
 Class definition for FactorizationCalculator
**************************************************************************************************************************/

/**
* Returns the prime factors of this number (with multiplicity)
*
* @param[in] pFactorizationCalculator - FactorizationCalculator instance.
* @param[in] nPrimeFactorsBufferSize - Number of elements in buffer
* @param[out] pPrimeFactorsNeededCount - will be filled with the count of the written elements, or needed buffer size.
* @param[out] pPrimeFactorsBuffer - PrimeFactor buffer of The prime factors of this number
* @return error code or 0 (success)
*/
typedef LibPrimesResult (*PLibPrimesFactorizationCalculator_GetPrimeFactorsPtr) (LibPrimes_FactorizationCalculator pFactorizationCalculator, const LibPrimes_uint64 nPrimeFactorsBufferSize, LibPrimes_uint64* pPrimeFactorsNeededCount, sLibPrimesPrimeFactor * pPrimeFactorsBuffer);

/**
* Checks, whether a list of prime factors (with multiplicity) is the prime factor decomposistion of the calculator's value
*
* @param[in] pFactorizationCalculator - FactorizationCalculator instance.
* @param[in] nPrimeFactorsBufferSize - Number of elements in buffer
* @param[in] pPrimeFactorsBuffer - PrimeFactor buffer of 
* @param[out] pAreEqual - Do the prime factors decompose this calculator's value
* @return error code or 0 (success)
*/
typedef LibPrimesResult (*PLibPrimesFactorizationCalculator_CheckPrimeFactorsPtr) (LibPrimes_FactorizationCalculator pFactorizationCalculator, LibPrimes_uint64 nPrimeFactorsBufferSize, const sLibPrimesPrimeFactor * pPrimeFactorsBuffer, bool * pAreEqual);

/*************************************************************************************************************************
 Class definition for SieveCalculator
**************************************************************************************************************************/

/**
* Returns all prime numbers lower or equal to the sieve's value
*
* @param[in] pSieveCalculator - SieveCalculator instance.
* @param[in] nPrimesBufferSize - Number of elements in buffer
* @param[out] pPrimesNeededCount - will be filled with the count of the written elements, or needed buffer size.
* @param[out] pPrimesBuffer - uint64 buffer of The primes lower or equal to the sieve's value
* @return error code or 0 (success)
*/
typedef LibPrimesResult (*PLibPrimesSieveCalculator_GetPrimesPtr) (LibPrimes_SieveCalculator pSieveCalculator, const LibPrimes_uint64 nPrimesBufferSize, LibPrimes_uint64* pPrimesNeededCount, LibPrimes_uint64 * pPrimesBuffer);

/*************************************************************************************************************************
 Global functions
**************************************************************************************************************************/

/**
* Creates a new FactorizationCalculator instance
*
* @param[out] pInstance - New FactorizationCalculator instance
* @return error code or 0 (success)
*/
typedef LibPrimesResult (*PLibPrimesCreateFactorizationCalculatorPtr) (LibPrimes_FactorizationCalculator * pInstance);

/**
* Creates a new SieveCalculator instance
*
* @param[out] pInstance - New SieveCalculator instance
* @return error code or 0 (success)
*/
typedef LibPrimesResult (*PLibPrimesCreateSieveCalculatorPtr) (LibPrimes_SieveCalculator * pInstance);

/**
* Releases the memory of an Instance
*
* @param[in] pInstance - Instance Handle
* @return error code or 0 (success)
*/
typedef LibPrimesResult (*PLibPrimesReleaseInstancePtr) (LibPrimes_BaseClass pInstance);

/**
* retrieves the current version of the library.
*
* @param[out] pMajor - returns the major version of the library
* @param[out] pMinor - returns the minor version of the library
* @param[out] pMicro - returns the micro version of the library
* @return error code or 0 (success)
*/
typedef LibPrimesResult (*PLibPrimesGetLibraryVersionPtr) (LibPrimes_uint32 * pMajor, LibPrimes_uint32 * pMinor, LibPrimes_uint32 * pMicro);

/**
* Handles Library Journaling
*
* @param[in] pFileName - Journal FileName
* @return error code or 0 (success)
*/
typedef LibPrimesResult (*PLibPrimesSetJournalPtr) (const char * pFileName);

/*************************************************************************************************************************
 Function Table Structure
**************************************************************************************************************************/

typedef struct {
	void * m_LibraryHandle;
	PLibPrimesCalculator_GetValuePtr m_Calculator_GetValue;
	PLibPrimesCalculator_SetValuePtr m_Calculator_SetValue;
	PLibPrimesCalculator_SetProgressCallbackPtr m_Calculator_SetProgressCallback;
	PLibPrimesCalculator_CalculatePtr m_Calculator_Calculate;
	PLibPrimesFactorizationCalculator_GetPrimeFactorsPtr m_FactorizationCalculator_GetPrimeFactors;
	PLibPrimesFactorizationCalculator_CheckPrimeFactorsPtr m_FactorizationCalculator_CheckPrimeFactors;
	PLibPrimesSieveCalculator_GetPrimesPtr m_SieveCalculator_GetPrimes;
	PLibPrimesCreateFactorizationCalculatorPtr m_CreateFactorizationCalculator;
	PLibPrimesCreateSieveCalculatorPtr m_CreateSieveCalculator;
	PLibPrimesReleaseInstancePtr m_ReleaseInstance;
	PLibPrimesGetLibraryVersionPtr m_GetLibraryVersion;
	PLibPrimesSetJournalPtr m_SetJournal;
} sLibPrimesDynamicWrapperTable;

#endif // __LIBPRIMES_DYNAMICHEADER

