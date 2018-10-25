//https://www.infoarena.ro/problema/superp
#include <bits/stdc++.h>

using namespace std;

ifstream f("superp.in");
ofstream g("superp.out");

long long  q[100001],n,nr,p,u,sol[100001],x,i,fr[13],vf[13],j;
bool ok;
int cif[]={1,3,7,9};


bool prim(long long  x)
{
    if ( x == 2 )
        return true;

    if ( x < 2 || x%2 == 0 )
        return false;

    for (long long d=3;d*d<=x;d++){

        if (x%d==0){

            return false;
        }
    }
    return true;
}

int main(){

    f>>n;

    p = 1;
    u = 0;

    q[++u] = 2;
    q[++u] = 3;
    q[++u] = 5;
    q[++u] = 7;

    while ( p <= u ){

        sol[++nr] = q[p];
        x = q[p];
        p++;
        for ( i = 1;i <= 4;i++ ){

            if ( prim(x*10+cif[i]) == true ){

                q[++u] = x * 10 + cif[i];
            }
        }
    }
    for ( i = 1;i <= n;i++ ){

        f>>x;
        memset(fr,0,sizeof(fr));
        while ( x ){

            fr[x%10]++;
            x/=10;
        }
        for ( j = nr;j >= 1;j-- ){

            ok = true;
            memset(vf,0,sizeof(vf));
            x = sol[j];
            while ( x ){

                vf[x%10]++;
                x/=10;
            }
            for ( int t = 0;t < 10;t++ ){

                if ( vf[t] > fr[t] ){

                    ok = false;
                    break;
                }
            }
            if ( ok == true ){

                g<<sol[j]<<'\n';
                break;
            }
        }
    }
    return 0;
}
