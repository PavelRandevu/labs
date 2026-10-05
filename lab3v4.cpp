#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <string>

using namespace std;

int M = 0;
int N = 0;
vector<int> mdata;

int getindex(int i, int j) {
    if (i >= M) {
        i -= M; 
    }
    return i * N + j;
}
void setelement(int i, int j, int a) {
    mdata[getindex(i, j)] = a;
}
int getelement(int i, int j) {
    return mdata[getindex(i, j)];
}

int main() {
    while (true) {
        cout << "VVedite m(ot 1 do 5): ";
        if (cin >> M && M >= 1 && M <= 5) {
            break;
        }
        cout <<"Tak nelzya"<<endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    int R = 2 * M;
    while (true) {
        cout << "VVedite n(ot 1 do 10): ";
        if (cin >> N && N >= 1 && N <= 10) {
            break;
        }
        cout <<"Tak nelzya"<<endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    mdata.resize(M * N, 0);

    cout<<endl<<"Vvedite unikalnie elementy(pervie " << M <<" strok)"<<endl;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            int a; cin>>a;
            setelement(i, j, a);
        }
    }

    cout<<endl<<"Matrix (razmer " << R << "x" << N << "):"<<endl;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < N; ++j) {
            cout <<setw(6)<< getelement(i, j) << " ";
        }
        cout << endl;
    }

    int colvo = 0;
    for (int j = 0; j < N; ++j) {
        bool nolik = false;
        for (int i = 0; i < R; ++i) {
            if (getelement(i, j) == 0) {
                nolik = true;
                break;
            }
        }
        if (!nolik) {
            colvo++;
        }
    }
    int maxdlina = 0;
    int stroka = 0; 
    for (int i = 0; i < R; ++i) {
        int pokashtomaxdlina = 1;
        int dlina = 1;
        for (int j = 1; j < N; ++j) {
            if (getelement(i, j) > getelement(i, j - 1)) {
                dlina++;
            } 
            else {
                if (dlina > pokashtomaxdlina) {
                    pokashtomaxdlina = dlina;
                }
                dlina = 1;
            }
        }
        if (dlina > pokashtomaxdlina) {
            pokashtomaxdlina = dlina;
        }
        if (pokashtomaxdlina > maxdlina) {
            maxdlina = pokashtomaxdlina;
            stroka = i;
        }
    }
    cout<<endl<<"Colvo stolbov, ne soderzhaschih nolikov: " << colvo << endl;
    cout << "Nomer pervoy stroki s samoy dlinnoy vozrastayuschey posledovatelnostu: "<< (stroka + 1) << " (dlina: " << maxdlina <<")"<< endl;
    return 0;
}