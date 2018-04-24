#include "prime-generator.h"

void generator::primeGenerator(int number, int minLenght, mpz_class* resultArray)
{
    srand(clock());
    running = true;
    for (int i =0; i<number; ++i){
        mpz_class nbr = 10;
        for (int j=0; j<minLenght; ++j){
            nbr *= 10;
            nbr += rand() % MOD_RAND % nbr;
        }
        while (mpz_probab_prime_p(nbr.get_mpz_t(), 15) == 0){
            if (running == false) return;
            nbr = mpz_class(rand() % MOD_RAND) * 987456123888884573 + nbr;
            if (nbr % 2 == 0) nbr +=1;
            emit numberTested();
        }
        resultArray[i] = nbr;
    }
    emit finished();
}
