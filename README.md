Simple MRG speed tests using Vigna's harness. This is here mostly to share
between computers and test on different architectures. Make will run all
generators. Check parameters before runing, numbers can be a bit high.

Example usages:
```
make
make mrg59k3a.res
./compile.sh mrg59k3a 1000000 5
```

Results for different processors and architectures:

| CPU | OS | Architecture | Compiler | Misc. | lcg16 | mrg16_1 | mrg16_2 | mrg16_3 | mrg8 | mrg59k3a | mrg59p2a | mrg59p2b | mrg59p3c | mrg31k3p_original | mrg31k3p_fast | mrg32k3a_double | mrg32k3a_vigna |
|:---:|:--:|:------------:|:--------:|:-----:|:-----:|:-------:|:-------:|:-------:|:----:|:--------:|:--------:|:--------:|:--------:|:-----------------:|:-------------:|:---------------:|:--------------:|
| i5-7200U | Linux 5.3.15 | x86_64 (64 bits) | gcc 9.2.0 | - | 1.650 | 12.827 | 6.980 | 9.900 | 6.123 | 10.495 | 11.694 | 14.286 | 16.553 | 12.956 | 7.057 | 28.692 | 5.419 |
| i7-2600 | Linux 4.9.0 | x86_64 (64 bits) | 6.3.0 | - | 1.469 | 14.476 | 7.462 | 9.122 | 6.263 | 12.235 | 12.048 | 14.803 | 17.459 | 11.797 | 7.560 | 25.574 | 6.067 |
| SDM845| Linux 4.9.165 | aarch64 (64 bits) | clang 8.0.1 | Termux on Pixel 3 | 1.513 | 13.459 | 7.150 | 12.983 | 8.872 | 25.210 | 13.720 | 21.636 | 26.385 | 8.873 | 9.380 | 19.813 | 9.994 |
