// Why does this logic work?? Although it does not have better complexity
bool prime(int a) {
    if(a <= 1) return 0;
    if(a <= 3) return 1;
    if(a%2 == 0 or a%3 == 0) return 0;
    for(int i = 5; i*i <= a; i += 6) {
        if(a%i == 0 or a%(i+2) == 0)
            return 0;
    }
    return 1;
}