t1=4096
t2=65536
t3=17367040
max=10
param="params.txt"
program="hw1.x"
tag=$1
current="/home/ck1334/GPU/Project/BlackSholesSequential"
locate=$2
thr1=4
thr2=8

function test_seq_all {
	echo generating performance test result files: test_seq...$tag
	echo program: $program
	echo nthread: single
	echo mode:    0
	echo location:$locate
	make seq_4096_run > $locate/test_seq_$t1\_$tag
	make seq_65536_run > $locate/test_seq_$t2\_$tag
	make seq_17367040_run > $locate/test_seq_$t3\_$tag
}

function test_mpi4_all {
	echo generating performance test result files: test_mpi_4...$tag
	echo program: $program
	echo nthread: 4
	echo mode:    0
	echo location:$locate
	make mpi4_4096_run > $locate/test_mpi4_$t1\_$tag
	make mpi4_65536_run > $locate/test_mpi4_$t2\_$tag
	make mpi4_17367040_run > $locate/test_mpi4_$t3\_$tag
}

function test_mpi8_all {
	echo generating performance test result files: test_mpi_8...$tag
	echo program: $program
	echo nthread: 8 
	echo mode:    0
	echo location:$locate
	make mpi8_4096_run > $locate/test_mpi8_$t1\_$tag
	make mpi8_65536_run > $locate/test_mpi8_$t2\_$tag
	make mpi8_17367040_run > $locate/test_mpi8_$t3\_$tag
}

test_seq_all
test_mpi4_all
test_mpi8_all
