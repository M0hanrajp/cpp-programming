int sum_odd_digits(int n) {
  if(n < 10) {
    if(n % 2 != 0)
      return n;
    else
      return 0;
  }
  return sum_odd_digits(n % 10) + sum_odd_digits(n / 10);
}
