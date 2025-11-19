#include <iostream>
#include <cstring>   // memset
using namespace std;

int n;
int MT[105][105];
int duongDi[105];
bool daDi[105];
bool timThay = false;


void TimChuTrinh(int viTri)
{
    if (timThay) return;


    if (viTri == n)
    {

        if (MT[duongDi[n - 1]][duongDi[0]] == 1)
        {
            cout << 1 << "\n";
            for (int i = 0; i < n; i++)
                cout << duongDi[i] << " ";
            cout << duongDi[0] << "\n";
            timThay = true;
        }
        return;
    }

    int dinhTruoc = duongDi[viTri - 1];

    for (int dinh = 1; dinh <= n; dinh++)
    {
        if (!daDi[dinh] && MT[dinhTruoc][dinh] == 1)
        {
            duongDi[viTri] = dinh;
            daDi[dinh] = true;

            TimChuTrinh(viTri + 1);

            daDi[dinh] = false;
            if (timThay) return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> MT[i][j];

    memset(daDi, false, sizeof(daDi));
    duongDi[0] = 1;
    daDi[1] = true;

    TimChuTrinh(1);

    if (!timThay)
        cout << 0 << "\n";

    return 0;
}
