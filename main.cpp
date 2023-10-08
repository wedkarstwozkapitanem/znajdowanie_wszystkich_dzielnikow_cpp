#include <iostream>
#include <vector>
#include <algorithm>



void rozbij_czynniki(int N);

int main() {
    int T = 0;
    std::cin >> T;


    for (int i = 0; i < T; i++) {
        int N = 0;
        std::cin >> N;
        rozbij_czynniki(N);
    }

    return 0;
}






void rozbij_czynniki(int N) {
    int p = N;
    std::vector<int> dzielniki;

    for (int i = 2; i <= (N + 1); i++) {
        if (N % i == 0) {
            if (i != 0)
                dzielniki.push_back(i);
        }
    }

    std::vector<std::vector<int>> mozliwe_kombinacje;

    mozliwe_kombinacje.push_back({ 1,N });

    for (int i : dzielniki) {
        int s = 1;
        /* if (i * i == p) {
             mozliwe_kombinacje.push_back({i,i});
         }*/

        for (int j : dzielniki) {



            /* if (i * j == p) {
                 mozliwe_kombinacje.push_back({ i,j });
             }*/

            int potegi = j, ile_raz = 1;
            while (potegi <= p) {
                if (i * potegi == p) {
                    mozliwe_kombinacje.push_back({ i });
                    for (int i = 1; i <= ile_raz; i++) {
                        mozliwe_kombinacje[mozliwe_kombinacje.size() - 1].push_back(j);
                    }
                }
                potegi *= j;
                ile_raz++;
            }

        }
        // std::cout << i << "," << s << std::endl;

    }



    for (int i = 0; i < dzielniki.size(); i++) {
        int pix = 0, indeks = i;
        std::vector<int> jakie_liczby;
        while (pix < p) {
            if ((indeks) >= dzielniki.size()) break;
            pix *= dzielniki[indeks];
            jakie_liczby.push_back(dzielniki[indeks]);
            indeks++;
        }

        if (pix == p) mozliwe_kombinacje.push_back(jakie_liczby);
    }



    std::sort(mozliwe_kombinacje.begin(), mozliwe_kombinacje.end());

    for (auto i : mozliwe_kombinacje) {
        for (auto j : i) {
            std::cout << j << ",";
        }
        std::cout << std::endl;
    }

}
