GEN = $(filter-out harness.c, $(wildcard *.c))
RES = $(GEN:%.c=%.res)
EXE = $(GEN:%.c=%)
REPS = 1000000000
NUM_REPS = 10

default: $(RES) clean

%.res:
	./compile.sh $(@:%.res=%) $(REPS) $(NUM_REPS) > $@

clean:
	./average.py
	@rm $(RES) $(EXE)
