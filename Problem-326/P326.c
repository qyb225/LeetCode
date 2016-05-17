bool isPowerOfThree(int num) {
    if (num < 1)
        return false;
    else if (1 == num)
        return true;
    else
        return num % 3 == 0 && isPowerOfThree(num / 3);
}