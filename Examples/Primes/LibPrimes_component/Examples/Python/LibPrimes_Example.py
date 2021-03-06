'''++

Copyright (C) 2018 Automatic Component Toolkit Developers

All rights reserved.

Abstract: This is an autogenerated Python application that demonstrates the
 usage of the Python bindings of Prime Numbers Interface
Interface version: 1.0.0

'''

def progressCallback(progress, shouldAbort):
	print("Progress = {:d}%".format(round(progress*100)))
	if (shouldAbort is not None):
		shouldAbort[0] = progress > 0.5;


import os
import sys
sys.path.append(os.path.join(os.path.realpath(__file__),"..", "..", "..", "Bindings", "Python"))
import LibPrimes


def main():
	libpath = '' # TODO add the location of the shared library binary here
	wrapper = LibPrimes.LibPrimesWrapper(os.path.join(libpath, "libprimes"))
	wrapper.SetJournal('journal_python.xml')
	
	major, minor, micro = wrapper.GetLibraryVersion()
	print("LibPrimes version: {:d}.{:d}.{:d}".format(major, minor, micro))
	sieve = wrapper.CreateSieveCalculator()
	sieve.SetValue(105)
	sieve.Calculate()
	primes = sieve.GetPrimes()
	print("Primes <= {:d} = [".format(sieve.GetValue()), end="")
	commaString = ", "
	for i in range(0, len(primes)):
		if i == len(primes) - 1:
			commaString = ""
		print("{:d}".format(primes[i]), end=commaString)
	print("]")
        
	factorization = wrapper.CreateFactorizationCalculator()
	factorization.SetValue(735)
	cTypesCallback = LibPrimes.LibPrimesProgressCallback(progressCallback)
	factorization.SetProgressCallback(cTypesCallback)
	factorization.Calculate()
	primeFactors = factorization.GetPrimeFactors()
	productString = "*"
	print("{:d} = ".format(factorization.GetValue()), end="")
	for i in range(0, len(primeFactors)):
		pF = primeFactors[i]
		if i == len(primeFactors) - 1:
			productString = "\n"
		print(" {:d}^{:d} ".format(pF.Prime, pF.Multiplicity), end=productString)

	

if __name__ == "__main__":
	try:
		main()
	except LibPrimes.ELibPrimesException as e:
		print(e)
