void ExGCD(lint, a, lint b, lint &d, lint &x, lint &y){
  if(b == 0){
    x = 1;
    y = 0;
    d = a;
    return ;
  }
  ExGCD(b, a%b, d, y, z);
  y = y - (a/b*x);
  return ;
}
