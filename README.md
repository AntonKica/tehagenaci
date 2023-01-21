# tehagenaci: ročníkový projekt

**Názov**: Testovanie hardvérových generátorov náhodných čísiel

## Študent

**Meno**: Anton Kica

**Email**: kica6@uniba.sk


## Školiaci

**Meno**: RNDr. Richard Ostertág, PhD.

**Email**: ostertag@dcs.fmph.uniba.sk

## Cieľe projektu

1. Vyvinúť alebo nájsť vhodné existujúce aplikácie pre testovanie kvality náhodných generátorov

2. Získať náhodné dáta zo zvolených HW generátorov za rôznych podmienok, otestovať kvalitu súčiastok a pozorovať prípadné zmeny parametrov


## Výsledky projektu [2023, január]

Podarilo sa nám vyzbierať a spracovať dáta generované hardvérovými súčiastkami.

### Hardvér
- [Ardunino UNO SMD rev. 3x](https://store.arduino.cc/products/arduino-uno-rev3)
- [SparkFun CryptoShield](https://www.sparkfun.com/products/retired/13183)
  - využili sme jeho súčiastku [ATECC108](http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-8873S-CryptoAuth-ATECC108-Datasheet-Summary.pdf)

![Hardvér](./pictures/hardware.jpg)

### Softvér
- [Dieharder](https://webhome.phy.duke.edu/~rgb/General/dieharder.php)
  - testovanie spoľahlivosti náhodných generátorov a postupností
- [cryptoauth-arduino](https://github.com/cryptotronix/cryptoauth-arduino)
  - knižnica na komunikáciu s ATECC108

### Testované prostredia
Hardvérovú súčiastku sme testovali v rôznych podmienkach.

### Izbová teplota
|teplota|veľkosť vzorky v MB|
|-|-|
|21° (izbová)|231|

#### Dieharder výsledky 

|        test_name   |ntup| tsamples |psamples|  p-value |Assessment|
|-|-|-|-|-|-|
|   diehard_birthdays|   0|       100|     100|0.50319350|  PASSED  |
|      diehard_operm5|   0|   1000000|     100|0.43174119|  PASSED  |
|  diehard_rank_32x32|   0|     40000|     100|0.44019941|  PASSED  |
|    diehard_rank_6x8|   0|    100000|     100|0.54024721|  PASSED  |
|   diehard_bitstream|   0|   2097152|     100|0.34949261|  PASSED  |
|        diehard_opso|   0|   2097152|     100|0.06777356|  PASSED  |
|        diehard_oqso|   0|   2097152|     100|0.72449996|  PASSED  |
|         diehard_dna|   0|   2097152|     100|0.39048633|  PASSED  |
|diehard_count_1s_str|   0|    256000|     100|0.23833845|  PASSED  |
|diehard_count_1s_byt|   0|    256000|     100|0.41704546|  PASSED  |
| diehard_parking_lot|   0|     12000|     100|0.90999882|  PASSED  |
|    diehard_2dsphere|   2|      8000|     100|0.12220458|  PASSED  |
|    diehard_3dsphere|   3|      4000|     100|0.27432417|  PASSED  |
|     diehard_squeeze|   0|    100000|     100|0.46640643|  PASSED  |
|        diehard_sums|   0|       100|     100|0.00123076|   WEAK   |
|        diehard_runs|   0|    100000|     100|0.24583178|  PASSED  |
|        diehard_runs|   0|    100000|     100|0.37085418|  PASSED  |
|       diehard_craps|   0|    200000|     100|0.21917504|  PASSED  |
|       diehard_craps|   0|    200000|     100|0.49780118|  PASSED  |
| marsaglia_tsang_gcd|   0|  10000000|     100|0.00001491|   WEAK   |
| marsaglia_tsang_gcd|   0|  10000000|     100|0.00472095|   WEAK   |
|         sts_monobit|   1|    100000|     100|0.90949020|  PASSED  |
|            sts_runs|   2|    100000|     100|0.33235740|  PASSED  |
|          sts_serial|   1|    100000|     100|0.10819493|  PASSED  |
|          sts_serial|   2|    100000|     100|0.97737185|  PASSED  |
|          sts_serial|   3|    100000|     100|0.45888116|  PASSED  |
|          sts_serial|   3|    100000|     100|0.77785332|  PASSED  |
|          sts_serial|   4|    100000|     100|0.32035633|  PASSED  |
|          sts_serial|   4|    100000|     100|0.79209362|  PASSED  |
|          sts_serial|   5|    100000|     100|0.87168072|  PASSED  |
|          sts_serial|   5|    100000|     100|0.98188624|  PASSED  |
|          sts_serial|   6|    100000|     100|0.45268710|  PASSED  |
|          sts_serial|   6|    100000|     100|0.93630415|  PASSED  |
|          sts_serial|   7|    100000|     100|0.81884397|  PASSED  |
|          sts_serial|   7|    100000|     100|0.13293360|  PASSED  |
|          sts_serial|   8|    100000|     100|0.36663128|  PASSED  |
|          sts_serial|   8|    100000|     100|0.87070459|  PASSED  |
|          sts_serial|   9|    100000|     100|0.42213009|  PASSED  |
|          sts_serial|   9|    100000|     100|0.37646597|  PASSED  |
|          sts_serial|  10|    100000|     100|0.25142432|  PASSED  |
|          sts_serial|  10|    100000|     100|0.63646224|  PASSED  |
|          sts_serial|  11|    100000|     100|0.63755392|  PASSED  |
|          sts_serial|  11|    100000|     100|0.76117433|  PASSED  |
|          sts_serial|  12|    100000|     100|0.72055265|  PASSED  |
|          sts_serial|  12|    100000|     100|0.93150182|  PASSED  |
|          sts_serial|  13|    100000|     100|0.97593963|  PASSED  |
|          sts_serial|  13|    100000|     100|0.98227105|  PASSED  |
|          sts_serial|  14|    100000|     100|0.37510183|  PASSED  |
|          sts_serial|  14|    100000|     100|0.60857057|  PASSED  |
|          sts_serial|  15|    100000|     100|0.88061603|  PASSED  |
|          sts_serial|  15|    100000|     100|0.67567252|  PASSED  |
|          sts_serial|  16|    100000|     100|0.92826026|  PASSED  |
|          sts_serial|  16|    100000|     100|0.58187349|  PASSED  |
|         rgb_bitdist|   1|    100000|     100|0.70921138|  PASSED  |
|         rgb_bitdist|   2|    100000|     100|0.12472575|  PASSED  |
|         rgb_bitdist|   3|    100000|     100|0.96329872|  PASSED  |
|         rgb_bitdist|   4|    100000|     100|0.31258394|  PASSED  |
|         rgb_bitdist|   5|    100000|     100|0.32163706|  PASSED  |
|         rgb_bitdist|   6|    100000|     100|0.88686463|  PASSED  |
|         rgb_bitdist|   7|    100000|     100|0.20748346|  PASSED  |
|         rgb_bitdist|   8|    100000|     100|0.60506925|  PASSED  |
|         rgb_bitdist|   9|    100000|     100|0.78415059|  PASSED  |
|         rgb_bitdist|  10|    100000|     100|0.00359854|   WEAK   |
|         rgb_bitdist|  11|    100000|     100|0.36355332|  PASSED  |
|         rgb_bitdist|  12|    100000|     100|0.52347583|  PASSED  |
|rgb_minimum_distance|   2|     10000|    1000|0.82218315|  PASSED  |
|rgb_minimum_distance|   3|     10000|    1000|0.68272085|  PASSED  |
|rgb_minimum_distance|   4|     10000|    1000|0.61142596|  PASSED  |
|rgb_minimum_distance|   5|     10000|    1000|0.43114853|  PASSED  |
|    rgb_permutations|   2|    100000|     100|0.83885179|  PASSED  |
|    rgb_permutations|   3|    100000|     100|0.72765199|  PASSED  |
|    rgb_permutations|   4|    100000|     100|0.46156897|  PASSED  |
|    rgb_permutations|   5|    100000|     100|0.95822861|  PASSED  |
|      rgb_lagged_sum|   0|   1000000|     100|0.80672605|  PASSED  |
|      rgb_lagged_sum|   1|   1000000|     100|0.05029723|  PASSED  |
|      rgb_lagged_sum|   2|   1000000|     100|0.22317234|  PASSED  |
|      rgb_lagged_sum|   3|   1000000|     100|0.17006137|  PASSED  |
|      rgb_lagged_sum|   4|   1000000|     100|0.92182285|  PASSED  |
|      rgb_lagged_sum|   5|   1000000|     100|0.00007407|   WEAK   |
|      rgb_lagged_sum|   6|   1000000|     100|0.62294766|  PASSED  |
|      rgb_lagged_sum|   7|   1000000|     100|0.00001378|   WEAK   |
|      rgb_lagged_sum|   8|   1000000|     100|0.00000000|  FAILED  |
|      rgb_lagged_sum|   9|   1000000|     100|0.19284954|  PASSED  |
|      rgb_lagged_sum|  10|   1000000|     100|0.18606259|  PASSED  |
|      rgb_lagged_sum|  11|   1000000|     100|0.00000514|   WEAK   |
|      rgb_lagged_sum|  12|   1000000|     100|0.67832176|  PASSED  |
|      rgb_lagged_sum|  13|   1000000|     100|0.83403008|  PASSED  |
|      rgb_lagged_sum|  14|   1000000|     100|0.15303318|  PASSED  |
|      rgb_lagged_sum|  15|   1000000|     100|0.00000000|  FAILED  |
|      rgb_lagged_sum|  16|   1000000|     100|0.88637170|  PASSED  |
|      rgb_lagged_sum|  17|   1000000|     100|0.00000000|  FAILED  |
|      rgb_lagged_sum|  18|   1000000|     100|0.50400854|  PASSED  |
|      rgb_lagged_sum|  19|   1000000|     100|0.83808683|  PASSED  |
|      rgb_lagged_sum|  20|   1000000|     100|0.06792032|  PASSED  |
|      rgb_lagged_sum|  21|   1000000|     100|0.44949614|  PASSED  |
|      rgb_lagged_sum|  22|   1000000|     100|0.30267181|  PASSED  |
|      rgb_lagged_sum|  23|   1000000|     100|0.00008294|   WEAK   |
|      rgb_lagged_sum|  24|   1000000|     100|0.59124875|  PASSED  |
|      rgb_lagged_sum|  25|   1000000|     100|0.21867462|  PASSED  |
|      rgb_lagged_sum|  26|   1000000|     100|0.00000003|  FAILED  |
|      rgb_lagged_sum|  27|   1000000|     100|0.23665722|  PASSED  |
|      rgb_lagged_sum|  28|   1000000|     100|0.66720074|  PASSED  |
|      rgb_lagged_sum|  29|   1000000|     100|0.00001284|   WEAK   |
|      rgb_lagged_sum|  30|   1000000|     100|0.91595622|  PASSED  |
|      rgb_lagged_sum|  31|   1000000|     100|0.00000000|  FAILED  |
|      rgb_lagged_sum|  32|   1000000|     100|0.02142402|  PASSED  |
|     rgb_kstest_test|   0|     10000|    1000|0.36543777|  PASSED  |
|     dab_bytedistrib|   0|  51200000|       1|0.00000000|  FAILED  |
|             dab_dct| 256|     50000|       1|0.32427017|  PASSED  |
|        dab_filltree|  32|  15000000|       1|0.18778119|  PASSED  |
|        dab_filltree|  32|  15000000|       1|0.29370218|  PASSED  |
|       dab_filltree2|   0|   5000000|       1|0.27211981|  PASSED  |
|       dab_filltree2|   1|   5000000|       1|0.22232123|  PASSED  |
|        dab_monobit2|  12|  65000000|       1|0.55185262|  PASSED  |

#### Veles
|dvojice bitov|trojice bitov|
|-|-|
|![Plane](./pictures/random-sequence-plane.png)|![Cube](./pictures/random-sequence-cube.png)|

### Znížená teplota
|teplota|veľkosť vzorky v MB|
|-|-|
|0°|257|

#### Dieharder výsledky 
|        test_name   |ntup| tsamples |psamples|  p-value |Assessment|
|-|-|-|-|-|-|
|   diehard_birthdays|   0|       100|     100|0.23579804|  PASSED  |
|      diehard_operm5|   0|   1000000|     100|0.72447632|  PASSED  |
|  diehard_rank_32x32|   0|     40000|     100|0.63749501|  PASSED  |
|    diehard_rank_6x8|   0|    100000|     100|0.49559319|  PASSED  |
|   diehard_bitstream|   0|   2097152|     100|0.69916295|  PASSED  |
|        diehard_opso|   0|   2097152|     100|0.00118623|   WEAK   |
|        diehard_oqso|   0|   2097152|     100|0.93447054|  PASSED  |
|         diehard_dna|   0|   2097152|     100|0.92712657|  PASSED  |
|diehard_count_1s_str|   0|    256000|     100|0.41756806|  PASSED  |
|diehard_count_1s_byt|   0|    256000|     100|0.76896458|  PASSED  |
| diehard_parking_lot|   0|     12000|     100|0.66912419|  PASSED  |
|    diehard_2dsphere|   2|      8000|     100|0.54327847|  PASSED  |
|    diehard_3dsphere|   3|      4000|     100|0.99232513|  PASSED  |
|     diehard_squeeze|   0|    100000|     100|0.11447009|  PASSED  |
|        diehard_sums|   0|       100|     100|0.66218623|  PASSED  |
|        diehard_runs|   0|    100000|     100|0.53958809|  PASSED  |
|        diehard_runs|   0|    100000|     100|0.98044129|  PASSED  |
|       diehard_craps|   0|    200000|     100|0.52482089|  PASSED  |
|       diehard_craps|   0|    200000|     100|0.23596044|  PASSED  |
| marsaglia_tsang_gcd|   0|  10000000|     100|0.00083062|   WEAK   |
| marsaglia_tsang_gcd|   0|  10000000|     100|0.00004898|   WEAK   |
|         sts_monobit|   1|    100000|     100|0.61300866|  PASSED  |
|            sts_runs|   2|    100000|     100|0.25744567|  PASSED  |
|          sts_serial|   1|    100000|     100|0.79556208|  PASSED  |
|          sts_serial|   2|    100000|     100|0.10043132|  PASSED  |
|          sts_serial|   3|    100000|     100|0.08027417|  PASSED  |
|          sts_serial|   3|    100000|     100|0.52394096|  PASSED  |
|          sts_serial|   4|    100000|     100|0.23742126|  PASSED  |
|          sts_serial|   4|    100000|     100|0.47231625|  PASSED  |
|          sts_serial|   5|    100000|     100|0.11460566|  PASSED  |
|          sts_serial|   5|    100000|     100|0.95764821|  PASSED  |
|          sts_serial|   6|    100000|     100|0.67359373|  PASSED  |
|          sts_serial|   6|    100000|     100|0.89783092|  PASSED  |
|          sts_serial|   7|    100000|     100|0.96859166|  PASSED  |
|          sts_serial|   7|    100000|     100|0.37487508|  PASSED  |
|          sts_serial|   8|    100000|     100|0.92267267|  PASSED  |
|          sts_serial|   8|    100000|     100|0.88158842|  PASSED  |
|          sts_serial|   9|    100000|     100|0.66102014|  PASSED  |
|          sts_serial|   9|    100000|     100|0.27198463|  PASSED  |
|          sts_serial|  10|    100000|     100|0.14320257|  PASSED  |
|          sts_serial|  10|    100000|     100|0.46252560|  PASSED  |
|          sts_serial|  11|    100000|     100|0.50676899|  PASSED  |
|          sts_serial|  11|    100000|     100|0.99258222|  PASSED  |
|          sts_serial|  12|    100000|     100|0.88513473|  PASSED  |
|          sts_serial|  12|    100000|     100|0.68219334|  PASSED  |
|          sts_serial|  13|    100000|     100|0.79215678|  PASSED  |
|          sts_serial|  13|    100000|     100|0.31384592|  PASSED  |
|          sts_serial|  14|    100000|     100|0.06038477|  PASSED  |
|          sts_serial|  14|    100000|     100|0.79321311|  PASSED  |
|          sts_serial|  15|    100000|     100|0.50158160|  PASSED  |
|          sts_serial|  15|    100000|     100|0.47596553|  PASSED  |
|          sts_serial|  16|    100000|     100|0.03221822|  PASSED  |
|          sts_serial|  16|    100000|     100|0.88451065|  PASSED  |
|         rgb_bitdist|   1|    100000|     100|0.16150813|  PASSED  |
|         rgb_bitdist|   2|    100000|     100|0.53871954|  PASSED  |
|         rgb_bitdist|   3|    100000|     100|0.64615246|  PASSED  |
|         rgb_bitdist|   4|    100000|     100|0.60509157|  PASSED  |
|         rgb_bitdist|   5|    100000|     100|0.67125581|  PASSED  |
|         rgb_bitdist|   6|    100000|     100|0.02956216|  PASSED  |
|         rgb_bitdist|   7|    100000|     100|0.99384808|  PASSED  |
|         rgb_bitdist|   8|    100000|     100|0.77333974|  PASSED  |
|         rgb_bitdist|   9|    100000|     100|0.94298504|  PASSED  |
|         rgb_bitdist|  10|    100000|     100|0.88022445|  PASSED  |
|         rgb_bitdist|  11|    100000|     100|0.52918184|  PASSED  |
|         rgb_bitdist|  12|    100000|     100|0.28592764|  PASSED  |
|rgb_minimum_distance|   2|     10000|    1000|0.09561788|  PASSED  |
|rgb_minimum_distance|   3|     10000|    1000|0.47948754|  PASSED  |
|rgb_minimum_distance|   4|     10000|    1000|0.90537835|  PASSED  |
|rgb_minimum_distance|   5|     10000|    1000|0.01662268|  PASSED  |
|    rgb_permutations|   2|    100000|     100|0.60263402|  PASSED  |
|    rgb_permutations|   3|    100000|     100|0.96823736|  PASSED  |
|    rgb_permutations|   4|    100000|     100|0.17281878|  PASSED  |
|    rgb_permutations|   5|    100000|     100|0.97919247|  PASSED  |
|      rgb_lagged_sum|   0|   1000000|     100|0.82387015|  PASSED  |
|      rgb_lagged_sum|   1|   1000000|     100|0.81221651|  PASSED  |
|      rgb_lagged_sum|   2|   1000000|     100|0.73673402|  PASSED  |
|      rgb_lagged_sum|   3|   1000000|     100|0.53634367|  PASSED  |
|      rgb_lagged_sum|   4|   1000000|     100|0.87332408|  PASSED  |
|      rgb_lagged_sum|   5|   1000000|     100|0.66066563|  PASSED  |
|      rgb_lagged_sum|   6|   1000000|     100|0.95756459|  PASSED  |
|      rgb_lagged_sum|   7|   1000000|     100|0.91596536|  PASSED  |
|      rgb_lagged_sum|   8|   1000000|     100|0.50019934|  PASSED  |
|      rgb_lagged_sum|   9|   1000000|     100|0.88419294|  PASSED  |
|      rgb_lagged_sum|  10|   1000000|     100|0.60574551|  PASSED  |
|      rgb_lagged_sum|  11|   1000000|     100|0.88920746|  PASSED  |
|      rgb_lagged_sum|  12|   1000000|     100|0.91605929|  PASSED  |
|      rgb_lagged_sum|  13|   1000000|     100|0.41681998|  PASSED  |
|      rgb_lagged_sum|  14|   1000000|     100|0.85525770|  PASSED  |
|      rgb_lagged_sum|  15|   1000000|     100|0.52833884|  PASSED  |
|      rgb_lagged_sum|  16|   1000000|     100|0.66579042|  PASSED  |
|      rgb_lagged_sum|  17|   1000000|     100|0.30960989|  PASSED  |
|      rgb_lagged_sum|  18|   1000000|     100|0.96360509|  PASSED  |
|      rgb_lagged_sum|  19|   1000000|     100|0.57059331|  PASSED  |
|      rgb_lagged_sum|  20|   1000000|     100|0.44297245|  PASSED  |
|      rgb_lagged_sum|  21|   1000000|     100|0.84486862|  PASSED  |
|      rgb_lagged_sum|  22|   1000000|     100|0.78705465|  PASSED  |
|      rgb_lagged_sum|  23|   1000000|     100|0.72782562|  PASSED  |
|      rgb_lagged_sum|  24|   1000000|     100|0.75694544|  PASSED  |
|      rgb_lagged_sum|  25|   1000000|     100|0.86399488|  PASSED  |
|      rgb_lagged_sum|  26|   1000000|     100|0.81256865|  PASSED  |
|      rgb_lagged_sum|  27|   1000000|     100|0.04446170|  PASSED  |
|      rgb_lagged_sum|  28|   1000000|     100|0.35100849|  PASSED  |
|      rgb_lagged_sum|  29|   1000000|     100|0.97064081|  PASSED  |
|      rgb_lagged_sum|  30|   1000000|     100|0.75969472|  PASSED  |
|      rgb_lagged_sum|  31|   1000000|     100|0.27170661|  PASSED  |
|      rgb_lagged_sum|  32|   1000000|     100|0.70478351|  PASSED  |
|     rgb_kstest_test|   0|     10000|    1000|0.58105892|  PASSED  |
|     dab_bytedistrib|   0|  51200000|       1|0.18532968|  PASSED  |
|             dab_dct| 256|     50000|       1|0.27272423|  PASSED  |
|        dab_filltree|  32|  15000000|       1|0.00669355|  PASSED  |
|        dab_filltree|  32|  15000000|       1|0.40069809|  PASSED  |
|       dab_filltree2|   0|   5000000|       1|0.07465145|  PASSED  |
|       dab_filltree2|   1|   5000000|       1|0.94692516|  PASSED  |
|        dab_monobit2|  12|  65000000|       1|0.25514870|  PASSED  |

#### Veles
|dvojice bitov|trojice bitov|
|-|-|
|![Plane](./pictures/random-sequence-cold-plane.png)|![Cube](./pictures/random-sequence-cold-cube.png)|
