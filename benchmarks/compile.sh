# !bin/sh

MPSOC_BENCH_DIR=/home/zelda/Documentos/git/mpsoc/tb/tests/benchmark
MPSOC_HOME=/home/zelda/Documentos/git/mpsoc

make RISCV_ARCH=rv32ia
make RISCV_ARCH=rv32ima

cp *.riscv *.dump $MPSOC_HOME

#cp *.riscv *.dump $MPSOC_BENCH_DIR
#cd $MPSOC_BENCH_DIR
#mv *ia.riscv* ia
#mv *ima.riscv* ima

