#include "warehouse.h"
#include "warehouse.c"
#include "map.c"

int main() {
    Map tes;
    CreateEmpty(&tes);
    manageWareHouse(&tes);
    return 0;
}