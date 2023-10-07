//Développed by Benstitou Sofiane
//Start the 7 october 2023
//maniaque : my own math lib for projetcs

//This file is where are made basics mathematical operations

float maniaque_identity(float x){
    return x;
}


float manique_sum(float x, float y){
    return x+y;
}

float maniaque_minus(float x, float y){
    return x-y;
}

float maniaque_multiplication(float x, float y){
    return x*y;
}

float maniaque_division(float x, float y){
    return x/y;
}


float maniaque_opposite(float x){
    return -x;
}

float maniaque_inverse(float x){
    return 1/x;
}

float maniaque_absolute(float x){
    if (x < 0){
        return -x;
    }
    return x;
}


float maniaque_powerInt(float x, int n){
    float x_powerer = x;
    int n_loop = maniaque_absolute(n);

    for (int i = 0; i < n_loop-1; i++){
        x *= x_powerer;
    }

    if (n < 0){
        return 1/x;
    } else if (n == 0){
        return 1;
    }

    return x;
}

float maniaque_powerFracInt(float x, int n, int m){ //calculate x^(n/m), source: https://www.youtube.com/watch?v=Z_BDJaveZNs
    float result = 4; // u_0 = 4
    if (n < 0 && m < 0){ // Simplify the frac sign
        n = maniaque_absolute(n);
        m = maniaque_absolute(m);
    }

    float y = maniaque_powerInt(result, m) - x; //result^m = x <=> result^m - x = 0
    float yp = m*maniaque_powerInt(result, m-1); //derivative of y

    for (int i = 0; i < 10; i++){//calculate x^(1/m) with Newton-Raphson method
        result = result - y/yp;
        y = maniaque_powerInt(result, m) - x;
        yp = m*maniaque_powerInt(result, m-1);
    }
    
    return maniaque_powerInt(result,n); //(x^(1/m))^n = x^((1/m)*n) = x^(n/m)
}


