# Objektinio programavimo (IND studijos)  2 užduotis

## Instaliavimas ir paleidimas Unix sistemose

Instaliavus su `git clone` pradinio kompiliavimo veiksmai:

```
mkdir build
./run.sh
./build/main
```

Vėliau leidžiant programą, pirmosios eilutės nebereikės.

> Jei nenorite paleisti, bet tik sukompiliuoti: paskutinės komandos nereikia

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

![Matavimo rezultatų screenshot'as](./screenshots/klases.png)

## v1.2

- Realizuoti "Rule of three" metodai".

## v1.5

- Sukurta `Zmogus` abstrakti klasė.

## v2.0

- Sugeneruota dokumentacija su doxygen.
- Parašyti unittestai.