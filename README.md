# Objektinio programavimo (IND studijos)  2 užduotis

## Instaliavimas ir paleidimas Unix sistemose

Instaliuoti galima su `git clone` komanda: .
Paleisdimui naudojamas `cmake`. 
Kompiliavimui užtenka paleisti `run.sh`.
Sukompiliavimus executable `main` bus direktorijoje `build` todėl Unix sistemose reikia paleisti `./build/main`.

## v1.1

- Realizuota su klasėmis.
- Padaryti matavimai su įvairiais compiler flagais.

### Matavimo rezultatai

Failo dydžiai:

| Optimizavimo lygis | Failo dydis (baitais) |
| ------------------ | --------------------- |
| O1 | 200904 |
| O2 | 203160 |
| O3 | 210784 |

![Matavimo rezultatai](./screenshots/klases.png)