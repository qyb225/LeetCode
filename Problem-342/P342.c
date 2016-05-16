bool isPowerOfFour(int num);

bool isPowerOfFour(int num) {
    if (num < 1)
        return false;
    else if (1 == num)
        return true;
    else
        return num % 4 == 0 && isPowerOfFour(num / 4);
}
