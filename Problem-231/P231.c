bool isPowerOfTwo(int n) {
    if (n < 1)
        return false;
    else if (n == 1)
        return true;
    else
        return 0 == n % 2 && isPowerOfTwo(n / 2);
}