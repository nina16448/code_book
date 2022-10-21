lint fast _pow(lint a,lint b){
  if(b == 0) return 1;
  int tmp = fast(a,b/2);
  if(b%2 == 1)
    return tmp*tmp*a;
  else
    return tmp*tmp;
}
