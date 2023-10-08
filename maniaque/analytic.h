//WC : with (precision) choice

float maniaque_expWC(float x, int n){ //source : https://fr.wikipedia.org/wiki/Factorielle
    float result = 0;
    for (int i = 0; i < n; i++){
        result += maniaque_powerInt(x,i)/maniaque_factorial(i);
    }
    return result;
}

float maniaque_exp(float x){
    return maniaque_expWC(x,30);
}

float maniaque_lnWC(float x, int n){ //using Halley-Newton method : https://en.wikipedia.org/wiki/Natural_logarithm#High_precision
    if (x <= 0){
        printf("Maniaque Ln : cannot go smaller than 0 excluded.\n");
        return 0;
    }
    
    float result = 0; // u_0

    for (int i = 0; i < n; i++){
        result += 2*((x - maniaque_exp(result))/(x + maniaque_exp(result)));
    }

    return result;
}

float maniaque_ln(float x){
    return maniaque_lnWC(x, 100);
}

float maniaque_powerPositiveNotFrac(float x, float y){ //Do not use fraction ! -> for it use maniaque_powerFracInt
    if (x < 0){
        printf("Maniaque powerNatural : can't decide the value :(\n");
        return 0;
    }

    
    if (y < 0){
        return 1/maniaque_powerPositiveNotFrac(x,-y);
    }

    return maniaque_exp(y*maniaque_ln(x)); //exp(yln(x)) = exp(ln(x^y)) = x^y
}
