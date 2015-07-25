void prime_number_sieve {
        int sieve[N];
        REP(i,2,N) sieve[i]=1;
        REP(i,2,M)
                if(sieve[i]==1) 
                        for(int j=i*i;j<N;j+=i) 
                                sieve[j]=0;
}

