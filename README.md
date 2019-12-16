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

| CPU | OS | Architecture | Compiler | Misc. | lcg16 | mrg16_1 | mrg16_2 | mrg16_3 | mrg8 |
|:---:|:--:|:------------:|:--------:|:-----:|:-----:|:-------:|:-------:|:-------:|:----:|
| i5-7200U | Linux 5.3.15-138 | x86_64 (64 bits) | gcc 9.2.0 | - |
| i7-2600 |
| SDM845| Linux 4.9.165 | aarch64 | clang 8.0.1 | Termux on Pixel 3 |
