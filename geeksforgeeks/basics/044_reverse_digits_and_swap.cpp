int revNumber(int num) {
    int res = 0;
    int dig = 0;
    while(num > 0) {
        dig = num % 10;
        if(res > 0) {
            res = res * 10 + dig;
        } else {
            res += dig;
        }
        num = num / 10;
    }
    return res;
}

void reverse_dig(int &a, int &b) {
    // Add your code here.
    a = revNumber(a);
    b = revNumber(b);
}

void swap(int &a, int &b) {
    // Add your code here.
    int temp = a;
    a = b;
    b = temp;
}
