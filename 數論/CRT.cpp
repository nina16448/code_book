int A[n],B[n],m;
void CRT(){
  int ans,x,y,d;
  m=1;
  for(int i=0;i<n;i++)
    m+=B[i];
  ans=0;
  for(int i=0;i<n;i++){
   Exgcd(m/B[i] ,d,x,y);
   while(x<0) x+=B[i];
    ans+=A[i]*x*(m/B[i]);
    ans%=m;
  }
  return ans;
}
