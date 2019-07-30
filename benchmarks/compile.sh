# !bin/sh

MPSOC_HOME=

make RISCV_ARCH=rv32ia
make RISCV_ARCH=rv32ima

cp *.riscv *.dump $MPSOC_HOME


