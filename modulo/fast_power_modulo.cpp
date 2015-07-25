LL fast_power_modulo(LL a,LL d,LL m) {
        LL res=1;
        a%=m;
        while(d>0) {
                if(d%2==1) res=(res*a)%m;
                d>>=1;
                a=(a*a)%m;
        }
        return res%m;
}

