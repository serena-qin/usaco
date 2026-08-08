#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int start_bronze, start_silver, start_gold, start_plat;
    int end_bronze, end_silver, end_gold, end_plat;
    int br_si = 0, si_go = 0, go_pl = 0;
    freopen("promote.in", "r", stdin);
    scanf("%d %d", &start_bronze, &end_bronze);
    scanf("%d %d", &start_silver, &end_silver);
    scanf("%d %d", &start_gold, &end_gold);
    scanf("%d %d", &start_plat, &end_plat);
    go_pl = end_plat - start_plat; //cuz platinum is upper limit
    si_go = end_gold - start_gold + go_pl; //participants may have went silver -> gold -> plat
    br_si = end_silver - start_silver + si_go;
    freopen("promote.out", "w", stdout);
    printf("%d\n", br_si);
    printf("%d\n", si_go);
    printf("%d\n", go_pl);
}