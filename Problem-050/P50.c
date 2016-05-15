double myPow(double x, int n);

double myPow(double x, int n) {
    double ans = 1;
    int judge;
    if (n > 0) {
        judge = 1;
    }
    else if (n < 0) {
        judge = -1;
        n = -1 * n;
    }
    while (n > 0) {
        ans = x * ans;
        --n;
    }
    if (judge < 0) {
        ans = 1.0 / ans;
    }
    return ans;
}