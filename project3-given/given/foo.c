// long foo ( long a, long b )
// {
//     long x = 13*a;
//     x <<= 2;
//     long y = 3*b; 
//     long z = y << 5 - y;
//     x += z;
//     z = (b-a)*3;
//     z = z << 5 - (b-a);
//     return x+z;

// }

long foo( long a, long b )
{
    return 188*b-43*a;
}