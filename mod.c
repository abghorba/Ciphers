// defined new modulo function
int mod(int x, int y)
{
    while (x<0)
        x+=y;
    return x % y;
}